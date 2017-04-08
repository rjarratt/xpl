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
#include <string.h>
#include <ctype.h>
#include "xpl.h"

FILE *binary;
int error_in_pass;
unsigned int segment;

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

static int datavec_size;
static int datavec_element_num;
static unsigned int datavec_partial_element;

static int is_extended_operand(unsigned int cr, unsigned int k);
static void emit_instruction(unsigned char cr, unsigned char f, unsigned char k, unsigned char n);
static void emit_extended_instruction(unsigned char cr, unsigned char f, unsigned char kp, unsigned char np);
static void emit_16_bit_word(unsigned int word);
static void emit_32_bit_word(unsigned int word);
static void emit_64_bit_word(t_uint64 word);
static void emit_literal(literal_t *literal);
static void emit_datavec_line();
static void emit_partial_literal(unsigned int value);
static void write_16_bit_word(unsigned int word);
static void set_datavec_size(t_uint64 size);
static int get_datavec_partial_element_number();

void set_pass(int new_pass)
{
    pass = new_pass;
    yylineno = 1;
}

void yyerror(char *msg)
{
    fprintf(stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
    error_in_pass = 1;
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
        yyerror("symbol not declared");
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
            yyerror("label already defined");
        }

        entry = &label_table[numLabels++];
        entry->name = _strdup(name);
        entry->location = instructionNum;
    }
    else
    {
        entry = find_label(name);
        entry->location = instructionNum;
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

int set_operand_label(char *name, int distance, operand_t *operand)
{
    label_entry_t *entry = find_label(name);

    operand->operand_type = OPERAND_LITERAL;

    if (distance == 0)
    {
        operand->literal.literal_type = LITERAL_SIGNED_16_BIT;
    }
    else if (distance < 0)
    {
        operand->literal.literal_type = LITERAL_SIGNED_6_BIT;
    }
    else
    {
        operand->literal.literal_type = LITERAL_SIGNED_32_BIT;
    }

    if (entry == NULL)
    {
        if (pass > PASS_GET_FORWARDS)
        {
            yyerror("label not found");
        }
        else
        {
            operand->literal.signed_val = 0; /* dummy value for now */
        }
    }
    else
    {
        operand->literal.signed_val = (t_int64)entry->location - (t_int64)instructionNum;
    }

    return 1;
}

literal_type_t get_literal_type(int sign, t_uint64 value)
{
	literal_type_t literal_type;
	if (sign != 0)
	{
		if (datavec_size == 0)
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
        else if (datavec_size == 1)
        {
            literal_type = LITERAL_SIGNED_1_BIT;
        }
        else if (datavec_size == 4)
        {
            literal_type = LITERAL_SIGNED_4_BIT;
        }
        else if (datavec_size == 8)
        {
            literal_type = LITERAL_SIGNED_8_BIT;
        }
        else if (datavec_size == 16)
        {
            literal_type = LITERAL_SIGNED_16_BIT;
        }
        else if (datavec_size == 32)
		{
			literal_type = LITERAL_SIGNED_32_BIT;
		}
		else if (datavec_size == 64)
		{
			literal_type = LITERAL_SIGNED_64_BIT;
		}
	}
	else
	{
		if (datavec_size == 0)
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
        else if (datavec_size == 1)
        {
            literal_type = LITERAL_UNSIGNED_1_BIT;
        }
        else if (datavec_size == 4)
        {
            literal_type = LITERAL_UNSIGNED_4_BIT;
        }
        else if (datavec_size == 8)
        {
            literal_type = LITERAL_UNSIGNED_8_BIT;
        }
        else if (datavec_size == 16)
		{
			literal_type = LITERAL_UNSIGNED_16_BIT;
		}
		else if (datavec_size == 32)
		{
			literal_type = LITERAL_UNSIGNED_32_BIT;
		}
		else if (datavec_size == 64)
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
                        emit_extended_instruction(3, 1, 0, 6); /* D= 64-bit literal */
                        emit_64_bit_word(operand->symbol->value);
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
                            if (operand->symbol->relativeTo == NB)
                            {
                                k = 2;
                                n = operand->symbol->value;
                            }
                            else if (operand->symbol->relativeTo == STK)
                            {
                                k = (cr == 0) ? 1 : 7;
                                kp = 2;
                                np = 4;
                            }
                            else if (operand->symbol->relativeTo == ZERO)
                            {
                                k = (cr == 0) ? 1 : 7;
                                kp = 2;
                                np = 1;
                                offset = (t_int64)operand->symbol->value;
                            }
                            else
                            {
                                yyerror("non-NB relative not handled yet");
                            }
                            break;
                        }
                        case V64:
                        {
                            if (operand->symbol->relativeTo == NB)
                            {
                                k = 3;
                                n = operand->symbol->value;
                            }
                            else if (operand->symbol->relativeTo == STK)
                            {
                                k = (cr == 0) ? 1 : 7;
                                kp = 3;
                                np = 4;
                            }
                            else if (operand->symbol->relativeTo == ZERO)
                            {
                                k = (cr == 0) ? 1 : 7;
                                kp = 3;
                                np = 1;
                                offset = operand->symbol->value;
                            }
                            else
                            {
                                yyerror("non-NB relative not handled yet");
                            }
                            break;
                        }
                        case VV:
                        {
                            k = (cr == 0) ? 1 : 7;
                            kp = 7;
                            if (operand->symbol->relativeTo == NB)
                            {
                                np = 2;
                                offset = operand->symbol->value;
                            }
                            else if (operand->symbol->relativeTo == STK)
                            {
                                np = 4;
                            }
                            else if (operand->symbol->relativeTo == ZERO)
                            {
                                np = 1;
                                offset = operand->symbol->value;
                            }
                            else
                            {
                                yyerror("non-NB relative not handled yet");
                            }
                            break;
                        }
						case DESCRIPTOR:
						{
							k = (cr == 0) ? 1 : 7;
							kp = 0;
							np = LITERAL_UNSIGNED_64_BIT;
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

t_uint64 process_text(char *name, char *string)
{
    int i;
    int n = 0;
    unsigned int word;
    char c;
    unsigned int byte;
    int valid_byte = 1;
    int started_hex = 0;
    unsigned int origin = (segment << 18) + instructionNum * 2; /* segment has to be shifted 2 to the left because this is a byte origin */

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
	if (size != 0 && size != 1 && size != 4 && size != 8 && size != 16 && size != 32 && size != 64)
	{
		yyerror("datavec size not supported");
	}

	datavec_size = (int)size;
}

void process_datavec_start(t_uint64 size)
{
    set_datavec_size(size);
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
    int elems_in_word = 16 / datavec_size;
    int elem_in_word = elems_in_word - (datavec_element_num % elems_in_word) - 1;
    return elem_in_word;

}
void process_datavec_end()
{
    if (get_datavec_partial_element_number() != ((16 / datavec_size) - 1))
    {
        emit_16_bit_word(datavec_partial_element);
    }
    set_datavec_size(0);
}

void process_datavec_line_repeat(unsigned int n)
{
    int i;
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

static void emit_instruction(unsigned char cr, unsigned char f, unsigned char k, unsigned char n)
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

static void emit_extended_instruction(unsigned char cr, unsigned char f, unsigned char kp, unsigned char np)
{
    unsigned int n;
    n = (kp & 0x7) << 3;
    n |= np & 0x7;
    emit_instruction(cr, f, 7, n);
}

static void emit_16_bit_word(unsigned int word)
{
	if (pass == PASS_CODE_GEN)
    {
        printf("%05d.%05d:%04X\n", segment, instructionNum, word);
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
    datavec_partial_element |= value << (datavec_size * elem_in_word);
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
