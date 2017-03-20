/* xpl.y: MU5 XPL cross-compiler Yacc syntax analyzer

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

%token T_NL
%token T_COMMA
%token T_COLON
%token T_SLASH
%token <unsignedval> T_HEX_DIGITS
%token T_SEGMENT
%token T_ENDOFSEGMENT
%token T_BEGIN
%token T_END
%token T_COMMENT
%token T_V32
%token T_V64
%token T_VV
%token <nameval> T_NAME
%token <unsignedval> T_INTEGER
%token T_D
%token T_DO
%token T_XD
%token T_XDO
%token T_DB
%token T_XDB
%token T_MOD
%token T_RMOD
%token T_SMOD
%token T_XMOD
%token T_A
%token T_AU
%token T_B
%token T_NB
%token T_XNB
%token T_SF
%token T_STK
%token T_LOAD_NB_ADD
%token T_LOAD_SF_ADD
%token T_LOAD
%token T_LOAD_DEC
%token T_STACK_LOAD
%token T_STORE
%token T_PLUS
%token T_MINUS
%token T_MUL
%token T_NEQV
%token T_OR
%token T_AND
%token T_SHIFT
%token T_RSUB
%token T_COMP
%token T_CINC
%token T_CONV
%token T_RDIV
%token T_B_REL
%token T_0_REL
%token T_STACK
%token T_RJUMP

%type <signedval> displacement
%type <vartype> var_type
%type <varrelativeto> var_rel
%type <varspec> var_spec
%type <varspeclist> var_spec_list
%type <operand> operand
%type <operand> simple_operand
%type <sign> sign
%type <literal> literal
%type <literal> decimal
%type <f> b_operator
%type <instruction> b_ord
%type <f> a_operator
%type <f> au_operator
%type <instruction> a_ord
%type <f> sts
%type <f> org
%type <f> nb_ord
%type <f> sf_ord
%type <instruction> fn_1
%type <instruction> fn_2
%type <distance> jump_spec

%{
#include <stdio.h>
#include "xpl.h"

extern int yylex();
extern char *yytext;
extern int yylineno;

%}

%union
{
    unsigned int f;
    t_uint64 unsignedval;
    t_int64 signedval;
	int distance;
    char * nameval;
    var_type_t vartype;
    var_relative_to_t varrelativeto;
    var_spec_t varspec;
    var_spec_list_t varspeclist;
    t_int64 sign;
	literal_t literal;
	operand_t operand;
	instruction_t instruction;
}

%%
program_of_a_segment: T_SEGMENT T_INTEGER T_NL T_BEGIN  T_NL program T_END T_NL T_ENDOFSEGMENT T_NL
program:
  statement
| program statement;

statement:
  label
| label sep
| declarative sep
| instruction sep
| sep;

label: T_NAME T_COLON { add_label($1); }

declarative:
  var_dec;

var_dec: var_type T_SLASH var_rel var_spec_list { add_declaration($1, $3, &$4); }
var_type: T_V32 { $$=V32; } | T_V64 { $$ = V64; } | T_VV { $$ = VV; }
var_rel:
  T_NB { $$ = NB; }
| T_XNB { $$ = XNB; }
| T_SF { $$ =SF; }
| T_INTEGER { if ($1 != 0) yyerror("invalid relative-to"); $$ = ZERO; }
| T_STK { $$ = STK; }
var_spec_list: var_spec { init_var_spec_list(&$$); add_var_spec_list(&$$, &$1); } | var_spec_list T_COMMA var_spec  { add_var_spec_list(&$$, &$3); }
var_spec: T_NAME T_COLON displacement { $$.name = $1; $$.displacement = (int)$3; }
displacement:
  T_MINUS T_INTEGER         { $$ = 0 - $2; }
| T_INTEGER                 { $$ = $1; }
| T_HEX_DIGITS              { $$ = $1; }

instruction:
  comput
| sts
| org
| condit

comput:
  b_ord operand       { process_instruction($1.cr, $1.f, &$2); }
| a_ord operand       { process_instruction($1.cr, $1.f, &$2); }

b_ord: T_B b_operator       { $$.cr = 1; $$.f = $2; }
b_operator:
  T_LOAD                    { $$ = 0; }
| T_LOAD_DEC                { $$ = 1; }
| T_STACK_LOAD              { $$ = 2; }
| T_STORE	                { $$ = 3; }
| T_PLUS	                { $$ = 4; }
| T_MINUS	                { $$ = 5; }
| T_MUL		                { $$ = 6; }
| T_SLASH                   { $$ = 7; }
| T_NEQV	                { $$ = 8; }
| T_OR		                { $$ = 9; }
| T_SHIFT	                { $$ = 10; }
| T_AND		                { $$ = 11; }
| T_RSUB	                { $$ = 12; }
| T_COMP	                { $$ = 13; }
| T_CINC	                { $$ = 14; }
| T_RDIV	                { $$ = 15; }

a_ord:
  T_A a_operator       { $$.cr = 7; $$.f = $2; }
| T_AU au_operator     { $$.cr = 5; $$.f = $2; }

a_operator:
  T_LOAD                    { $$ = 0; }
| T_LOAD_DEC                { $$ = 1; }
| T_STACK_LOAD              { $$ = 2; }
| T_STORE	                { $$ = 3; }
| T_PLUS	                { $$ = 4; }
| T_MINUS	                { $$ = 5; }
| T_MUL		                { $$ = 6; }
| T_SLASH                   { $$ = 7; }
| T_NEQV	                { $$ = 8; }
| T_OR		                { $$ = 9; }
| T_SHIFT	                { $$ = 10; }
| T_AND		                { $$ = 11; }
| T_RSUB	                { $$ = 12; }
| T_COMP	                { $$ = 13; }
| T_CONV	                { $$ = 14; }
| T_RDIV	                { $$ = 15; }

au_operator:
| T_PLUS	                { $$ = 4; }
| T_MINUS	                { $$ = 5; }
| T_MUL		                { $$ = 6; }
| T_SLASH                   { $$ = 7; }
| T_NEQV	                { $$ = 8; }
| T_OR		                { $$ = 9; }
| T_SHIFT	                { $$ = 10; }
| T_AND		                { $$ = 11; }
| T_RSUB	                { $$ = 12; }
| T_COMP	                { $$ = 13; }
| T_RDIV	                { $$ = 15; }

org:
  nb_ord operand             { process_instruction(0, $1, &$2); }
| sf_ord operand             { process_instruction(0, $1, &$2); }

nb_ord:
  T_NB T_LOAD                { $$ = 28; }
| T_NB T_LOAD_SF_ADD         { $$ = 29; }
| T_NB T_PLUS                { $$ = 30; }

sf_ord:
  T_SF T_LOAD                { $$ = 24; }
| T_SF T_PLUS                { $$ = 25; }
| T_SF T_LOAD_NB_ADD         { $$ = 26; }

sts:
  fn_1 operand               { process_instruction($1.cr, $1.f, &$2); }
| fn_2 simple_operand        { process_instruction($1.cr, $1.f, &$2); }

fn_1:
  T_XDO T_LOAD               { $$.cr = 2; $$.f = 0; }
| T_XD T_LOAD                { $$.cr = 2; $$.f = 1; }
| T_STACK                    { $$.cr = 2; $$.f = 2; }
| T_DO T_LOAD                { $$.cr = 3; $$.f = 0; }
| T_D T_LOAD                 { $$.cr = 3; $$.f = 1; }
| T_D T_STACK_LOAD           { $$.cr = 3; $$.f = 2; }

fn_2:
  T_XD T_STORE               { $$.cr = 2; $$.f = 3; }
| T_XDB T_STORE              { $$.cr = 2; $$.f = 4; }
| T_XMOD                     { $$.cr = 2; $$.f = 7; }
| T_D T_STORE                { $$.cr = 3; $$.f = 3; }
| T_DB T_STORE               { $$.cr = 3; $$.f = 4; }
| T_MOD                      { $$.cr = 3; $$.f = 6; }

condit: jump_spec T_NAME     { operand_t operand; find_label($2, $1, &operand); process_instruction(0, 0, &operand); }
jump_spec:
  T_PLUS T_RJUMP             { $$ = 1; }
| T_MINUS T_RJUMP            { $$ = -1; }
| T_RJUMP                    { $$ = 0; }

operand:
  simple_operand
| T_NAME T_B_REL { $$.operand_type = OPERAND_VARIABLE; $$.var_decl = find_declaration($1); }
| T_NAME T_0_REL { $$.operand_type = OPERAND_VARIABLE; $$.var_decl = find_declaration($1); }

simple_operand:
  T_NAME                    { $$.operand_type = OPERAND_VARIABLE; $$.var_decl = find_declaration($1); }
| literal                   { $$.operand_type = OPERAND_LITERAL; $$.literal = $1; }

literal:
  decimal
| T_HEX_DIGITS              { $$.literal_type = LITERAL_UNSIGNED_16_BIT; $$.unsigned_val = $1; }

decimal:
  sign T_INTEGER            { $$.literal_type = LITERAL_SIGNED_6_BIT; $$.signed_val = $1 * $2; /* TODO: can't express largest negative number */ }
| T_INTEGER                 { $$.literal_type = LITERAL_UNSIGNED_16_BIT; $$.unsigned_val = $1; }

sign: T_PLUS { $$ = 1; } | T_MINUS { $$ = -1; } /* TODO: can't express largest negative number */

sep: T_NL | T_COMMENT;
%%

extern FILE *yyin;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: xpl [infile]\n");
    }
    else
    {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL)
        {
            fprintf(stderr, "cannot open %s\n", argv[1]);
        }
        else
        {
            do
            {
                yyparse();
            }
            while (!feof(yyin));
        }
    }
}
