/* xpl.h: MU5 XPL cross-compiler definitions

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

#pragma once

typedef signed __int64          t_int64;
typedef unsigned __int64        t_uint64;

typedef enum VAR_TYPE
{
    V32,
    V64,
    VV
} t_var_type;

typedef enum VAR_RELATIVE_TO
{
    NB,
    XNB,
    SF,
    ZERO,
    STK
} t_var_relative_to;

typedef struct VAR_SPEC
{
    char *name;
    t_int64 displacement;
} t_var_spec;

void yyerror(char *msg);
void add_declaration(t_var_type var_type, t_var_relative_to relativeTo, t_var_spec *varspec);