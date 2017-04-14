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
#define MAX_SEGMENTS 100
#define MAX_VAR_SPECS 16
#define MAX_DATAVEC_ITEMS 50 /* max items on a line in a DATAVEC */

#define PASS_GET_FORWARDS 1
#define PASS_CALC_SIZES 2
#define PASS_CODE_GEN 3

typedef signed __int64          t_int64;
typedef unsigned __int64        t_uint64;

typedef enum VAR_TYPE
{
    V32,
    V64,
    VV,
	DESCRIPTOR,
    IR
} var_type_t;

typedef enum DESCRIPTOR_TYPE
{
	GENERAL_VECTOR = 0,
	STRING_VECTOR = 1,
	ADDRESS_VECTOR = 2,
	MISC_VECTOR = 3
} descriptor_type_t;

typedef enum DESCRIPTOR_SIZE
{
    SIZE_0_BIT = -1,
	SIZE_1_BIT = 0,
	SIZE_4_BIT = 2,
	SIZE_8_BIT = 3,
	SIZE_16_BIT = 4,
	SIZE_32_BIT = 5,
	SIZE_64_BIT = 6,
} descriptor_size_t;

typedef enum VAR_RELATIVE_TO
{
	NOT_REL,
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

typedef struct SEGMENT
{
    unsigned int segment;
    unsigned int length;
} segment_t;

typedef struct LABEL_ENTRY
{
	char *name;
	unsigned int location;
} label_entry_t;

typedef enum
{
	OPERAND_LITERAL,
    OPERAND_VARIABLE,
    OPERAND_VARIABLE_B_REL,
    OPERAND_VARIABLE_0_REL
} operand_type_t;

/* the positive numbers relate directly to values of n' */
typedef enum
{
    LITERAL_SIGNED_1_BIT = -4,
    LITERAL_SIGNED_4_BIT = -3,
    LITERAL_SIGNED_6_BIT = -2,
    LITERAL_SIGNED_8_BIT = -1,
    LITERAL_SIGNED_16_BIT = 0,
	LITERAL_SIGNED_32_BIT = 1,
	LITERAL_SIGNED_64_BIT = 2,
    LITERAL_UNSIGNED_1_BIT = -8,
    LITERAL_UNSIGNED_4_BIT = -7,
    LITERAL_UNSIGNED_8_BIT = -6,
    LITERAL_UNSIGNED_16_BIT = 4,
	LITERAL_UNSIGNED_32_BIT = 5,
	LITERAL_UNSIGNED_64_BIT = 6,
} literal_type_t;

typedef enum
{
	JUMP_RELATIVE_SHORT,
	JUMP_RELATIVE_DEFAULT,
	JUMP_RELATIVE_LONG,
	JUMP_ABSOLUTE
} jump_type_t;

typedef struct LITERAL
{
	literal_type_t literal_type;
	union
	{
		t_uint64 unsigned_val;
		t_int64 signed_val;
	};
} literal_t;

typedef struct SYMBOL
{
	var_type_t vartype;
	var_relative_to_t relativeTo;
	char *name;
	t_uint64 value;
} symbol_t;

typedef struct OPERAND
{
	operand_type_t operand_type;
	union
	{
		symbol_t *symbol;
		literal_t literal;
	};
} operand_t;

typedef struct INSTRUCTION
{
	unsigned int cr;
	unsigned int f;
} instruction_t;

extern unsigned int segment;
extern int error_in_pass;
extern FILE *binary;
extern symbol_t b_symbol;
extern symbol_t bn_symbol;
extern symbol_t d_symbol;

t_uint64 scan_hex_digits(char *hex_digits);
void set_pass(int new_pass);
void yyerror(char *msg);
void start_segment(unsigned int segment_number);
void end_segment(void);
segment_t *get_segment(unsigned int segment_number);
void set_segment(unsigned int segment_number, unsigned int length);
void init_var_spec_list(var_spec_list_t *var_spec_list);
void add_var_spec_list(var_spec_list_t *var_spec_list, var_spec_t *var_spec);
void add_declaration(var_type_t var_type, var_relative_to_t relativeTo, var_spec_list_t *var_spec_list);
void add_symbol(var_type_t var_type, var_relative_to_t relativeTo, char *name, t_uint64 value);
symbol_t *find_symbol(char *name);
void add_label(char *name);
label_entry_t *find_label(char *name);
void set_operand_label_context(jump_type_t jump_type);
int set_operand_label(char *name, jump_type_t jump_type, operand_t *operand);
void set_operand(char *name, operand_t *operand);
literal_type_t get_literal_type(int sign, t_uint64 value);
void make_int_literal(int sign, t_uint64 value, literal_t *literal);
t_uint64 make_descriptor(descriptor_type_t type, descriptor_size_t size, unsigned char unscaled, unsigned char noboundcheck, unsigned int bound, unsigned int origin);
void process_instruction(unsigned int cr, unsigned int f, operand_t *operand);
t_uint64 process_text(char *name, char *string);
void process_datavec_start(t_uint64 size);
void process_datavec_literal(literal_t *literal);
void process_datavec_line_end();
t_uint64 process_datavec_end();
void process_datavec_line_repeat(unsigned int n);
void emit_instruction(unsigned char cr, unsigned char f, unsigned char k, unsigned char n);
void emit_extended_instruction(unsigned char cr, unsigned char f, unsigned char kp, unsigned char np);
