/* xpl.c: MU5 XPL cross-compiler routines

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

#include <stdio.h>
#include <string.h>
#include "xpl.h"

#define MAX_SYMBOLS 100

extern char *yytext;
extern int yylineno;

static t_var_decl SymbolTable[MAX_SYMBOLS];
static int numSymbols = 0;

void yyerror(char *msg)
{
    fprintf(stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
}

void add_declaration(t_var_type var_type, t_var_relative_to relativeTo, t_var_spec *varspec)
{
    if (relativeTo == STK && varspec->displacement != 0)
    {
        yyerror("displacement must be zero");
    }

    if (numSymbols >= MAX_SYMBOLS)
    {
        yyerror("symbol table full");
    }
    else
    {
        t_var_decl *entry = &SymbolTable[numSymbols++];
        entry->vartype = var_type;
        entry->relativeTo = relativeTo;
        entry->varspec.name = _strdup(varspec->name);
        entry->varspec.displacement = varspec->displacement;
    }
}
