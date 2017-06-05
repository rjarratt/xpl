/* xpl.c: MU5 XPL cross-compiler routines

Copyright (c) 2017, Robert Jarratt

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
ROBERT JARRATT BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of Robert Jarratt shall not be
used in advertising or otherwise to promote the sale, use or other dealings
in this Software without prior written authorization from Robert Jarratt.
*/

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include "xpl.h"

FILE *binary;
int error_in_pass;
unsigned int segment;
symbol_t sn_ir_symbol = { IR, NOT_REL, "SN", 2 }; /* Not sure of correct syntax as there are two IR entries for SN, just picked one for now */
symbol_t a_ir_symbol = { IR, NOT_REL, "A", 48 };
symbol_t b_ir_symbol = { IR, NOT_REL, "B", 32 };
symbol_t bn_ir_symbol = { IR, NOT_REL, "BN", 4 };
symbol_t d_ir_symbol = { IR, NOT_REL, "D", 16 };
symbol_t d_symbol = { DESCRIPTOR };

extern char *yytext;
extern int yylineno;

static int pass;
static unsigned int instructionNum;

static symbol_t symbol_table[MAX_SYMBOLS];
static int numSymbols = 0;

static label_entry_t label_table[MAX_LABELS];
static int numLabels;

static segment_t segment_table[MAX_SEGMENTS];
static int numSegments;

static literal_t datavec_items[MAX_DATAVEC_ITEMS];
static int numDatavecItems;

static unsigned int datavec_origin;
static descriptor_size_t datavec_size = SIZE_0_BIT;
static int datavec_bits;
static int datavec_element_num;
static unsigned int datavec_partial_element;
static jump_type_t jump_type_context;

static int is_extended_operand(unsigned int cr, unsigned int k);
static void emit_16_bit_word(unsigned int word);
static void emit_32_bit_word(unsigned int word);
static void emit_64_bit_word(t_uint64 word);
static void emit_literal(literal_t *literal);
static void emit_datavec_line(void);
static void emit_partial_literal(unsigned int value);
static void write_16_bit_word(unsigned int word);
static void set_datavec_size(t_uint64 size);
static int get_datavec_partial_element_number(void);
static unsigned int get_current_descriptor_origin(void);
static unsigned int get_current_instruction_address(void);

t_uint64 scan_hex_digits(char *hex_digits)
{
    unsigned int i;
    int j;
    t_uint64 result = 0;
    unsigned int hex_digit;
    unsigned int dec_digit;
    int in_repeat_seq = 0;
    int repeat;
    for (i = 0; i < strlen(hex_digits); i++)
    {
        if (!in_repeat_seq)
        {
            if (sscanf(hex_digits + i, "%1X", &hex_digit))
            {
                result <<= 4;
                result |= hex_digit;
            }
            else
            {
                in_repeat_seq = 1;
                repeat = 0;
            }
        }
        else
        {
            if (sscanf(hex_digits + i, "%1u", &dec_digit))
            {
                repeat = repeat * 10 + dec_digit;
            }
            else
            {
                in_repeat_seq = 0;
                for (j = 0; j < repeat - 1; j++)
                {
                    result <<= 4;
                    result |= hex_digit;
                }
            }
        }
    }

    return result;
}

void set_pass(int new_pass)
{
    pass = new_pass;
    yylineno = 1;
}

void yyerror(const char *msg, ...)
{
	va_list ap;
	va_start(ap, msg);
    fprintf(stderr, "%d: ", yylineno);
	vfprintf(stderr, msg, ap);
	fprintf(stderr, " at '%s'\n", yytext);
    error_in_pass = 1;
	va_end(ap);
}

void start_segment(unsigned int segment_number)
{
    segment_t *seg;
    if (pass == PASS_CODE_GEN)
    {
        seg = get_segment(segment_number);
        write_16_bit_word(segment_number);
        write_16_bit_word(seg->length);
    }

    segment = segment_number;
    instructionNum = 0;
}

void end_segment(void)
{
    set_segment(segment, instructionNum);
}

