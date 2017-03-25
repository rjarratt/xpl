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
     T_CHARACTER_STRING = 273,
     T_D = 274,
     T_DO = 275,
     T_XD = 276,
     T_XDO = 277,
     T_DB = 278,
     T_XDB = 279,
     T_MOD = 280,
     T_RMOD = 281,
     T_SMOD = 282,
     T_XMOD = 283,
     T_MDR = 284,
     T_XCHK = 285,
     T_BMVE = 286,
     T_BMVB = 287,
     T_BCMP = 288,
     T_BLGC = 289,
     T_BSCN = 290,
     T_SMVE = 291,
     T_SMVB = 292,
     T_SCMP = 293,
     T_SLGC = 294,
     T_SMVF = 295,
     T_TALU = 296,
     T_TCHK = 297,
     T_TRNS = 298,
     T_A = 299,
     T_AU = 300,
     T_AOD = 301,
     T_B = 302,
     T_NB = 303,
     T_XNB = 304,
     T_SF = 305,
     T_STK = 306,
     T_LOAD_NB_ADD = 307,
     T_LOAD_SF_ADD = 308,
     T_LOAD = 309,
     T_LOAD_DEC = 310,
     T_STACK_LOAD = 311,
     T_STORE = 312,
     T_PLUS = 313,
     T_MINUS = 314,
     T_MUL = 315,
     T_NEQV = 316,
     T_OR = 317,
     T_AND = 318,
     T_SHIFT = 319,
     T_RSUB = 320,
     T_COMP = 321,
     T_CINC = 322,
     T_CONV = 323,
     T_RDIV = 324,
     T_B_REL = 325,
     T_0_REL = 326,
     T_STACK = 327,
     T_IF = 328,
     T_EQ = 329,
     T_NE = 330,
     T_LT = 331,
     T_LE = 332,
     T_GT = 333,
     T_GE = 334,
     T_OV = 335,
     T_BN = 336,
     T_RJUMP = 337,
     T_DATASTR = 338
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 145 "xpl.y"

    unsigned int f;
    t_uint64 unsignedval;
    t_int64 signedval;
	int distance;
    char * nameval;
	char *stringval;
    var_type_t vartype;
    var_relative_to_t varrelativeto;
    var_spec_t varspec;
    var_spec_list_t varspeclist;
    t_int64 sign;
	literal_t literal;
	operand_t operand;
	instruction_t instruction;


/* Line 2058 of yacc.c  */
#line 158 "xpl.tab.h"
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
