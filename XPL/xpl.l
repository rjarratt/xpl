%option noyywrap

%{
#include "xpl.h"
#include "xpl.tab.h"

%}

NAME    [A-Z][A-Z0-9\.]*
DECIMAL [0-9]+

%%
\*SEGMENT          { return T_SEGMENT; }
\*END\ OF\ SEGMENT { return T_ENDOFSEGMENT; }
BEGIN              { return T_BEGIN; }
END                { return T_END; }

B                  { return T_B; }
NB                 { return T_NB; }
SF                 { return T_SF; }
=NB\+              { return T_LOAD_NB_ADD; }
=SF\+              { return T_LOAD_SF_ADD; }
=                  { return T_LOAD; }
='                 { return T_LOAD_DEC; }
\*=                { return T_STACK_LOAD; }
=>                 { return T_STORE; }
\+                 { return T_ADD; }
\-                 { return T_SUB; }
\*                 { return T_MUL; }
\-/=               { return T_NEQV; }
V                  { return T_OR; }
&                  { return T_AND; }
\<=                { return T_SHIFT; }
-:                 { return T_RSUB; }
COMP               { return T_COMP; }
CINC               { return T_CINC; }

\[B\]              { return T_B_REL; }
\[0\]              { return T_0_REL; }

{NAME}\:           { return T_LABEL; }
{NAME}             { return T_NAME; }
{DECIMAL}          { yylval.uval = atoi(yytext); return T_DECIMAL; }
\:\:.*\n           { return T_COMMENT; }
\n                 { return T_NL;}
. ;
%%

/*
int main()
{
    yylex();
}*/