segment_t *get_segment(unsigned int segment_number)
{
    int i;
    segment_t *entry = NULL;

    for (i = 0; i < numSegments; i++)
    {
        if (segment_table[i].segment == segment_number)
        {
            entry = &segment_table[i];
            break;
        }
    }

    return entry;
}

void set_segment(unsigned int segment_number, unsigned int length)
{
    segment_t *entry;
    if (pass == PASS_GET_FORWARDS)
    {
        if (get_segment(segment_number) != NULL)
        {
            yyerror("cannot define same segment more than once");
        }
        else if (numSegments >= MAX_SEGMENTS)
        {
            yyerror("too many segments");
        }
        else
        {
            entry = &segment_table[numSegments++];
            entry->segment = segment_number;
            entry->length = length;
        }
    }
    else
    {
        entry = get_segment(segment_number);
        entry->length = length;
    }
}

void init_var_spec_list(var_spec_list_t *var_spec_list)
{
    var_spec_list->length = 0;
}

void add_var_spec_list(var_spec_list_t *var_spec_list, var_spec_t *var_spec)
{
    if (var_spec_list->length >= MAX_VAR_SPECS)
    {
        yyerror("var spec list full");
    }
    else
    {
        memcpy(&var_spec_list->var_specs[var_spec_list->length++], var_spec, sizeof(var_spec_t));
    }

}

void add_declaration(var_type_t var_type, var_relative_to_t relativeTo, var_spec_list_t *var_spec_list)
{
    int i;
    for (i = 0; i < var_spec_list->length; i++)
    {
        var_spec_t *varspec = &var_spec_list->var_specs[i];
        if (relativeTo == STK && varspec->displacement != 0)
        {
            yyerror("displacement must be zero");
        }

        add_symbol(var_type, relativeTo, varspec->name, varspec->displacement);
    }
}

void add_symbol(var_type_t var_type, var_relative_to_t relativeTo, char *name, t_uint64 value)
{
	symbol_t *entry;
	if (pass == PASS_GET_FORWARDS)
	{
        /* TODO: check decl does not already exist, use a structure that is sorted */
        if (numSymbols >= MAX_SYMBOLS)
		{
			yyerror("symbol table full");
		}
		else
		{
			entry = &symbol_table[numSymbols++];
			entry->vartype = var_type;
			entry->relativeTo = relativeTo;
			entry->name = _strdup(name);
			entry->value = value;
		}
	}
	else
	{
		entry = find_symbol(name);
		entry->value = value;
		printf("%s at %016llX\n", name, value);
	}
}


symbol_t *find_symbol(char *name)
{
    int i;
    symbol_t *result = NULL;
    for (i = 0; i < numSymbols; i++)
    {
        if (strcmp(name, symbol_table[i].name) == 0)
        {
            result = &symbol_table[i];
            break;
        }
    }

    if (result == NULL && pass != PASS_GET_FORWARDS)
    {
        yyerror("symbol %s not declared", name);
    }

    return result;
}

void add_label(char *name)
{
    label_entry_t *entry;
    /* TODO: check decl does not already exist, use a structure that is sorted. Label scoping */
    if (pass == PASS_GET_FORWARDS)
    {
        if (find_label(name))
        {
            yyerror("label %s already defined", name);
        }

        entry = &label_table[numLabels++];
        entry->name = _strdup(name);
        entry->location = get_current_instruction_address();
    }
    else
    {
        entry = find_label(name);
        entry->location = get_current_instruction_address();
    }
}

label_entry_t *find_label(char *name)
{
    int i;
    label_entry_t *entry = NULL;
    for (i = 0; i < numLabels; i++)
    {
        if (strcmp(name, label_table[i].name) == 0)
        {
            entry = &label_table[i];
            break;
        }
    }

    return entry;
}

char *proc_end_label(char *name)
{
	static char label[80];
	strcpy(label, "_");
	strcat(label, name);
	return label;
}

void set_operand_label_context(jump_type_t jump_type)
{
	jump_type_context = jump_type;
}

