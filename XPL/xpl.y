%token T_NL
%token T_SEGMENT
%token T_ENDOFSEGMENT
%token T_BEGIN
%token T_END
%token T_COMMENT
%token T_NAME
%token T_DECIMAL
%token T_LABEL
%token T_B
%token T_NB
%token T_SF
%token T_LOAD_NB_ADD
%token T_LOAD_SF_ADD
%token T_LOAD
%token T_LOAD_DEC
%token T_STACK_LOAD
%token T_STORE
%token T_ADD
%token T_SUB
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

%{
#include <stdio.h>
#include "xpl.h"

extern int yylex();
extern char *yytext;
extern int yylineno;

unsigned int cr;
unsigned int f;
unsigned int k;
t_uint64 n;

void yyerror(char *msg)
{
    fprintf(stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
}

%}

%union
{
    t_uint64 uval;
	char * sval;
}

%%
program_of_a_segment: T_SEGMENT T_DECIMAL T_NL T_BEGIN  T_NL program T_END T_NL T_ENDOFSEGMENT T_NL
program:
  statement
| program statement;

statement:
  T_LABEL
| T_LABEL sep
| instruction sep { printf("order cr=%u, f=%u, k=%d, n=%llu\n", cr, f, k, n); }
| sep;

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
| T_ADD		                { f = 4; }
| T_SUB		                { f = 5; }
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
| T_NB T_ADD operand         { f = 25; }
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

literal: T_DECIMAL          { n = yylval.uval; }

sep: T_NL | T_COMMENT;
%%

extern FILE *yyin;

int main()
{
    do
	{
	    yyparse();
	}
	while (!feof(yyin));
}
