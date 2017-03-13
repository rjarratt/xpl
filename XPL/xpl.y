%token NL SEGMENT ENDOFSEGMENT BEGIN END DECIMAL

%{
#include <stdio.h>

extern int yylex();

void yyerror(char *s)
{
    fprintf(stderr, "%s\n", s);
}

%}

%%
program_of_a_segment: SEGMENT DECIMAL NL BEGIN  NL program NL END NL ENDOFSEGMENT NL
program: statement
    | program statement
statement: DECIMAL { printf("stmt\n"); }
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
