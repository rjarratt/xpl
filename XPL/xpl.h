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
#define MAX_LABELS 100
#define MAX_VAR_SPECS 16

typedef signed __int64          t_int64;
typedef unsigned __int64        t_uint64;

typedef enum VAR_TYPE
{
    V32,
    V64,
    VV
} var_type_t;

typedef enum VAR_RELATIVE_TO
{
    NB,
    XNB,
    SF,
    ZERO,
    STK
} var_relative_to_t;

typedef struct VAR_SPEC
{
    char *name;
    int displacement;
} var_spec_t;

typedef struct VAR_SPEC_LIST
{
    int length;
    var_spec_t var_specs[MAX_VAR_SPECS];
} var_spec_list_t;

typedef struct VAR_DECL
{
    var_type_t vartype;
    var_relative_to_t relativeTo;
    var_spec_t varspec;
} var_decl_t;

typedef struct LABEL_ENTRY
{
	char *name;
	unsigned int location;
} label_entry_t;

typedef enum
{
	OPERAND_LITERAL,
	OPERAND_VARIABLE
} operand_type_t;

typedef enum
{
	LITERAL_SIGNED_6_BIT,
	LITERAL_UNSIGNED_16_BIT,
	LITERAL_SIGNED_16_BIT,
	LITERAL_UNSIGNED_32_BIT,
	LITERAL_SIGNED_32_BIT,
	LITERAL_UNSIGNED_64_BIT,
	LITERAL_SIGNED_64_BIT
} literal_type_t;

typedef struct LITERAL
{
	literal_type_t literal_type;
	union
	{
		t_uint64 unsigned_val;
		t_int64 signed_val;
	};
} literal_t;

typedef struct OPERAND
{
	operand_type_t operand_type;
	union
	{
		var_decl_t *var_decl;
		literal_t literal;
	};
} operand_t;

typedef struct INSTRUCTION
{
	unsigned int cr;
	unsigned int f;
} instruction_t;

void yyerror(char *msg);
void init_var_spec_list(var_spec_list_t *var_spec_list);
void add_var_spec_list(var_spec_list_t *var_spec_list, var_spec_t *var_spec);
void add_declaration(var_type_t var_type, var_relative_to_t relativeTo, var_spec_list_t *var_spec_list);
var_decl_t *find_declaration(char *name);
void add_label(char *name);
int find_label(char *name, int distance, operand_t *operand);
void process_instruction(unsigned int cr, unsigned int f, operand_t *operand);