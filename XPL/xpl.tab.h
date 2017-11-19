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
     T_PROC = 269,
     T_BEGIN = 270,
     T_END = 271,
     T_COMMENT = 272,
     T_LINE = 273,
     T_V32 = 274,
     T_V64 = 275,
     T_VV = 276,
     T_NAME = 277,
     T_INTEGER = 278,
     T_CHARACTER_STRING = 279,
     T_D = 280,
     T_DO = 281,
     T_XD = 282,
     T_XDO = 283,
     T_DB = 284,
     T_XDB = 285,
     T_MS = 286,
     T_SN = 287,
     T_DL = 288,
     T_SPM = 289,
     T_MOD = 290,
     T_RMOD = 291,
     T_SMOD = 292,
     T_XMOD = 293,
     T_MDR = 294,
     T_XCHK = 295,
     T_BMVE = 296,
     T_BMVB = 297,
     T_BCMP = 298,
     T_BLGC = 299,
     T_BSCN = 300,
     T_SMVE = 301,
     T_SMVB = 302,
     T_SCMP = 303,
     T_SLGC = 304,
     T_SMVF = 305,
     T_TALU = 306,
     T_TCHK = 307,
     T_TRNS = 308,
     T_A = 309,
     T_AU = 310,
     T_AOD = 311,
     T_B = 312,
     T_X = 313,
     T_XS = 314,
     T_NB = 315,
     T_XNB = 316,
     T_SF = 317,
     T_STK = 318,
     T_LOAD_NB_ADD = 319,
     T_LOAD_SF_ADD = 320,
     T_LOAD = 321,
     T_LOAD_DEC = 322,
     T_STACK_LOAD = 323,
     T_STORE = 324,
     T_PLUS = 325,
     T_MINUS = 326,
     T_MUL = 327,
     T_NEQV = 328,
     T_OR = 329,
     T_AND = 330,
     T_SHIFT = 331,
     T_RSUB = 332,
     T_COMP = 333,
     T_CINC = 334,
     T_CONV = 335,
     T_RDIV = 336,
     T_B_REL = 337,
     T_0_REL = 338,
     T_STACK = 339,
     T_IF = 340,
     T_EQ = 341,
     T_NE = 342,
     T_LT = 343,
     T_LE = 344,
     T_GT = 345,
     T_GE = 346,
     T_OV = 347,
     T_BN = 348,
     T_RJUMP = 349,
     T_RETURN = 350,
     T_EXIT = 351,
     T_JUMP = 352,
     T_XJUMP = 353,
     T_STKLINK = 354,
     T_SETLINK = 355,
     T_CALL = 356,
     T_ACALL = 357,
     T_DATAVEC = 358,
     T_DATASTR = 359
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 175 "xpl.y"

    unsigned int f;
    t_uint64 unsignedval;
    t_int64 signedval;
	jump_type_t jumptype;
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
#line 179 "xpl.tab.h"
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
