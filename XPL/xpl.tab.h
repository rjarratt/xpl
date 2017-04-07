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
     T_L_BR = 262,
     T_R_BR = 263,
     T_L_SQ = 264,
     T_R_SQ = 265,
     T_HEX_DIGITS = 266,
     T_SEGMENT = 267,
     T_ENDOFSEGMENT = 268,
     T_BEGIN = 269,
     T_END = 270,
     T_COMMENT = 271,
     T_V32 = 272,
     T_V64 = 273,
     T_VV = 274,
     T_NAME = 275,
     T_INTEGER = 276,
     T_CHARACTER_STRING = 277,
     T_D = 278,
     T_DO = 279,
     T_XD = 280,
     T_XDO = 281,
     T_DB = 282,
     T_XDB = 283,
     T_MOD = 284,
     T_RMOD = 285,
     T_SMOD = 286,
     T_XMOD = 287,
     T_MDR = 288,
     T_XCHK = 289,
     T_BMVE = 290,
     T_BMVB = 291,
     T_BCMP = 292,
     T_BLGC = 293,
     T_BSCN = 294,
     T_SMVE = 295,
     T_SMVB = 296,
     T_SCMP = 297,
     T_SLGC = 298,
     T_SMVF = 299,
     T_TALU = 300,
     T_TCHK = 301,
     T_TRNS = 302,
     T_A = 303,
     T_AU = 304,
     T_AOD = 305,
     T_B = 306,
     T_NB = 307,
     T_XNB = 308,
     T_SF = 309,
     T_STK = 310,
     T_LOAD_NB_ADD = 311,
     T_LOAD_SF_ADD = 312,
     T_LOAD = 313,
     T_LOAD_DEC = 314,
     T_STACK_LOAD = 315,
     T_STORE = 316,
     T_PLUS = 317,
     T_MINUS = 318,
     T_MUL = 319,
     T_NEQV = 320,
     T_OR = 321,
     T_AND = 322,
     T_SHIFT = 323,
     T_RSUB = 324,
     T_COMP = 325,
     T_CINC = 326,
     T_CONV = 327,
     T_RDIV = 328,
     T_B_REL = 329,
     T_0_REL = 330,
     T_STACK = 331,
     T_IF = 332,
     T_EQ = 333,
     T_NE = 334,
     T_LT = 335,
     T_LE = 336,
     T_GT = 337,
     T_GE = 338,
     T_OV = 339,
     T_BN = 340,
     T_RJUMP = 341,
     T_DATAVEC = 342,
     T_DATASTR = 343
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 151 "xpl.y"

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
#line 163 "xpl.tab.h"
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
