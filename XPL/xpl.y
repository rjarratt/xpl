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
%token T_B
%token T_NB
%token T_XNB
%token T_SF
%token T_ZERO
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
%token T_B_REL
%token T_0_REL

%type <signedval> displacement
%type <vartype> var_type
%type <varrelativeto> var_rel
%type <varspec> var_spec

%{
#include <stdio.h>
#include "xpl.h"

extern int yylex();
extern char *yytext;
extern int yylineno;

unsigned int instructionNum;
unsigned int cr;
unsigned int f;
unsigned int k;
t_uint64 n;

%}

%union
{
    t_uint64 unsignedval;
    t_int64 signedval;
    char * nameval;
    t_var_type vartype;
    t_var_relative_to varrelativeto;
    t_var_spec varspec;
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
| instruction sep { printf("order cr=%u, f=%u, k=%d, n=%llu\n", cr, f, k, n); instructionNum++; }
| sep;

label: T_NAME T_COLON { printf("Label %s at instruction %d\n", $1, instructionNum); }

declarative:
  var_dec;

var_dec: var_type T_SLASH var_rel var_spec { add_declaration($1, $3, &$4); }
var_type: T_V32 { $$=V32; } | T_V64 { $$ = V64; } | T_VV { $$ = VV; }
var_rel: T_NB { $$ = NB; } | T_XNB { $$ = XNB; } | T_SF { $$ =SF; } | T_ZERO { $$ = ZERO; } | T_STK { $$ = STK; }
var_spec: T_NAME T_COLON displacement { $$.name = $1; $$.displacement = $3; }
displacement:
  T_MINUS T_INTEGER         { $$ = 0 - $2; }
| T_INTEGER                 { $$ = $1; }
| T_HEX_DIGITS              { $$ = $1; }

instruction:
  comput                    
| org                       { cr = 0; }

comput: b_ord operand       { cr = 1; }
b_ord: T_B b_operator;
b_operator:
  T_LOAD                    { f = 0; }
| T_LOAD_DEC                { f = 1; }
| T_STACK_LOAD              { f = 2; }
| T_STORE	                { f = 3; }
| T_PLUS	                { f = 4; }
| T_MINUS	                { f = 5; }
| T_MUL		                { f = 6; }
| T_NEQV	                { f = 8; }
| T_OR		                { f = 9; }
| T_SHIFT	                { f = 10; }
| T_AND		                { f = 11; }
| T_RSUB	                { f = 12; }
| T_COMP	                { f = 13; }
| T_CINC	                { f = 14; }

org:
  nb_ord
| sf_ord;

nb_ord:
  T_NB T_LOAD operand        { f = 24; }
| T_NB T_PLUS operand        { f = 25; }
| T_NB T_LOAD_SF_ADD operand { f = 26; }

sf_ord:
  T_SF T_LOAD operand        { f = 28; }
| T_SF T_LOAD_NB_ADD operand { f = 29; }

operand:
  simple_operand
| T_NAME T_B_REL
| T_NAME T_0_REL;

simple_operand:
  T_NAME                    { k = 255; }
| literal                   { k = 0; }

literal: decimal | T_HEX_DIGITS;
decimal:
  sign T_INTEGER            { n = yylval.unsignedval; }
| T_INTEGER                 { n = yylval.unsignedval; }
sign: T_PLUS | T_MINUS;

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
