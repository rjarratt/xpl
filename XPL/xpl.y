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

extern int yylex();
extern char *yytext;
extern int yylineno;

void yyerror(char *msg)
{
    fprintf(stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
}

%}

%%
program_of_a_segment: T_SEGMENT T_DECIMAL T_NL T_BEGIN  T_NL program T_END T_NL T_ENDOFSEGMENT T_NL
program:
  statement
| program statement;

statement:
  T_LABEL { printf("label %s\n", yytext); }
| T_LABEL sep { printf("label sep %s\n", yytext); }
| instruction sep
| sep;

instruction: comput operand { printf("order %s\n", yytext); }

comput: b_ord;
b_ord: T_B b_operator;
b_operator:
  T_LOAD
| T_LOAD_DEC
| T_STACK_LOAD
| T_STORE
| T_ADD
| T_SUB
| T_MUL
| T_NEQV
| T_OR
| T_AND
| T_SHIFT
| T_RSUB
| T_COMP
| T_CINC;

operand: simple_operand | T_NAME T_B_REL |  T_NAME T_0_REL;
simple_operand: literal;
literal: T_DECIMAL;
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
