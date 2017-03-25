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

extern char *yytext;
extern int yylineno;

static int pass;
static unsigned int instructionNum;

static var_decl_t symbol_table[MAX_SYMBOLS];
static int numSymbols = 0;

static label_entry_t label_table[MAX_LABELS];
static int numLabels;

static int is_extended_operand(unsigned int cr, unsigned int k);
static void emit_16_bit_word(unsigned int word);

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

			if (numSymbols >= MAX_SYMBOLS)
			{
				yyerror("symbol table full");
			}
			else
			{
				var_decl_t *entry = &symbol_table[numSymbols++];
				entry->vartype = var_type;
				entry->relativeTo = relativeTo;
				entry->varspec.name = _strdup(varspec->name);
				entry->varspec.displacement = varspec->displacement;
			}
		}
	}
}

var_decl_t *find_declaration(char *name)
{
	int i;
	var_decl_t *result = NULL;
	for (i = 0; i < numSymbols; i++)
	{
		if (strcmp(name, symbol_table[i].varspec.name) == 0)
		{
			result = &symbol_table[i];
			break;
		}
	}

	if (result == NULL)
	{
		yyerror("variable not declared");
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

void make_int_literal(int sign, t_uint64 value, literal_t *literal)
{
	if (sign != 0)
	{
		if (sign < 0)
		{
			literal->signed_val = -(t_int64)value;
			if (value < 0x20)
			{
				literal->literal_type = LITERAL_SIGNED_6_BIT;
			}
			else if (value < 0x8000)
			{
				literal->literal_type = LITERAL_SIGNED_16_BIT;
			}
			else if (value < 0x80000000)
			{
				literal->literal_type = LITERAL_SIGNED_32_BIT;
			}
			else
			{
				literal->literal_type = LITERAL_SIGNED_64_BIT;
			}
		}
		else
		{
			literal->signed_val = value;
			if (value < 0x1F)
			{
				literal->literal_type = LITERAL_SIGNED_6_BIT;
			}
			else if (value < 0x7FFF)
			{
				literal->literal_type = LITERAL_SIGNED_16_BIT;
			}
			else if (value < 0x7FFFFFFF)
			{
				literal->literal_type = LITERAL_SIGNED_32_BIT;
			}
			else
			{
				literal->literal_type = LITERAL_SIGNED_64_BIT;
			}
		}
	}
	else
	{
		literal->unsigned_val = value;
		if (value < 0x1F)
		{
			literal->literal_type = LITERAL_SIGNED_6_BIT;
			literal->signed_val = value;
		}
		else if (value < 0xFFFF)
		{
			literal->literal_type = LITERAL_UNSIGNED_16_BIT;
		}
		else if (value < 0xFFFFFFFF)
		{
			literal->literal_type = LITERAL_UNSIGNED_32_BIT;
		}
		else
		{
			literal->literal_type = LITERAL_UNSIGNED_64_BIT;
		}
	}
}

void process_instruction(unsigned int cr, unsigned int f, operand_t *operand)
{
	unsigned int instruction;
	unsigned int k = 0;
	t_int64 n = 0;
	unsigned int kp = 0;
	unsigned int np = 0;
	unsigned int offset = 0;

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

		if (operand->var_decl != NULL)
		{
            if (operand->operand_type == OPERAND_VARIABLE_B_REL)
            {
                k = 4;
                n = operand->var_decl->varspec.displacement; /* TODO: N>32 */
            }
            else if (operand->operand_type == OPERAND_VARIABLE_0_REL)
            {
                k = 6;
                n = operand->var_decl->varspec.displacement;  /* TODO: N>32 */
            }
            else
            {
                switch (operand->var_decl->vartype)
                {
                    case V32:
                    {
                        if (operand->var_decl->relativeTo == NB)
                        {
                            k = 2;
                            n = operand->var_decl->varspec.displacement;
                        }
                        else if (operand->var_decl->relativeTo == STK)
                        {
                            k = (cr == 0) ? 1 : 7;
                            kp = 2;
                            np = 4;
                        }
                        else if (operand->var_decl->relativeTo == ZERO)
                        {
                            k = (cr == 0) ? 1 : 7;
                            kp = 2;
                            np = 1;
                            offset = operand->var_decl->varspec.displacement;
                        }
                        else
                        {
                            yyerror("non-NB relative not handled yet");
                        }
                        break;
                    }
                    case V64:
                    {
                        if (operand->var_decl->relativeTo == NB)
                        {
                            k = 3;
                            n = operand->var_decl->varspec.displacement;
                        }
                        else if (operand->var_decl->relativeTo == STK)
                        {
                            k = (cr == 0) ? 1 : 7;
                            kp = 3;
                            np = 4;
                        }
                        else if (operand->var_decl->relativeTo == ZERO)
                        {
                            k = (cr == 0) ? 1 : 7;
                            kp = 3;
                            np = 1;
                            offset = operand->var_decl->varspec.displacement;
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
                        if (operand->var_decl->relativeTo == NB)
                        {
                            np = 2;
                            offset = operand->var_decl->varspec.displacement;
                        }
                        else if (operand->var_decl->relativeTo == STK)
                        {
                            np = 4;
                        }
                        else if (operand->var_decl->relativeTo == ZERO)
                        {
                            np = 1;
                            offset = operand->var_decl->varspec.displacement;
                        }
                        else
                        {
                            yyerror("non-NB relative not handled yet");
                        }
                        break;
                    }
                    default:
                    {
                        yyerror("unhandled vartype");
                        break;
                    }
                }
            }
		}

	}

	if (cr == 0)
	{
		instruction = (cr & 7) << 13;
		instruction |= (f & 0x3F) << 7;
		instruction |= (k & 1) << 6;
	}
	else
	{
		instruction = (cr & 7) << 13;
		instruction |= (f & 0xF) << 9;
		instruction |= (k & 7) << 6;
	}

	if (is_extended_operand(cr, k))
	{
		instruction |= kp << 3;
		instruction |= np;
	}
	else if (n > -33 && n < 32)
	{
		instruction |= (n & 0x3F);
	}

	emit_16_bit_word(instruction);

	if (is_extended_operand(cr, k) && kp > 1 && np < 4)
	{
		emit_16_bit_word(offset);
	}
	else if (n <= -33 || n >= 32)
	{
		if (n > -65536 && n < 65535)
		{
			emit_16_bit_word(n & 0xFFFF);
			//do the rest of opereand literals
		}
	}

	//printf("cr=%u f=%u ", cr, f);
	//if (operand->operand_type == OPERAND_LITERAL)
	//{
	//	printf("lit=0x%llX ", operand->unsignedLiteral);
	//}
	//else
	//{
	//	printf("var=%s ", operand->var_decl->varspec.name);
	//}

}

void process_text(char *name, char *string)
{
	int i;
	int n = 0;
	unsigned int word;
	char c;
	unsigned int byte;
	int valid_byte = 1;
	int started_hex = 0;
	printf("%s=%s\n", name, string);
	for (i = 0; i < strlen(string); i++)
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
}

static int is_extended_operand(unsigned int cr, unsigned int k)
{
	return (cr != 0 && k == 7) || (cr == 0 && k == 1);
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
