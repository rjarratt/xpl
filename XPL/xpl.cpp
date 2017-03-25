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

static int is_extended_operand(unsigned int cr, unsigned int k);
static void emit_instruction(unsigned char cr, unsigned char f, unsigned char k, unsigned char n);
static void emit_extended_instruction(unsigned char cr, unsigned char f, unsigned char kp, unsigned char np);
static void emit_16_bit_word(unsigned int word);
static void emit_32_bit_word(unsigned int word);
static void emit_64_bit_word(t_uint64 word);

void set_pass(int new_pass)
{
    printf("starting pass %d\n", new_pass);
    pass = new_pass;
    instructionNum = 0;
    yylineno = 1;
}

void yyerror(char *msg)
{
    fprintf(stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
    error_in_pass = 1;
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
    /* TODO: check decl does not already exist, use a structure that is sorted */
    int i;
    if (pass == 1)
    {
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
}

void add_symbol(var_type_t var_type, var_relative_to_t relativeTo, char *name, t_uint64 value)
{
	symbol_t *entry;
	if (pass == 1)
	{
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

    if (result == NULL && pass != 1)
    {
        yyerror("symbol not declared");
    }

    return result;
}

void add_label(char *name)
{
    /* TODO: check decl does not already exist, use a structure that is sorted. Label scoping */
    if (pass == 1)
    {
        label_entry_t *entry = &label_table[numLabels++];
        entry->name = _strdup(name);
        entry->location = instructionNum;
    }
}

int find_label(char *name, int distance, operand_t *operand)
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
        if (pass > 1)
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
	else
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

	return literal_type;
}

void make_int_literal(int sign, t_uint64 value, literal_t *literal)
{
	literal->literal_type = get_literal_type(sign, value);
	switch (literal->literal_type)
	{
		case LITERAL_SIGNED_6_BIT:
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
		switch (np)
		{
			case LITERAL_SIGNED_16_BIT:
			case LITERAL_UNSIGNED_16_BIT:
			{
				emit_16_bit_word(n & 0xFFFF);
				break;
			}
			case LITERAL_SIGNED_32_BIT:
			case LITERAL_UNSIGNED_32_BIT:
			{
				emit_32_bit_word(n & 0xFFFFFFFF);
				break;
			}
			case LITERAL_SIGNED_64_BIT:
			case LITERAL_UNSIGNED_64_BIT:
			{
				emit_64_bit_word((t_uint64)n);
				break;
			}
		}
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
    unsigned char byte;
	if (pass == 2)
    {
        printf("%3d:%04X\n", instructionNum, word);
        byte = (word >> 8) & 0xFF;
        fwrite(&byte, 1, 1, binary);
        byte = word & 0xFF;
        fwrite(&byte, 1, 1, binary);
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

