/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_XPL_TAB_H_INCLUDED
# define YY_YY_XPL_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_NL = 258,
     T_COLON = 259,
     T_SLASH = 260,
     T_HEX_DIGITS = 261,
     T_SEGMENT = 262,
     T_ENDOFSEGMENT = 263,
     T_BEGIN = 264,
     T_END = 265,
     T_COMMENT = 266,
     T_V32 = 267,
     T_V64 = 268,
     T_VV = 269,
     T_NAME = 270,
     T_INTEGER = 271,
     T_B = 272,
     T_NB = 273,
     T_XNB = 274,
     T_SF = 275,
     T_STK = 276,
     T_LOAD_NB_ADD = 277,
     T_LOAD_SF_ADD = 278,
     T_LOAD = 279,
     T_LOAD_DEC = 280,
     T_STACK_LOAD = 281,
     T_STORE = 282,
     T_PLUS = 283,
     T_MINUS = 284,
     T_MUL = 285,
     T_NEQV = 286,
     T_OR = 287,
     T_AND = 288,
     T_SHIFT = 289,
     T_RSUB = 290,
     T_COMP = 291,
     T_CINC = 292,
     T_B_REL = 293,
     T_0_REL = 294
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 87 "xpl.y"

    t_uint64 unsignedval;
    t_int64 signedval;
    char * nameval;
    t_var_type vartype;
    t_var_relative_to varrelativeto;
    t_var_spec varspec;


/* Line 2058 of yacc.c  */
#line 106 "xpl.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_XPL_TAB_H_INCLUDED  */
