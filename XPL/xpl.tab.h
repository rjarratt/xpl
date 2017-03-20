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
     T_COMMA = 259,
     T_COLON = 260,
     T_SLASH = 261,
     T_HEX_DIGITS = 262,
     T_SEGMENT = 263,
     T_ENDOFSEGMENT = 264,
     T_BEGIN = 265,
     T_END = 266,
     T_COMMENT = 267,
     T_V32 = 268,
     T_V64 = 269,
     T_VV = 270,
     T_NAME = 271,
     T_INTEGER = 272,
     T_D = 273,
     T_DO = 274,
     T_XD = 275,
     T_XDO = 276,
     T_DB = 277,
     T_XDB = 278,
     T_MOD = 279,
     T_RMOD = 280,
     T_SMOD = 281,
     T_XMOD = 282,
     T_A = 283,
     T_AU = 284,
     T_AOD = 285,
     T_B = 286,
     T_NB = 287,
     T_XNB = 288,
     T_SF = 289,
     T_STK = 290,
     T_LOAD_NB_ADD = 291,
     T_LOAD_SF_ADD = 292,
     T_LOAD = 293,
     T_LOAD_DEC = 294,
     T_STACK_LOAD = 295,
     T_STORE = 296,
     T_PLUS = 297,
     T_MINUS = 298,
     T_MUL = 299,
     T_NEQV = 300,
     T_OR = 301,
     T_AND = 302,
     T_SHIFT = 303,
     T_RSUB = 304,
     T_COMP = 305,
     T_CINC = 306,
     T_CONV = 307,
     T_RDIV = 308,
     T_B_REL = 309,
     T_0_REL = 310,
     T_STACK = 311,
     T_RJUMP = 312
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 118 "xpl.y"

    unsigned int f;
    t_uint64 unsignedval;
    t_int64 signedval;
	int distance;
    char * nameval;
    var_type_t vartype;
    var_relative_to_t varrelativeto;
    var_spec_t varspec;
    var_spec_list_t varspeclist;
    t_int64 sign;
	literal_t literal;
	operand_t operand;
	instruction_t instruction;


/* Line 2058 of yacc.c  */
#line 131 "xpl.tab.h"
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