int set_operand_label(char *name, jump_type_t jump_type, operand_t *operand)
{
    label_entry_t *entry = find_label(name);

    operand->operand_type = OPERAND_LITERAL;

    if (jump_type == JUMP_RELATIVE_DEFAULT)
    {
        operand->literal.literal_type = LITERAL_SIGNED_16_BIT;
    }
    else if (jump_type == JUMP_RELATIVE_SHORT)
    {
        operand->literal.literal_type = LITERAL_SIGNED_6_BIT;
    }
	else if (jump_type == JUMP_RELATIVE_LONG)
	{
		operand->literal.literal_type = LITERAL_SIGNED_32_BIT;
	}
	else
	{
		operand->literal.literal_type = LITERAL_UNSIGNED_32_BIT;
	}

    if (entry == NULL)
    {
        if (pass > PASS_GET_FORWARDS)
        {
            yyerror("label %s not found", name);
        }
        else
        {
            operand->literal.signed_val = 0; /* dummy value for now */
        }
    }
    else
    {
		if (jump_type != JUMP_ABSOLUTE)
		{
			operand->literal.signed_val = (t_int64)entry->location - (t_int64)get_current_instruction_address();
//			if (pass == PASS_GET_FORWARDS + 1) printf("Label %s is at %08X (relative)\n", name, operand->literal.signed_val & 0xFFFFFFFF);
		}
		else
		{
			operand->literal.unsigned_val = (t_int64)entry->location;
//			if (pass == PASS_GET_FORWARDS + 1) printf("Label %s is at %08X (absolute)\n", name, operand->literal.unsigned_val & 0xFFFFFFFF);
		}
	}

    return 1;
}

void set_operand(char *name, operand_t *operand)
{
	label_entry_t *label = find_label(name);
	if (label != NULL)
	{
		set_operand_label(name, jump_type_context, operand);
	}
	else
	{
		operand->operand_type = OPERAND_VARIABLE;
		operand->symbol = find_symbol(name);
	}
}

literal_type_t get_literal_type(int sign, t_uint64 value)
{
	literal_type_t literal_type;
	if (sign != 0)
	{
		if (datavec_size == SIZE_0_BIT)
		{
			if (sign < 0)
			{
				if (value < 0x20)
				{
					literal_type = LITERAL_SIGNED_6_BIT;
				}
				else if (value < 0x8000)
				{
					literal_type = LITERAL_SIGNED_16_BIT;
				}
				else if (value < 0x80000000)
				{
					literal_type = LITERAL_SIGNED_32_BIT;
				}
				else
				{
					literal_type = LITERAL_SIGNED_64_BIT;
				}
			}
			else
			{
				if (value < 0x1F)
				{
					literal_type = LITERAL_SIGNED_6_BIT;
				}
				else if (value < 0x7FFF)
				{
					literal_type = LITERAL_SIGNED_16_BIT;
				}
				else if (value < 0x7FFFFFFF)
				{
					literal_type = LITERAL_SIGNED_32_BIT;
				}
				else
				{
					literal_type = LITERAL_SIGNED_64_BIT;
				}
			}
		}
        else if (datavec_size == SIZE_1_BIT)
        {
            literal_type = LITERAL_SIGNED_1_BIT;
        }
        else if (datavec_size == SIZE_4_BIT)
        {
            literal_type = LITERAL_SIGNED_4_BIT;
        }
        else if (datavec_size == SIZE_8_BIT)
        {
            literal_type = LITERAL_SIGNED_8_BIT;
        }
        else if (datavec_size == SIZE_16_BIT)
        {
            literal_type = LITERAL_SIGNED_16_BIT;
        }
        else if (datavec_size == SIZE_32_BIT)
		{
			literal_type = LITERAL_SIGNED_32_BIT;
		}
		else if (datavec_size == SIZE_64_BIT)
		{
			literal_type = LITERAL_SIGNED_64_BIT;
		}
	}
	else
	{
		if (datavec_size == SIZE_0_BIT)
		{
			if (value < 0x1F)
			{
				literal_type = LITERAL_SIGNED_6_BIT;
			}
			else if (value < 0xFFFF)
			{
				literal_type = LITERAL_UNSIGNED_16_BIT;
			}
			else if (value < 0xFFFFFFFF)
			{
				literal_type = LITERAL_UNSIGNED_32_BIT;
			}
			else
			{
				literal_type = LITERAL_UNSIGNED_64_BIT;
			}
		}
        else if (datavec_size == SIZE_1_BIT)
        {
            literal_type = LITERAL_UNSIGNED_1_BIT;
        }
        else if (datavec_size == SIZE_4_BIT)
        {
            literal_type = LITERAL_UNSIGNED_4_BIT;
        }
        else if (datavec_size == SIZE_8_BIT)
        {
            literal_type = LITERAL_UNSIGNED_8_BIT;
        }
        else if (datavec_size == SIZE_16_BIT)
		{
			literal_type = LITERAL_UNSIGNED_16_BIT;
		}
		else if (datavec_size == SIZE_32_BIT)
		{
			literal_type = LITERAL_UNSIGNED_32_BIT;
		}
		else if (datavec_size == SIZE_64_BIT)
		{
			literal_type = LITERAL_UNSIGNED_64_BIT;
		}
	}

	return literal_type;
}

