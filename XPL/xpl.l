/* xpl.l: MU5 XPL cross-compiler Lex analyzer

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

%option noyywrap

%{
#include "xpl.h"
#include "xpl.tab.h"

%}

NAME    [A-Z][A-Z0-9\.]*
INTEGER [0-9]+

%%
\*SEGMENT          { return T_SEGMENT; }
\*END\ OF\ SEGMENT { return T_ENDOFSEGMENT; }
PROC               { return T_PROC; }
BEGIN              { return T_BEGIN; }
END                { return T_END; }
\*LINE             { return T_LINE; }

,                  { return T_COMMA; }
:                  { return T_COLON; }
\/                 { return T_SLASH; }
\(                 { return T_L_BR; }
\)                 { return T_R_BR; }
\[                 { return T_L_SQ; }
\]                 { return T_R_SQ; }
V32                { return T_V32; }
V64                { return T_V64; }
VV                 { return T_VV; }
AFL                { return T_A; }
A                  { return T_A; }
AU                 { return T_AU; }
AOD                { return T_AOD; }
D                  { return T_D; }
DO                 { return T_DO; }
XD                 { return T_XD; }
XDO                { return T_XDO; }
DB                 { return T_DB; }
XDB                { return T_XDB; }
MS                 { return T_MS; }
SN                 { return T_SN; }
DL                 { return T_DL; }
SPM                { return T_SPM; }
MOD                { return T_MOD; }
RMOD               { return T_RMOD; }
SMOD               { return T_SMOD; }
XMOD               { return T_XMOD; }
MDR                { return T_MDR; }
XCHK               { return T_XCHK; }
BMVE               { return T_BMVE; }
BMVB               { return T_BMVB; }
BCMP               { return T_BCMP; }
BLGC               { return T_BLGC; }
BSCN               { return T_BSCN; }
SMVE               { return T_SMVE; }
SMVB               { return T_SMVB; }
SCMP               { return T_SCMP; }
SLGC               { return T_SLGC; }
SMVF               { return T_SMVF; }
TALU               { return T_TALU; }
TCHK               { return T_TCHK; }
TRNS               { return T_TRNS; }
B                  { return T_B; }
X                  { return T_X; }
XS                 { return T_XS; }
NB                 { return T_NB; }
XNB                { return T_XNB; }
SF                 { return T_SF; }
STK                { return T_STK; }
=NB\+              { return T_LOAD_NB_ADD; }
=SF\+              { return T_LOAD_SF_ADD; }
=                  { return T_LOAD; }
='                 { return T_LOAD_DEC; }
\*=                { return T_STACK_LOAD; }
=>                 { return T_STORE; }
\+                 { return T_PLUS; }
\-                 { return T_MINUS; }
\*                 { return T_MUL; }
\-\/=              { return T_NEQV; }
V                  { return T_OR; }
&                  { return T_AND; }
\<=                { return T_SHIFT; }
-:                 { return T_RSUB; }
COMP               { return T_COMP; }
CINC               { return T_CINC; }
CONV               { return T_CONV; }
\/:                { return T_RDIV; }

\[B\]              { return T_B_REL; }
\[0\]              { return T_0_REL; }

STACK              { return T_STACK; }

IF                 { return T_IF; }
=0                 { return T_EQ; }
\/=0               { return T_NE; }
\<0                { return T_LT; }
=\<0               { return T_LE; }
\>0                { return T_GT; }
\>=0               { return T_GE; }
OV                 { return T_OV; }
BN                 { return T_BN; }
\-\>               { return T_RJUMP; }
RETURN             { return T_RETURN; }
EXIT               { return T_EXIT; }
JUMP               { return T_JUMP; }
XJUMP              { return T_XJUMP; }
STKLINK            { return T_STKLINK; }
SETLINK            { return T_SETLINK; }
CALL               { return T_CALL; }
ACALL              { return T_ACALL; }

DATAVEC            { return T_DATAVEC; }
DATASTR            { return T_DATASTR; }

\".*\"             { yylval.stringval = _strdup(yytext); return T_CHARACTER_STRING; }
{NAME}             { yylval.nameval = _strdup(yytext); return T_NAME; }
{INTEGER}          { yylval.unsignedval = atoi(yytext); return T_INTEGER; }
%[0-9A-F]+(\([0-9]+\)[0-9A-F]*)*  { yylval.unsignedval = scan_hex_digits(yytext + 1); return T_HEX_DIGITS; }
\:\:.*\n           {  yylineno++; return T_COMMENT; }
\n                 { yylineno++; return T_NL;}
. ;
%%

/*
int main()
{
    yylex();
}*/