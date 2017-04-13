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
%token T_L_BR
%token T_R_BR
%token T_L_SQ
%token T_R_SQ
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
%token <stringval> T_CHARACTER_STRING
%token T_D
%token T_DO
%token T_XD
%token T_XDO
%token T_DB
%token T_XDB
%token T_MS
%token T_SN
%token T_DL
%token T_SPM
%token T_MOD
%token T_RMOD
%token T_SMOD
%token T_XMOD
%token T_MDR
%token T_XCHK
%token T_BMVE
%token T_BMVB
%token T_BCMP
%token T_BLGC
%token T_BSCN
%token T_SMVE
%token T_SMVB
%token T_SCMP
%token T_SLGC
%token T_SMVF
%token T_TALU
%token T_TCHK
%token T_TRNS
%token T_A
%token T_AU
%token T_AOD
%token T_B
%token T_X
%token T_XS
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
%token T_IF
%token T_EQ
%token T_NE
%token T_LT
%token T_LE
%token T_GT
%token T_GE
%token T_OV
%token T_BN
%token T_RJUMP
%token T_DATAVEC
%token T_DATASTR

%type <signedval> execute_seg_no
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
%type <f> x_operator
%type <instruction> x_ord
%type <f> a_operator
%type <f> au_operator
%type <instruction> a_ord
%type <f> sts
%type <f> org
%type <f> ms_ord
%type <f> sf_ord
%type <f> nb_ord
%type <f> xnb_ord
%type <f> misc_ord
%type <instruction> fn_1
%type <instruction> fn_2
%type <instruction> aod_ord
%type <distance> jump_spec
%type <f> cond
%type <f> b_fn

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
	char *stringval;
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
xpl_program: program_of_a_segment | program_of_a_segment xpl_program
program_of_a_segment: T_SEGMENT execute_seg_no  { start_segment((unsigned int)$2); } T_NL T_BEGIN  T_NL program T_END T_NL T_ENDOFSEGMENT T_NL { end_segment(); }
execute_seg_no: decimal { $$ = $1.signed_val; }
program:
  statement
| program statement;

statement:
  label
| label sep
| declarative sep
| instruction sep
| table sep
| text sep
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
| x_ord operand       { process_instruction($1.cr, $1.f, &$2); }
| a_ord operand       { process_instruction($1.cr, $1.f, &$2); }
| aod_ord operand     { process_instruction($1.cr, $1.f, &$2); }

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

x_ord:
  T_X x_operator       { $$.cr = 4; $$.f = $2; }
| T_XS x_operator      { $$.cr = 4; $$.f = $2; }

x_operator:
  T_LOAD                    { $$ = 0; }
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

aod_ord:
  T_AOD T_LOAD              { $$.cr = 5; $$.f = 0; }
| T_AOD T_STACK_LOAD        { $$.cr = 5; $$.f = 2; }
| T_AOD T_STORE             { $$.cr = 5; $$.f = 3; }
| T_AOD T_COMP              { $$.cr = 6; $$.f = 12; }

org:
  ms_ord operand             { process_instruction(0, $1, &$2); }
| sf_ord operand             { process_instruction(0, $1, &$2); }
| nb_ord operand             { process_instruction(0, $1, &$2); }
| xnb_ord operand            { process_instruction(0, $1, &$2); }
| misc_ord operand           { process_instruction(0, $1, &$2); }

ms_ord: T_MS T_LOAD          { $$ = 16; }
sf_ord:
  T_SF T_LOAD                { $$ = 24; }
| T_SF T_PLUS                { $$ = 25; }
| T_SF T_LOAD_NB_ADD         { $$ = 26; }

nb_ord:
  T_NB T_LOAD                { $$ = 28; }
| T_NB T_LOAD_SF_ADD         { $$ = 29; }
| T_NB T_PLUS                { $$ = 30; }

xnb_ord:
  T_XNB T_LOAD                { $$ = 20; }
| T_XNB T_PLUS                { $$ = 22; }

misc_ord:
  T_SN T_LOAD                 { $$ = 21; }
| T_DL T_LOAD                 { $$ = 17; }
| T_SPM T_LOAD                { $$ = 18; }

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
| T_MDR                      { $$.cr = 3; $$.f = 5; }
| T_XCHK                     { $$.cr = 2; $$.f = 5; }
| T_BMVE                     { $$.cr = 3; $$.f = 10; }
| T_BMVB                     { $$.cr = 3; $$.f = 9; }
| T_BCMP                     { $$.cr = 3; $$.f = 14; }
| T_BLGC                     { $$.cr = 3; $$.f = 8; }
| T_BSCN                     { $$.cr = 3; $$.f = 13; }
| T_SMVE                     { $$.cr = 2; $$.f = 10; } /* for HASE not real in MU5 */
| T_SMVB                     { $$.cr = 2; $$.f = 9; }
| T_SCMP                     { $$.cr = 2; $$.f = 14; }
| T_SLGC                     { $$.cr = 2; $$.f = 8; }
| T_SMVF                     { $$.cr = 2; $$.f = 11; }
| T_TALU                     { $$.cr = 2; $$.f = 12; }