void make_int_literal(int sign, t_uint64 value, literal_t *literal)
{
	literal->literal_type = get_literal_type(sign, value);
	switch (literal->literal_type)
	{
        case LITERAL_SIGNED_1_BIT:
        case LITERAL_SIGNED_4_BIT:
        case LITERAL_SIGNED_6_BIT:
        case LITERAL_SIGNED_8_BIT:
        case LITERAL_SIGNED_16_BIT:
		case LITERAL_SIGNED_32_BIT:
		case LITERAL_SIGNED_64_BIT:
		{
			if (sign < 0)
			{
				literal->signed_val = -(t_int64)value;
			}
			else
			{
				literal->signed_val = value;
			}
			break;
		}

        case LITERAL_UNSIGNED_1_BIT:
        case LITERAL_UNSIGNED_4_BIT:
        case LITERAL_UNSIGNED_8_BIT:
        case LITERAL_UNSIGNED_16_BIT:
        case LITERAL_UNSIGNED_32_BIT:
		case LITERAL_UNSIGNED_64_BIT:
		{
			literal->unsigned_val = value;
		}
	}
}

t_uint64 make_descriptor(descriptor_type_t type, descriptor_size_t size, unsigned char unscaled, unsigned char noboundcheck, unsigned int bound, unsigned int origin)
{
    t_uint64 result = 0;

    result |= ((t_uint64)type & 0x3) << 62;
    result |= ((t_uint64)size & 0x7) << 59;
    result |= ((t_uint64)bound & 0xFFFFFF) << 32;
    result |= ((t_uint64)origin & 0xFFFFFFFF);

    return result;
}

