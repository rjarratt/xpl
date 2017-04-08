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
     T_SN = 285,
     T_DL = 286,
     T_SPM = 287,
     T_MOD = 288,
     T_RMOD = 289,
     T_SMOD = 290,
     T_XMOD = 291,
     T_MDR = 292,
     T_XCHK = 293,
     T_BMVE = 294,
     T_BMVB = 295,
     T_BCMP = 296,
     T_BLGC = 297,
     T_BSCN = 298,
     T_SMVE = 299,
     T_SMVB = 300,
     T_SCMP = 301,
     T_SLGC = 302,
     T_SMVF = 303,
     T_TALU = 304,
     T_TCHK = 305,
     T_TRNS = 306,
     T_A = 307,
     T_AU = 308,
     T_AOD = 309,
     T_B = 310,
     T_NB = 311,
     T_XNB = 312,
     T_SF = 313,
     T_STK = 314,
     T_LOAD_NB_ADD = 315,
     T_LOAD_SF_ADD = 316,
     T_LOAD = 317,
     T_LOAD_DEC = 318,
     T_STACK_LOAD = 319,
     T_STORE = 320,
     T_PLUS = 321,
     T_MINUS = 322,
     T_MUL = 323,
     T_NEQV = 324,
     T_OR = 325,
     T_AND = 326,
     T_SHIFT = 327,
     T_RSUB = 328,
     T_COMP = 329,
     T_CINC = 330,
     T_CONV = 331,
     T_RDIV = 332,
     T_B_REL = 333,
     T_0_REL = 334,
     T_STACK = 335,
     T_IF = 336,
     T_EQ = 337,
     T_NE = 338,
     T_LT = 339,
     T_LE = 340,
     T_GT = 341,
     T_GE = 342,
     T_OV = 343,
     T_BN = 344,
     T_RJUMP = 345,
     T_DATAVEC = 346,
     T_DATASTR = 347
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 159 "xpl.y"

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
#line 167 "xpl.tab.h"
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
