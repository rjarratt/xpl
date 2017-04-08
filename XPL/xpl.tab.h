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
     T_MS = 284,
     T_MOD = 285,
     T_RMOD = 286,
     T_SMOD = 287,
     T_XMOD = 288,
     T_MDR = 289,
     T_XCHK = 290,
     T_BMVE = 291,
     T_BMVB = 292,
     T_BCMP = 293,
     T_BLGC = 294,
     T_BSCN = 295,
     T_SMVE = 296,
     T_SMVB = 297,
     T_SCMP = 298,
     T_SLGC = 299,
     T_SMVF = 300,
     T_TALU = 301,
     T_TCHK = 302,
     T_TRNS = 303,
     T_A = 304,
     T_AU = 305,
     T_AOD = 306,
     T_B = 307,
     T_NB = 308,
     T_XNB = 309,
     T_SF = 310,
     T_STK = 311,
     T_LOAD_NB_ADD = 312,
     T_LOAD_SF_ADD = 313,
     T_LOAD = 314,
     T_LOAD_DEC = 315,
     T_STACK_LOAD = 316,
     T_STORE = 317,
     T_PLUS = 318,
     T_MINUS = 319,
     T_MUL = 320,
     T_NEQV = 321,
     T_OR = 322,
     T_AND = 323,
     T_SHIFT = 324,
     T_RSUB = 325,
     T_COMP = 326,
     T_CINC = 327,
     T_CONV = 328,
     T_RDIV = 329,
     T_B_REL = 330,
     T_0_REL = 331,
     T_STACK = 332,
     T_IF = 333,
     T_EQ = 334,
     T_NE = 335,
     T_LT = 336,
     T_LE = 337,
     T_GT = 338,
     T_GE = 339,
     T_OV = 340,
     T_BN = 341,
     T_RJUMP = 342,
     T_DATAVEC = 343,
     T_DATASTR = 344
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 155 "xpl.y"

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
#line 164 "xpl.tab.h"
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