void process_instruction(unsigned int cr, unsigned int f, operand_t *operand)
{
    unsigned int k = 0;
    t_int64 n = 0;
    unsigned int kp = 0;
    unsigned int np = 0;
    t_int64 offset = 0;

    if (operand->operand_type == OPERAND_LITERAL)
    {
        if (operand->literal.literal_type == LITERAL_SIGNED_6_BIT)
        {
            k = 0;
        }
        else
        {
            k = (cr == 0) ? 1 : 7;
            kp = 0;
            np = operand->literal.literal_type;
        }

        n = operand->literal.signed_val;
    }
    else
    {

        if (operand->symbol != NULL)
        {
            switch (operand->operand_type)
            {
                case OPERAND_VARIABLE_0_REL:
                case OPERAND_VARIABLE_B_REL:
                {
                    if (operand->symbol->vartype == DESCRIPTOR)
                    {
                        if (operand->symbol != &d_symbol)
                        {
                            emit_extended_instruction(3, 1, 0, 6); /* D= 64-bit literal */
                            emit_64_bit_word(operand->symbol->value);
                        }
                        k = (cr == 0) ? 1 : 7;
                        kp = (operand->operand_type == OPERAND_VARIABLE_B_REL) ? 4 : 6;
                        np = 5;
                    }
                    else
                    {
                        k = (operand->operand_type == OPERAND_VARIABLE_B_REL) ? 4 : 6;
                        n = operand->symbol->value;
                    }
                    break;
                }
                case OPERAND_VARIABLE:
                {
                    switch (operand->symbol->vartype)
                    {
                        case V32:
                        {
                            switch (operand->symbol->relativeTo)
                            {
                                case NB:
                                {
                                    k = 2;
                                    n = operand->symbol->value;
                                    break;
                                }
                                case STK:
                                {
                                    k = (cr == 0) ? 1 : 7;
                                    kp = 2;
                                    np = 4;
                                    break;
                                }
                                case ZERO:
                                {
                                    k = (cr == 0) ? 1 : 7;
                                    kp = 2;
                                    np = 1;
                                    offset = (t_int64)operand->symbol->value;
                                    break;
                                }
                                case XNB:
                                {
                                    k = (cr == 0) ? 1 : 7;
                                    kp = 2;
                                    np = 3;
                                    offset = (t_int64)operand->symbol->value;
                                    break;
                                }
                                default:
                                {
                                    yyerror("relative type not handled");
                                    break;
                                }
                            }
                            break;
                        }
                        case V64:
                        {
                            switch (operand->symbol->relativeTo)
                            {
                                case NB:
                                {
                                    k = 3;
                                    n = operand->symbol->value;
                                    break;
                                }
                                case STK:
                                {
                                    k = (cr == 0) ? 1 : 7;
                                    kp = 3;
                                    np = 4;
                                    break;
                                }
                                case ZERO:
                                {
                                    k = (cr == 0) ? 1 : 7;
                                    kp = 3;
                                    np = 1;
                                    offset = operand->symbol->value;
                                    break;
                                }
                                case XNB:
                                {
                                    k = (cr == 0) ? 1 : 7;
                                    kp = 3;
                                    np = 3;
                                    offset = operand->symbol->value;
                                    break;
                                }
                                default:
                                {
                                    yyerror("relative type not handled");
                                    break;
                                }
                            }
                            break;
                        }
                        case VV:
                        {
                            k = (cr == 0) ? 1 : 7;
                            kp = 7;
                            switch (operand->symbol->relativeTo)
                            {
                                case NB:
                                {
                                    np = 2;
                                    offset = operand->symbol->value;
                                    break;
                                }
                                case STK:
                                {
                                    np = 4;
                                    break;
                                }
                                case ZERO:
                                {
                                    np = 1;
                                    offset = operand->symbol->value;
                                    break;
                                }
                                case XNB:
                                {
                                    np = 3;
                                    offset = operand->symbol->value;
                                    break;
                                }
                                default:
                                {
                                    yyerror("relative type not handled");
                                    break;
                                }
                            }
                            break;
                        }
						case DESCRIPTOR:
						{
							k = (cr == 0) ? 1 : 7;
							kp = 0;
							np = LITERAL_UNSIGNED_64_BIT;
							n = operand->symbol->value;
							operand->literal.literal_type = LITERAL_UNSIGNED_64_BIT;
							operand->literal.unsigned_val = n;
							break;
						}
                        case IR:
                        {
                            if (cr == 0)
                            {
                                yyerror("cannot use IR operand for org order");
                            }

                            k = 1;
                            n = operand->symbol->value;
                            break;
                        }
                        default:
                        {
                            yyerror("unhandled vartype");
                            break;
                        }
                    }
                    break;
                }
            }
        }

    }

    if (is_extended_operand(cr, k))
    {
        emit_extended_instruction(cr, f, kp, np);
    }
    else
    {
        emit_instruction(cr, f, k, n & 0x3F);
    }

    if (is_extended_operand(cr, k) && kp > 1 && np < 4)
    {
        emit_16_bit_word(offset & 0xFFFF);
    }
    else if (is_extended_operand(cr, k) && kp <= 1)
    {
		emit_literal(&operand->literal);
    }
}

static unsigned int get_current_descriptor_origin()
{
    unsigned int result = (segment << 18) + instructionNum * 2; /* segment has to be shifted 2 to the left because this is a byte origin */
    return result;
}

