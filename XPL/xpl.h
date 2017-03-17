/* xpl.h: MU5 XPL cross-compiler definitions

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

#pragma once

#define MAX_SYMBOLS 100
#define MAX_VAR_SPECS 16

typedef signed __int64          t_int64;
typedef unsigned __int64        t_uint64;

typedef enum VAR_TYPE
{
    V32,
    V64,
    VV
} t_var_type;

typedef enum VAR_RELATIVE_TO
{
    NB,
    XNB,
    SF,
    ZERO,
    STK
} t_var_relative_to;

typedef struct VAR_SPEC
{
    char *name;
    t_int64 displacement;
} t_var_spec;

typedef struct VAR_SPEC_LIST
{
    int length;
    t_var_spec var_specs[MAX_VAR_SPECS];
} t_var_spec_list;

typedef struct VAR_DECL
{
    t_var_type vartype;
    t_var_relative_to relativeTo;
    t_var_spec varspec;
} t_var_decl;

typedef enum
{
	OPERAND_LITERAL,
	OPERAND_VARIABLE
} t_operand_type;

typedef struct OPERAND
{
	t_operand_type operand_type;
	union
	{
		t_var_decl *var_decl;
		t_uint64 unsignedLiteral;
	};
} t_operand;

typedef struct INSTRUCTION
{
	unsigned int cr;
	unsigned int f;
	t_operand operand;
} t_instruction;

void yyerror(char *msg);
void init_var_spec_list(t_var_spec_list *var_spec_list);
void add_var_spec_list(t_var_spec_list *var_spec_list, t_var_spec *var_spec);
void add_declaration(t_var_type var_type, t_var_relative_to relativeTo, t_var_spec_list *var_spec_list);
t_var_decl *find_declaration(char *name);
void process_instruction(unsigned int cr, unsigned int f, t_operand *operand);