condit:
  jump_spec T_NAME                   { operand_t operand; set_operand_label($2, $1, &operand); process_instruction(0, 0, &operand); }
| T_IF cond T_COMMA jump_spec T_NAME { operand_t operand; set_operand_label($5, $4, &operand); process_instruction(0, 32 + $2, &operand); }
| T_BN b_fn T_IF cond                { operand_t operand; operand.operand_type = OPERAND_LITERAL; make_int_literal(0, $2, &operand.literal);;process_instruction(0, 40 + $4, &operand); }
| T_BN b_fn operand                  { process_instruction(0, 48 + $2, &$3); }

jump_spec:
  T_PLUS T_RJUMP             { $$ = 1; }
| T_MINUS T_RJUMP            { $$ = -1; }
| T_RJUMP                    { $$ = 0; }

cond:
  T_EQ                       { $$ = 0; }
| T_NE                       { $$ = 1; }
| T_GE                       { $$ = 2; }
| T_LT                       { $$ = 3; }
| T_LE                       { $$ = 4; }
| T_GT                       { $$ = 5; }
| T_OV                       { $$ = 6; }
| T_BN                       { $$ = 7; }

b_fn:
  T_SLASH                    { $$ = 10; }
| T_LOAD                     { $$ = 3; }

operand:
  simple_operand
| T_D T_B_REL    { $$.operand_type = OPERAND_VARIABLE_B_REL; $$.symbol = &d_symbol; }
| T_NAME T_B_REL { $$.operand_type = OPERAND_VARIABLE_B_REL; $$.symbol = find_symbol($1); }
| T_D T_0_REL    { $$.operand_type = OPERAND_VARIABLE_0_REL; $$.symbol = &d_symbol; }
| T_NAME T_0_REL { $$.operand_type = OPERAND_VARIABLE_0_REL; $$.symbol = find_symbol($1); }

simple_operand:
  T_NAME                    { $$.operand_type = OPERAND_VARIABLE; $$.symbol = find_symbol($1); }
| T_B                       { $$.operand_type = OPERAND_VARIABLE; $$.symbol = &b_symbol; }
| T_BN                      { $$.operand_type = OPERAND_VARIABLE; $$.symbol = &bn_symbol; }
| literal                   { $$.operand_type = OPERAND_LITERAL; $$.literal = $1; }

literal:
  decimal
| T_HEX_DIGITS              { make_int_literal(0, $1, &$$); }

decimal:
  sign T_INTEGER            { make_int_literal((int)$1, $2, &$$); /* TODO: can't express largest negative number */ }
| T_INTEGER                 { make_int_literal(0, $1, &$$); }

sign: T_PLUS { $$ = 1; } | T_MINUS { $$ = -1; } /* TODO: can't express largest negative number */

table: T_DATAVEC T_NAME T_L_BR T_INTEGER T_R_BR T_NL { process_datavec_start($4); } lit_list T_END { t_uint64 d = process_datavec_end(); add_symbol(DESCRIPTOR, NOT_REL, $2, d);}
lit_list: lit_line T_NL | lit_line T_NL lit_list
lit_line: lit_items { process_datavec_line_end(); }
lit_items: literal { process_datavec_literal(&$1); } T_COMMA lit_repeat | literal { process_datavec_literal(&$1); }
lit_repeat: lit_items | T_L_SQ T_INTEGER T_R_SQ { process_datavec_line_repeat((unsigned int)$2);}
text: T_DATASTR T_NAME T_CHARACTER_STRING { t_uint64 d = process_text($2, $3); add_symbol(DESCRIPTOR, NOT_REL, $2, d); }

sep: T_NL | T_COMMENT;
%%

extern FILE *binary;
extern FILE *yyin;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "usage: xpl [infile] [outfile]\n");
    }
    else
    {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL)
        {
            fprintf(stderr, "cannot open %s\n", argv[1]);
        }

		binary = fopen(argv[2], "wb");
        if (yyin == NULL)
        {
            fprintf(stderr, "cannot open %s\n", argv[2]);
        }

        if (yyin != NULL && binary != NULL)
        {
            /* first pass picks up the forward declarations, but the operand sizes are unknown for forward declarations, so instruction locations will be incorrect */
		    set_pass(PASS_GET_FORWARDS);
            do
            {
                yyparse();
            }
            while (!feof(yyin));

            /* Second pass generates the right instructions as all the data types of forward declared items are now known, but byte origins of any forward declared
               descriptors will be unknown, so they will be incorrect in the symbol table at this point
            */
			if (!error_in_pass)
			{
			    rewind(yyin);
			    set_pass(PASS_CALC_SIZES);
                do
                {
                    yyparse();
                }
                while (!feof(yyin));
			}

            /* Third pass will run with forward declared descriptors having the right byte origin values.
            */
			if (!error_in_pass)
			{
			    rewind(yyin);
			    set_pass(PASS_CODE_GEN);
                do
                {
                    yyparse();
                }
                while (!feof(yyin));
			}

			fclose(binary);
        }
    }
}