static unsigned int get_current_instruction_address()
{
	unsigned int result = (segment << 17) + instructionNum; /* segment has to be shifted 1 to the left because this is 16-bit word address */
	return result;
}

t_uint64 process_text(char *name, char *string)
{
    int i;
    int n = 0;
    unsigned int word;
    char c;
    unsigned int byte;
    int valid_byte = 1;
    int started_hex = 0;
    unsigned int origin = get_current_descriptor_origin();

    for (i = 1; i < (int)strlen(string) - 1; i++) /* skip first and last chars as they are the quotes */
    {
        c = string[i];
        if (c != '|')
        {
            if (!started_hex)
            {
                byte = c & 0xFF;
                valid_byte = 1;
            }
            else
            {
                byte = byte << 4;
                if (isdigit(c))
                {
                    byte |= c - '0';
                }
                else
                {
                    byte |= (tolower(c) - 'a' + 10) & 0xF;
                }
            }
        }
        else if (!started_hex)
        {
            valid_byte = 0;
            started_hex = 1;
            byte = 0;
        }
        else
        {
            started_hex = 0;
            valid_byte = 1;
        }

        if (valid_byte)
        {
            if ((n % 2) == 0)
            {
                word = byte << 8;
            }
            else
            {
                word |= byte;
                emit_16_bit_word(word);
            }
            n++;
        }
    }

    if ((n % 2) != 0)
    {
        emit_16_bit_word(word);
    }

    return make_descriptor(STRING_VECTOR, SIZE_8_BIT, 0, 0, n, origin);
}

static void set_datavec_size(t_uint64 size)
{
    switch (size)
    {
        case 0:
        {
            datavec_size = SIZE_0_BIT;
            break;
        }
        case 1:
        {
            datavec_size = SIZE_1_BIT;
            break;
        }
        case 4:
        {
            datavec_size = SIZE_4_BIT;
            break;
        }
        case 8:
        {
            datavec_size = SIZE_8_BIT;
            break;
        }
        case 16:
        {
            datavec_size = SIZE_16_BIT;
            break;
        }
        case 32:
        {
            datavec_size = SIZE_32_BIT;
            break;
        }
        case 64:
        {
            datavec_size = SIZE_64_BIT;
            break;
        }
        default:
        {
            yyerror("datavec size not supported");
            break;
        }
    }

	datavec_bits = (int)size;
}

void process_datavec_start(t_uint64 size)
{
    set_datavec_size(size);
    datavec_origin = get_current_descriptor_origin();
    datavec_element_num = 0;
    datavec_partial_element = 0;
}

void process_datavec_literal(literal_t *literal)
{
    if (numDatavecItems >= MAX_DATAVEC_ITEMS)
    {
        yyerror("too many datavec items on one line");
    }
    else
    {
        memcpy(&datavec_items[numDatavecItems++], literal, sizeof(literal_t));
    }
}

void process_datavec_line_end()
{
    emit_datavec_line();
    numDatavecItems = 0;
}

static int get_datavec_partial_element_number()
{
    int elems_in_word = 16 / datavec_bits;
    int elem_in_word = elems_in_word - (datavec_element_num % elems_in_word) - 1;
    return elem_in_word;
}

t_uint64 process_datavec_end()
{
    t_uint64 d;
	if (datavec_bits < 16)
	{
		if (get_datavec_partial_element_number() != ((16 / datavec_bits) - 1))
		{
			emit_16_bit_word(datavec_partial_element);
		}
	}
    d = make_descriptor(GENERAL_VECTOR, datavec_size, 0, 0, datavec_element_num, datavec_origin);
    set_datavec_size(0);
    return d;
}

void process_datavec_line_repeat(unsigned int n)
{
    unsigned int i;
    for (i = 0; i < n; i++)
    {
        emit_datavec_line();
    }
    numDatavecItems = 0;
}

static void emit_datavec_line()
{
    int i;
    for (i = 0; i < numDatavecItems; i++)
    {
        emit_literal(&datavec_items[i]);
        datavec_element_num++;
    }
}

static int is_extended_operand(unsigned int cr, unsigned int k)
{
    return (cr != 0 && k == 7) || (cr == 0 && k == 1);
}

