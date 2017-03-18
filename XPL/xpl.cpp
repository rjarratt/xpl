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
#include "xpl.h"

extern char *yytext;
extern int yylineno;

static t_var_decl symbol_table[MAX_SYMBOLS];
static int numSymbols = 0;

static void emit(unsigned int word);

void yyerror(char *msg)
{
    fprintf(stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
}

void init_var_spec_list(t_var_spec_list *var_spec_list)
{
    var_spec_list->length = 0;
}

void add_var_spec_list(t_var_spec_list *var_spec_list, t_var_spec *var_spec)
{
    if (var_spec_list->length >= MAX_VAR_SPECS)
    {
        yyerror("var spec list full");
    }
    else
    {
        memcpy(&var_spec_list->var_specs[var_spec_list->length++], var_spec, sizeof(t_var_spec));
    }

}

void add_declaration(t_var_type var_type, t_var_relative_to relativeTo, t_var_spec_list *var_spec_list)
{
	/* TODO: check decl does not already exist, use a structure that is sorted */
    int i;
    for (i = 0; i < var_spec_list->length; i++)
    {
        t_var_spec *varspec = &var_spec_list->var_specs[i];
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
            t_var_decl *entry = &symbol_table[numSymbols++];
            entry->vartype = var_type;
            entry->relativeTo = relativeTo;
            entry->varspec.name = _strdup(varspec->name);
            entry->varspec.displacement = varspec->displacement;
        }
    }
}

t_var_decl *find_declaration(char *name)
{
	int i;
	t_var_decl *result = NULL;
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

void process_instruction(unsigned int cr, unsigned int f, t_operand *operand)
{
	unsigned int instruction;
	unsigned int k = 0;
	t_int64 n = 0;

	if (operand->operand_type == OPERAND_LITERAL)
	{
		k = 0;
		n = operand->literal.signed_val;
	}
	else
	{
		
		if (operand->var_decl != NULL)
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


	if (n > -65 && n < 64)
	{
		instruction |= (n & 0x3F);
		emit(instruction);
	}
	else
	{
		yyerror("can't do big operands yet");
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

static void emit(unsigned int word)
{
	printf("%04X\n", word);
}
