%option noyywrap

%{
#include "y.tab.h"

%}

%%
\*SEGMENT { return SEGMENT; }
\*END\ OF\ SEGMENT { return ENDOFSEGMENT; }
BEGIN { return BEGIN; }
END { return END; }
[0-9]+ {return DECIMAL; }
\:\:.*\n /* comment */ ;
\n { return NL;}
. ;
%%

/*
int main()
{
    yylex();
}*/