void emit_instruction(unsigned char cr, unsigned char f, unsigned char k, unsigned char n)
{
    unsigned int instruction = 0;

    instruction = (cr & 7) << 13;
    if (cr == 0)
    {
        instruction |= (f & 0x3F) << 7;
        instruction |= (k & 1) << 6;
    }
    else
    {
        instruction |= (f & 0xF) << 9;
        instruction |= (k & 7) << 6;
    }

    instruction |= (n & 0x3F);

    emit_16_bit_word(instruction);
}

void emit_extended_instruction(unsigned char cr, unsigned char f, unsigned char kp, unsigned char np)
{
    unsigned int n;
    n = (kp & 0x7) << 3;
    n |= np & 0x7;
    emit_instruction(cr, f, 7, n);
}

void start_proc(char *name)
{
	operand_t operand;
	set_operand_label(proc_end_label(name), JUMP_ABSOLUTE, &operand);
	process_instruction(0, 4, &operand);
	add_label(name);
}

void end_proc(char *name)
{
	add_label(proc_end_label(name));
}

void stack_call_link(char *name)
{
	operand_t operand;
	set_operand_label(name, JUMP_RELATIVE_LONG, &operand);
	process_instruction(0, 15, &operand);
}

void stack_call_parameter(operand_t *operand)
{
	process_instruction(2, 2, operand);
}

static void emit_16_bit_word(unsigned int word)
{
	if (pass == PASS_CODE_GEN)
    {
        printf("(%d)%04X.%04X:%04X\n", yylineno, segment, instructionNum, word);
        write_16_bit_word(word);
    }

    instructionNum++;
}

static void emit_32_bit_word(unsigned int word)
{
    emit_16_bit_word((word >> 16) & 0xFFFF);
    emit_16_bit_word(word & 0xFFFF);
}

static void emit_64_bit_word(t_uint64 word)
{
    emit_16_bit_word((word >> 48) & 0xFFFF);
    emit_16_bit_word((word >> 32) & 0xFFFF);
    emit_16_bit_word((word >> 16) & 0xFFFF);
    emit_16_bit_word(word & 0xFFFF);
}

static void emit_partial_literal(unsigned int value)
{
    int elem_in_word = get_datavec_partial_element_number();
    datavec_partial_element |= value << (datavec_bits * elem_in_word);
    if (elem_in_word == 0)
    {
        emit_16_bit_word(datavec_partial_element);
        datavec_partial_element = 0;
    }
}

static void emit_literal(literal_t *literal)
{
	switch (literal->literal_type)
	{
        case LITERAL_SIGNED_1_BIT:
        case LITERAL_UNSIGNED_1_BIT:
        {
            emit_partial_literal(literal->unsigned_val & 0x1);
            break;
        }
        case LITERAL_SIGNED_4_BIT:
        case LITERAL_UNSIGNED_4_BIT:
        {
            emit_partial_literal(literal->unsigned_val & 0xF);
            break;
        }
        case LITERAL_SIGNED_8_BIT:
        case LITERAL_UNSIGNED_8_BIT:
        {
            emit_partial_literal(literal->unsigned_val & 0xFF);
            break;
        }
        case LITERAL_SIGNED_6_BIT:
        case LITERAL_SIGNED_16_BIT:
        case LITERAL_UNSIGNED_16_BIT:
        {
            emit_16_bit_word(literal->unsigned_val & 0xFFFF);
            break;
        }
        case LITERAL_SIGNED_32_BIT:
		case LITERAL_UNSIGNED_32_BIT:
		{
			emit_32_bit_word(literal->unsigned_val & 0xFFFFFFFF);
			break;
		}
		case LITERAL_SIGNED_64_BIT:
		case LITERAL_UNSIGNED_64_BIT:
		{
			emit_64_bit_word(literal->unsigned_val);
			break;
		}
	}
}

static void write_16_bit_word(unsigned int word)
{
    unsigned char byte;
    byte = (word >> 8) & 0xFF;
    fwrite(&byte, 1, 1, binary);
    byte = word & 0xFF;
    fwrite(&byte, 1, 1, binary);
}
