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
%token T_RDIV
%token T_B_REL
%token T_0_REL
%token T_STACK

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
%type <f> b_ord
%type <f> sts
%type <f> org
%type <f> nb_ord
%type <f> sf_ord
%type <instruction> fn_1
%type <instruction> fn_2

%{
#include <stdio.h>
#include "xpl.h"

extern int yylex();
extern char *yytext;
extern int yylineno;

unsigned int instructionNum;

%}

%union
{
    unsigned int f;
    t_uint64 unsignedval;
    t_int64 signedval;
    char * nameval;
    t_var_type vartype;
    t_var_relative_to varrelativeto;
    t_var_spec varspec;
    t_var_spec_list varspeclist;
    t_int64 sign;
	t_literal literal;
	t_operand operand;
	t_instruction instruction;
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
| instruction sep { instructionNum++; }
| sep;

label: T_NAME T_COLON { printf("Label %s at instruction %d\n", $1, instructionNum); }

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
var_spec: T_NAME T_COLON displacement { $$.name = $1; $$.displacement = $3; }
displacement:
  T_MINUS T_INTEGER         { $$ = 0 - $2; }
| T_INTEGER                 { $$ = $1; }
| T_HEX_DIGITS              { $$ = $1; }

instruction:
  comput
| sts
| org

comput: b_ord operand       { process_instruction(1, $1, &$2); }
b_ord: T_B b_operator       { $$ = $2; }
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
  T_STACK                    { $$.cr = 2; $$.f = 2; }

fn_2:
  T_D T_STORE                { $$.cr = 3; $$.f = 3; }

operand:
  simple_operand
| T_NAME T_B_REL { $$.operand_type = OPERAND_VARIABLE; $$.var_decl = find_declaration($1); }
| T_NAME T_0_REL { $$.operand_type = OPERAND_VARIABLE; $$.var_decl = find_declaration($1); }

simple_operand:
  T_NAME                    { $$.operand_type = OPERAND_VARIABLE; $$.var_decl = find_declaration($1); }
| literal                   { $$.operand_type = OPERAND_LITERAL; $$.literal = $1; }

literal:
  decimal
| T_HEX_DIGITS              { $$.literal_type = LITERAL_UNSIGNED; $$.unsigned_val = $1; }

decimal:
  sign T_INTEGER            { $$.literal_type = LITERAL_SIGNED; $$.signed_val = $1 * $2; /* TODO: can't express largest negative number */ }
| T_INTEGER                 { $$.literal_type = LITERAL_UNSIGNED; $$.unsigned_val = $1; }

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
