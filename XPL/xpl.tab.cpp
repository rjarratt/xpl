/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 163 "xpl.y"

#include <stdio.h>
#include <string.h>
#include "xpl.h"

extern int yylex();
extern char *yytext;
extern int yylineno;


/* Line 371 of yacc.c  */
#line 79 "xpl.tab.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "xpl.tab.h".  */
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
/* Line 387 of yacc.c  */
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


/* Line 387 of yacc.c  */
#line 244 "xpl.tab.cpp"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 272 "xpl.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   445

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  225
/* YYNRULES -- Number of states.  */
#define YYNSTATES  326

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   359

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    21,    23,    25,    28,
      30,    33,    36,    39,    42,    45,    48,    51,    54,    56,
      59,    61,    66,    68,    70,    72,    74,    76,    78,    80,
      82,    84,    88,    92,    95,    97,    99,   101,   103,   105,
     107,   110,   113,   116,   119,   122,   124,   126,   128,   130,
     132,   134,   136,   138,   140,   142,   144,   146,   148,   150,
     152,   154,   157,   160,   162,   164,   166,   168,   170,   172,
     174,   176,   178,   180,   182,   184,   186,   188,   190,   193,
     196,   199,   201,   203,   205,   207,   209,   211,   213,   215,
     217,   219,   221,   223,   225,   227,   229,   230,   232,   234,
     236,   238,   240,   242,   244,   246,   248,   250,   252,   255,
     258,   261,   264,   266,   269,   272,   275,   278,   281,   285,
     288,   290,   292,   294,   296,   298,   301,   304,   307,   310,
     313,   316,   319,   322,   325,   328,   331,   334,   337,   340,
     343,   346,   349,   351,   354,   357,   360,   363,   366,   368,
     371,   374,   376,   378,   380,   382,   384,   386,   388,   390,
     392,   394,   396,   398,   400,   402,   405,   411,   416,   420,
     423,   426,   428,   430,   432,   434,   436,   438,   440,   442,
     444,   446,   448,   450,   453,   456,   459,   462,   464,   466,
     468,   470,   472,   474,   476,   478,   480,   483,   485,   487,
     489,   491,   494,   495,   505,   508,   512,   514,   515,   520,
     522,   524,   528,   532,   537,   538,   539,   547,   553,   559,
     561,   562,   567,   569,   573,   575
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     106,     0,    -1,   107,    -1,   107,   106,    -1,    -1,    12,
     109,   108,     3,    15,     3,   110,    16,     3,    13,     3,
      -1,   147,    -1,   111,    -1,   110,   111,    -1,   112,    -1,
     112,   166,    -1,   113,   166,    -1,   120,   166,    -1,   149,
     166,    -1,   151,   166,    -1,   158,   166,    -1,   159,   166,
      -1,   162,   166,    -1,   166,    -1,    22,     5,    -1,   114,
      -1,   115,     6,   116,   117,    -1,    19,    -1,    20,    -1,
      21,    -1,    60,    -1,    61,    -1,    62,    -1,    23,    -1,
      63,    -1,   118,    -1,   117,     4,   118,    -1,    22,     5,
     119,    -1,    71,    23,    -1,    23,    -1,    11,    -1,   121,
      -1,   137,    -1,   130,    -1,   140,    -1,   122,   144,    -1,
     124,   144,    -1,   126,   144,    -1,   129,   144,    -1,    57,
     123,    -1,    66,    -1,    67,    -1,    68,    -1,    69,    -1,
      70,    -1,    71,    -1,    72,    -1,     6,    -1,    73,    -1,
      74,    -1,    76,    -1,    75,    -1,    77,    -1,    78,    -1,
      79,    -1,    81,    -1,    58,   125,    -1,    59,   125,    -1,
      66,    -1,    68,    -1,    69,    -1,    70,    -1,    71,    -1,
      72,    -1,     6,    -1,    73,    -1,    74,    -1,    76,    -1,
      75,    -1,    77,    -1,    78,    -1,    80,    -1,    81,    -1,
      54,    78,    -1,    54,   127,    -1,    55,   128,    -1,    66,
      -1,    67,    -1,    68,    -1,    69,    -1,    70,    -1,    71,
      -1,    72,    -1,     6,    -1,    73,    -1,    74,    -1,    76,
      -1,    75,    -1,    77,    -1,    80,    -1,    81,    -1,    -1,
      70,    -1,    71,    -1,    72,    -1,     6,    -1,    73,    -1,
      74,    -1,    76,    -1,    75,    -1,    77,    -1,    78,    -1,
      81,    -1,    56,    66,    -1,    56,    68,    -1,    56,    69,
      -1,    56,    78,    -1,    95,    -1,   131,   144,    -1,   132,
     144,    -1,   133,   144,    -1,   134,   144,    -1,   135,   144,
      -1,    61,    69,   145,    -1,   136,   144,    -1,    96,    -1,
      97,    -1,    98,    -1,    99,    -1,   100,    -1,    31,    66,
      -1,    62,    66,    -1,    62,    70,    -1,    62,    64,    -1,
      62,    69,    -1,    60,    66,    -1,    60,    65,    -1,    60,
      70,    -1,    61,    66,    -1,    61,    70,    -1,    32,    66,
      -1,    33,    66,    -1,    34,    66,    -1,   138,   144,    -1,
     139,   145,    -1,    28,    66,    -1,    27,    66,    -1,    84,
      -1,    26,    66,    -1,    25,    66,    -1,    25,    68,    -1,
      27,    69,    -1,    30,    69,    -1,    38,    -1,    25,    69,
      -1,    29,    69,    -1,    35,    -1,    39,    -1,    40,    -1,
      41,    -1,    42,    -1,    43,    -1,    44,    -1,    45,    -1,
      46,    -1,    47,    -1,    48,    -1,    49,    -1,    50,    -1,
      51,    -1,   141,    22,    -1,    85,   142,     4,   141,    22,
      -1,    93,   143,    85,   142,    -1,    93,   143,   144,    -1,
      70,    94,    -1,    71,    94,    -1,    94,    -1,    86,    -1,
      87,    -1,    91,    -1,    88,    -1,    89,    -1,    90,    -1,
      92,    -1,    93,    -1,     6,    -1,    66,    -1,   145,    -1,
      25,    82,    -1,    22,    82,    -1,    25,    83,    -1,    22,
      83,    -1,    22,    -1,    32,    -1,    54,    -1,    57,    -1,
      93,    -1,    25,    -1,   146,    -1,   147,    -1,    11,    -1,
     148,    23,    -1,    23,    -1,    70,    -1,    71,    -1,   150,
      -1,    18,    23,    -1,    -1,   103,    22,     7,    23,     8,
       3,   152,   153,    16,    -1,   154,     3,    -1,   154,     3,
     153,    -1,   155,    -1,    -1,   146,   156,     4,   157,    -1,
     146,    -1,   155,    -1,     9,    23,    10,    -1,   104,    22,
      24,    -1,    15,     3,   110,    16,    -1,    -1,    -1,    14,
      22,   160,     3,   110,   161,    16,    -1,   101,    22,     7,
     163,     8,    -1,   102,    22,     7,   163,     8,    -1,    22,
      -1,    -1,    22,   164,     4,   165,    -1,   144,    -1,   165,
       4,   144,    -1,     3,    -1,    17,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   193,   193,   193,   194,   194,   195,   197,   198,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   212,
     215,   217,   218,   218,   218,   220,   221,   222,   223,   224,
     225,   225,   226,   228,   229,   230,   233,   234,   235,   236,
     239,   240,   241,   242,   244,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   264,   265,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   285,   286,
     287,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   320,   321,
     322,   323,   326,   327,   328,   329,   330,   331,   332,   333,
     336,   337,   338,   339,   340,   342,   344,   345,   346,   347,
     350,   351,   352,   355,   356,   359,   360,   361,   364,   365,
     368,   369,   370,   371,   372,   373,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   397,   398,   399,   400,   403,
     404,   405,   408,   409,   410,   411,   412,   413,   414,   415,
     418,   419,   422,   423,   424,   425,   426,   429,   430,   431,
     432,   433,   434,   435,   438,   439,   442,   443,   445,   445,
     447,   448,   450,   450,   451,   451,   452,   453,   453,   453,
     454,   454,   455,   458,   459,   459,   459,   462,   463,   466,
     467,   467,   470,   471,   473,   473
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_NL", "T_COMMA", "T_COLON", "T_SLASH",
  "T_L_BR", "T_R_BR", "T_L_SQ", "T_R_SQ", "T_HEX_DIGITS", "T_SEGMENT",
  "T_ENDOFSEGMENT", "T_PROC", "T_BEGIN", "T_END", "T_COMMENT", "T_LINE",
  "T_V32", "T_V64", "T_VV", "T_NAME", "T_INTEGER", "T_CHARACTER_STRING",
  "T_D", "T_DO", "T_XD", "T_XDO", "T_DB", "T_XDB", "T_MS", "T_SN", "T_DL",
  "T_SPM", "T_MOD", "T_RMOD", "T_SMOD", "T_XMOD", "T_MDR", "T_XCHK",
  "T_BMVE", "T_BMVB", "T_BCMP", "T_BLGC", "T_BSCN", "T_SMVE", "T_SMVB",
  "T_SCMP", "T_SLGC", "T_SMVF", "T_TALU", "T_TCHK", "T_TRNS", "T_A",
  "T_AU", "T_AOD", "T_B", "T_X", "T_XS", "T_NB", "T_XNB", "T_SF", "T_STK",
  "T_LOAD_NB_ADD", "T_LOAD_SF_ADD", "T_LOAD", "T_LOAD_DEC", "T_STACK_LOAD",
  "T_STORE", "T_PLUS", "T_MINUS", "T_MUL", "T_NEQV", "T_OR", "T_AND",
  "T_SHIFT", "T_RSUB", "T_COMP", "T_CINC", "T_CONV", "T_RDIV", "T_B_REL",
  "T_0_REL", "T_STACK", "T_IF", "T_EQ", "T_NE", "T_LT", "T_LE", "T_GT",
  "T_GE", "T_OV", "T_BN", "T_RJUMP", "T_RETURN", "T_EXIT", "T_JUMP",
  "T_XJUMP", "T_STKLINK", "T_SETLINK", "T_CALL", "T_ACALL", "T_DATAVEC",
  "T_DATASTR", "$accept", "xpl_program", "program_of_a_segment", "$@1",
  "execute_seg_no", "program", "statement", "label", "declarative",
  "var_dec", "var_type", "var_rel", "var_spec_list", "var_spec",
  "displacement", "instruction", "comput", "b_ord", "b_operator", "x_ord",
  "x_operator", "a_ord", "a_operator", "au_operator", "aod_ord", "org",
  "misc_org_ord", "ms_ord", "sf_ord", "nb_ord", "xnb_ord", "misc_ord",
  "sts", "fn_1", "fn_2", "condit", "jump_spec", "cond", "b_fn", "operand",
  "simple_operand", "literal", "decimal", "sign",
  "special_directive_statement", "line_directive", "table", "$@2",
  "lit_list", "lit_line", "lit_items", "$@3", "lit_repeat", "text",
  "block", "$@4", "$@5", "call", "parameters", "$@6", "operand_list",
  "sep", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   105,   106,   106,   108,   107,   109,   110,   110,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   112,
     113,   114,   115,   115,   115,   116,   116,   116,   116,   116,
     117,   117,   118,   119,   119,   119,   120,   120,   120,   120,
     121,   121,   121,   121,   122,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   124,   124,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   126,   126,
     126,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   129,   129,
     129,   129,   130,   130,   130,   130,   130,   130,   130,   130,
     131,   131,   131,   131,   131,   132,   133,   133,   133,   133,
     134,   134,   134,   135,   135,   136,   136,   136,   137,   137,
     138,   138,   138,   138,   138,   138,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   140,   140,   140,   140,   141,
     141,   141,   142,   142,   142,   142,   142,   142,   142,   142,
     143,   143,   144,   144,   144,   144,   144,   145,   145,   145,
     145,   145,   145,   145,   146,   146,   147,   147,   148,   148,
     149,   150,   152,   151,   153,   153,   154,   156,   155,   155,
     157,   157,   158,   159,   160,   161,   159,   162,   162,   163,
     164,   163,   165,   165,   166,   166
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,    11,     1,     1,     2,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     2,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     1,     2,     2,     2,     2,     2,     3,     2,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     2,     2,     2,     2,     2,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     5,     4,     3,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     2,     0,     9,     2,     3,     1,     0,     4,     1,
       1,     3,     3,     4,     0,     0,     7,     5,     5,     1,
       0,     4,     1,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,   197,   198,   199,     4,     6,     0,
       1,     3,     0,   196,     0,     0,     0,   224,     0,     0,
     225,     0,    22,    23,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   151,   148,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,     0,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   142,     0,     0,   171,   112,   120,   121,   122,
     123,   124,     0,     0,     0,     0,     0,     7,     9,     0,
      20,     0,     0,    36,     0,     0,     0,     0,    38,     0,
       0,     0,     0,     0,     0,    37,     0,     0,    39,     0,
       0,   200,     0,     0,     0,     0,    18,   214,     0,   201,
      19,   144,   145,   149,   143,   141,   146,   140,   150,   147,
     125,   135,   136,   137,    88,    81,    82,    83,    84,    85,
      86,    87,    89,    90,    92,    91,    93,    78,    94,    95,
      79,   100,    97,    98,    99,   101,   102,   104,   103,   105,
     106,   107,    80,   108,   109,   110,   111,    52,    45,    46,
      47,    48,    49,    50,    51,    53,    54,    56,    55,    57,
      58,    59,    60,    44,    69,    63,    64,    65,    66,    67,
      68,    70,    71,    73,    72,    74,    75,    76,    77,    61,
      62,   131,   130,   132,   133,     0,   134,   128,   126,   129,
     127,   169,   170,   172,   173,   175,   176,   177,   174,   178,
     179,     0,   180,   181,     0,     0,     0,     0,     0,     0,
       8,    10,    11,     0,    12,   195,   187,   192,   188,   189,
     190,   191,    40,   182,   193,   194,    41,    42,    43,   113,
     114,   115,   116,   117,   119,   138,   187,   192,   139,   165,
      13,    14,    15,    16,    17,     0,     0,   118,     0,     0,
     168,     0,     0,     0,   212,     0,    28,    25,    26,    27,
      29,     0,   184,   186,   183,   185,     0,   213,     0,   167,
     219,     0,     0,     0,     0,     0,    21,    30,   215,   166,
       0,   217,   218,     0,     5,     0,     0,     0,     0,   202,
      35,    34,     0,    32,    31,   216,   222,   221,     0,    33,
       0,   207,     0,     0,   206,   223,     0,   203,   204,     0,
     205,     0,   210,   208,     0,   211
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    12,     7,    76,    77,    78,    79,    80,
      81,   271,   286,   287,   303,    82,    83,    84,   173,    85,
     189,    86,   140,   152,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   211,   214,   232,
     233,   234,   235,     9,   100,   101,   102,   308,   312,   313,
     314,   316,   323,   103,   104,   255,   297,   105,   281,   290,
     307,   106
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -173
static const yytype_int16 yypact[] =
{
       3,    -9,    22,     3,  -173,  -173,  -173,  -173,  -173,    49,
    -173,  -173,    72,  -173,    68,    84,   304,  -173,    69,   113,
    -173,    99,  -173,  -173,  -173,   136,   -49,    79,    32,    85,
      81,    88,    93,   104,   107,   110,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,   126,    91,    57,   350,   364,   364,   119,    61,   111,
      64,    96,  -173,   189,     7,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,   160,   164,   186,   187,     9,  -173,    15,    15,
    -173,   205,    15,  -173,    67,    67,    67,    67,  -173,    67,
      67,    67,    67,    67,    67,  -173,    67,   117,  -173,   190,
      15,  -173,    15,    15,    15,    15,  -173,  -173,   304,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,   117,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,   210,  -173,  -173,    63,   219,   247,   248,   241,   265,
    -173,  -173,  -173,    92,  -173,  -173,   -37,    36,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,   266,   202,  -173,     6,   189,
    -173,   249,   249,   251,  -173,   270,  -173,  -173,  -173,  -173,
    -173,   262,  -173,  -173,  -173,  -173,   304,  -173,   263,  -173,
     285,   286,   300,   301,   307,   306,   308,  -173,   304,  -173,
     309,  -173,  -173,   311,  -173,    10,   262,   299,    67,  -173,
    -173,  -173,   293,  -173,  -173,  -173,  -173,   313,   168,  -173,
      67,   317,   312,   324,  -173,  -173,   336,  -173,   168,    73,
    -173,   318,  -173,  -173,   347,  -173
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -173,   365,  -173,  -173,  -173,   -98,   -73,  -173,  -173,  -173,
    -173,  -173,  -173,    71,  -173,  -173,  -173,  -173,  -173,  -173,
     315,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,   114,   118,  -173,   -85,
     -81,  -172,   368,  -173,  -173,  -173,  -173,  -173,    55,  -173,
      59,  -173,  -173,  -173,  -173,  -173,  -173,  -173,   120,  -173,
    -173,   188
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -221
static const yytype_int16 yytable[] =
{
     236,   237,   238,   220,   239,   240,   241,   242,   243,   244,
     256,   245,    17,   212,     4,     1,   248,   111,    17,   112,
     113,   300,    10,    18,    19,   219,    20,    21,    22,    23,
      24,    25,    20,   301,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,   272,   273,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,     5,     6,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    13,   213,   225,    14,    60,    61,   225,    60,
      61,   302,   321,    15,   225,   226,     4,    16,   227,   226,
       4,   107,   227,    62,    63,   228,     4,   141,   115,   228,
      65,   116,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,   257,   266,   108,   229,   274,   275,
     230,   229,   109,   153,   230,   154,   155,   194,   225,   260,
     195,   196,   124,     5,     6,   156,   311,     5,     6,   246,
       4,   110,   247,     5,     6,   114,   311,   311,   259,   228,
     118,   117,   267,   268,   269,   270,   231,   119,   201,   120,
     231,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     121,   229,   151,   122,   230,   197,   123,   198,   288,   225,
     199,   200,   215,   220,   191,   192,   216,     5,     6,   193,
     202,     4,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,    17,   138,   139,   217,   218,
     231,   223,   249,   306,   258,   220,    18,    19,   277,    20,
      21,    22,    23,    24,    25,   315,   261,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     5,     6,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,   262,   263,    51,    52,    53,    54,
      55,    56,    57,    58,    59,   264,   221,   222,   265,   276,
     224,   280,    60,    61,   283,   203,   204,   205,   206,   207,
     208,   209,   210,   284,   285,   289,    62,    63,   250,  -220,
     251,   252,   253,   254,   291,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    17,   292,   293,
     294,   295,   296,   298,   299,   305,   309,   310,    18,    19,
    -209,    20,    21,    22,    23,    24,    25,   318,   317,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
     319,   324,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,   157,   325,    51,    52,
      53,    54,    55,    56,    57,    58,    59,   304,    11,     8,
     174,   190,   278,   320,    60,    61,     0,   279,   322,     0,
       0,     0,   282,     0,     0,     0,     0,     0,    62,    63,
       0,     0,     0,     0,     0,     0,     0,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     0,
       0,     0,     0,     0,     0,     0,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     175,   172,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-173)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      85,    86,    87,    76,    89,    90,    91,    92,    93,    94,
     108,    96,     3,     6,    23,    12,    97,    66,     3,    68,
      69,    11,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    17,    23,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    82,    83,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    70,    71,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    23,    66,    11,     3,    70,    71,    11,    70,
      71,    71,     9,    15,    11,    22,    23,     3,    25,    22,
      23,    22,    25,    84,    85,    32,    23,     6,    66,    32,
      94,    69,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   195,    23,     3,    54,    82,    83,
      57,    54,    23,    66,    57,    68,    69,    66,    11,   214,
      69,    70,     6,    70,    71,    78,   308,    70,    71,    22,
      23,     5,    25,    70,    71,    66,   318,   319,    85,    32,
      69,    66,    60,    61,    62,    63,    93,    69,    94,    66,
      93,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      66,    54,    81,    66,    57,    64,    66,    66,   276,    11,
      69,    70,    22,   256,    65,    66,    22,    70,    71,    70,
      94,    23,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,     3,    80,    81,    22,    22,
      93,     6,    22,   298,     4,   288,    14,    15,    16,    17,
      18,    19,    20,    21,    22,   310,     7,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    70,    71,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,     7,     7,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    24,    78,    79,     3,     3,
      82,    22,    70,    71,    23,    86,    87,    88,    89,    90,
      91,    92,    93,    13,    22,    22,    84,    85,   100,     4,
     102,   103,   104,   105,     8,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,     3,     8,     8,
       3,     5,     4,     4,     3,    16,    23,     4,    14,    15,
       3,    17,    18,    19,    20,    21,    22,     3,    16,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       4,    23,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,     6,    10,    54,    55,
      56,    57,    58,    59,    60,    61,    62,   296,     3,     1,
       6,    56,   258,   318,    70,    71,    -1,   259,   319,    -1,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      66,    81,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    -1,    80,    81
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,   106,   107,    23,    70,    71,   109,   147,   148,
       0,   106,   108,    23,     3,    15,     3,     3,    14,    15,
      17,    18,    19,    20,    21,    22,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      70,    71,    84,    85,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   110,   111,   112,   113,
     114,   115,   120,   121,   122,   124,   126,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     149,   150,   151,   158,   159,   162,   166,    22,     3,    23,
       5,    66,    68,    69,    66,    66,    69,    66,    69,    69,
      66,    66,    66,    66,     6,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    80,    81,
     127,     6,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    81,   128,    66,    68,    69,    78,     6,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    81,   123,     6,    66,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    80,    81,   125,
     125,    65,    66,    70,    66,    69,    70,    64,    66,    69,
      70,    94,    94,    86,    87,    88,    89,    90,    91,    92,
      93,   142,     6,    66,   143,    22,    22,    22,    22,    16,
     111,   166,   166,     6,   166,    11,    22,    25,    32,    54,
      57,    93,   144,   145,   146,   147,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,    22,    25,   145,    22,
     166,   166,   166,   166,   166,   160,   110,   145,     4,    85,
     144,     7,     7,     7,    24,     3,    23,    60,    61,    62,
      63,   116,    82,    83,    82,    83,     3,    16,   141,   142,
      22,   163,   163,    23,    13,    22,   117,   118,   110,    22,
     164,     8,     8,     8,     3,     5,     4,   161,     4,     3,
      11,    23,    71,   119,   118,    16,   144,   165,   152,    23,
       4,   146,   153,   154,   155,   144,   156,    16,     3,     4,
     153,     9,   155,   157,    23,    10
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
/* Line 1792 of yacc.c  */
#line 194 "xpl.y"
    { start_segment((unsigned int)(yyvsp[(2) - (2)].signedval)); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 194 "xpl.y"
    { end_segment(); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 195 "xpl.y"
    { (yyval.signedval) = (yyvsp[(1) - (1)].literal).signed_val; }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 212 "xpl.y"
    { add_label((yyvsp[(1) - (2)].nameval)); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 217 "xpl.y"
    { add_declaration((yyvsp[(1) - (4)].vartype), (yyvsp[(3) - (4)].varrelativeto), &(yyvsp[(4) - (4)].varspeclist)); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 218 "xpl.y"
    { (yyval.vartype)=V32; }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 218 "xpl.y"
    { (yyval.vartype) = V64; }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 218 "xpl.y"
    { (yyval.vartype) = VV; }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 220 "xpl.y"
    { (yyval.varrelativeto) = NB; }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 221 "xpl.y"
    { (yyval.varrelativeto) = XNB; }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 222 "xpl.y"
    { (yyval.varrelativeto) =SF; }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 223 "xpl.y"
    { if ((yyvsp[(1) - (1)].unsignedval) != 0) yyerror("invalid relative-to"); (yyval.varrelativeto) = ZERO; }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 224 "xpl.y"
    { (yyval.varrelativeto) = STK; }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 225 "xpl.y"
    { init_var_spec_list(&(yyval.varspeclist)); add_var_spec_list(&(yyval.varspeclist), &(yyvsp[(1) - (1)].varspec)); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 225 "xpl.y"
    { add_var_spec_list(&(yyval.varspeclist), &(yyvsp[(3) - (3)].varspec)); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 226 "xpl.y"
    { (yyval.varspec).name = (yyvsp[(1) - (3)].nameval); (yyval.varspec).displacement = (int)(yyvsp[(3) - (3)].signedval); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 228 "xpl.y"
    { (yyval.signedval) = 0 - (yyvsp[(2) - (2)].unsignedval); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 229 "xpl.y"
    { (yyval.signedval) = (yyvsp[(1) - (1)].unsignedval); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 230 "xpl.y"
    { (yyval.signedval) = (yyvsp[(1) - (1)].unsignedval); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 239 "xpl.y"
    { process_instruction((yyvsp[(1) - (2)].instruction).cr, (yyvsp[(1) - (2)].instruction).f, &(yyvsp[(2) - (2)].operand)); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 240 "xpl.y"
    { process_instruction((yyvsp[(1) - (2)].instruction).cr, (yyvsp[(1) - (2)].instruction).f, &(yyvsp[(2) - (2)].operand)); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 241 "xpl.y"
    { process_instruction((yyvsp[(1) - (2)].instruction).cr, (yyvsp[(1) - (2)].instruction).f, &(yyvsp[(2) - (2)].operand)); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 242 "xpl.y"
    { process_instruction((yyvsp[(1) - (2)].instruction).cr, (yyvsp[(1) - (2)].instruction).f, &(yyvsp[(2) - (2)].operand)); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 244 "xpl.y"
    { (yyval.instruction).cr = 1; (yyval.instruction).f = (yyvsp[(2) - (2)].f); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 246 "xpl.y"
    { (yyval.f) = 0; }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 247 "xpl.y"
    { (yyval.f) = 1; }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 248 "xpl.y"
    { (yyval.f) = 2; }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 249 "xpl.y"
    { (yyval.f) = 3; }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 250 "xpl.y"
    { (yyval.f) = 4; }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 251 "xpl.y"
    { (yyval.f) = 5; }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 252 "xpl.y"
    { (yyval.f) = 6; }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 253 "xpl.y"
    { (yyval.f) = 7; }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 254 "xpl.y"
    { (yyval.f) = 8; }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 255 "xpl.y"
    { (yyval.f) = 9; }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 256 "xpl.y"
    { (yyval.f) = 10; }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 257 "xpl.y"
    { (yyval.f) = 11; }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 258 "xpl.y"
    { (yyval.f) = 12; }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 259 "xpl.y"
    { (yyval.f) = 13; }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 260 "xpl.y"
    { (yyval.f) = 14; }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 261 "xpl.y"
    { (yyval.f) = 15; }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 264 "xpl.y"
    { (yyval.instruction).cr = 4; (yyval.instruction).f = (yyvsp[(2) - (2)].f); }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 265 "xpl.y"
    { (yyval.instruction).cr = 4; (yyval.instruction).f = (yyvsp[(2) - (2)].f); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 268 "xpl.y"
    { (yyval.f) = 0; }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 269 "xpl.y"
    { (yyval.f) = 2; }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 270 "xpl.y"
    { (yyval.f) = 3; }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 271 "xpl.y"
    { (yyval.f) = 4; }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 272 "xpl.y"
    { (yyval.f) = 5; }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 273 "xpl.y"
    { (yyval.f) = 6; }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 274 "xpl.y"
    { (yyval.f) = 7; }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 275 "xpl.y"
    { (yyval.f) = 8; }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 276 "xpl.y"
    { (yyval.f) = 9; }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 277 "xpl.y"
    { (yyval.f) = 10; }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 278 "xpl.y"
    { (yyval.f) = 11; }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 279 "xpl.y"
    { (yyval.f) = 12; }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 280 "xpl.y"
    { (yyval.f) = 13; }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 281 "xpl.y"
    { (yyval.f) = 14; }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 282 "xpl.y"
    { (yyval.f) = 15; }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 285 "xpl.y"
    { (yyval.instruction).cr = 5; (yyval.instruction).f = 13; }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 286 "xpl.y"
    { (yyval.instruction).cr = 7; (yyval.instruction).f = (yyvsp[(2) - (2)].f); }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 287 "xpl.y"
    { (yyval.instruction).cr = 5; (yyval.instruction).f = (yyvsp[(2) - (2)].f); }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 290 "xpl.y"
    { (yyval.f) = 0; }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 291 "xpl.y"
    { (yyval.f) = 1; }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 292 "xpl.y"
    { (yyval.f) = 2; }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 293 "xpl.y"
    { (yyval.f) = 3; }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 294 "xpl.y"
    { (yyval.f) = 4; }
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 295 "xpl.y"
    { (yyval.f) = 5; }
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 296 "xpl.y"
    { (yyval.f) = 6; }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 297 "xpl.y"
    { (yyval.f) = 7; }
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 298 "xpl.y"
    { (yyval.f) = 8; }
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 299 "xpl.y"
    { (yyval.f) = 9; }
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 300 "xpl.y"
    { (yyval.f) = 10; }
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 301 "xpl.y"
    { (yyval.f) = 11; }
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 302 "xpl.y"
    { (yyval.f) = 12; }
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 303 "xpl.y"
    { (yyval.f) = 14; }
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 304 "xpl.y"
    { (yyval.f) = 15; }
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 307 "xpl.y"
    { (yyval.f) = 4; }
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 308 "xpl.y"
    { (yyval.f) = 5; }
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 309 "xpl.y"
    { (yyval.f) = 6; }
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 310 "xpl.y"
    { (yyval.f) = 7; }
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 311 "xpl.y"
    { (yyval.f) = 8; }
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 312 "xpl.y"
    { (yyval.f) = 9; }
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 313 "xpl.y"
    { (yyval.f) = 10; }
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 314 "xpl.y"
    { (yyval.f) = 11; }
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 315 "xpl.y"
    { (yyval.f) = 12; }
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 316 "xpl.y"
    { (yyval.f) = 13; }
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 317 "xpl.y"
    { (yyval.f) = 15; }
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 320 "xpl.y"
    { (yyval.instruction).cr = 5; (yyval.instruction).f = 0; }
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 321 "xpl.y"
    { (yyval.instruction).cr = 5; (yyval.instruction).f = 2; }
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 322 "xpl.y"
    { (yyval.instruction).cr = 5; (yyval.instruction).f = 3; }
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 323 "xpl.y"
    { (yyval.instruction).cr = 6; (yyval.instruction).f = 12; }
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 326 "xpl.y"
    { emit_extended_instruction(0, 5, 2, 4); }
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 327 "xpl.y"
    { process_instruction(0, (yyvsp[(1) - (2)].f), &(yyvsp[(2) - (2)].operand)); }
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 328 "xpl.y"
    { process_instruction(0, (yyvsp[(1) - (2)].f), &(yyvsp[(2) - (2)].operand)); }
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 329 "xpl.y"
    { process_instruction(0, (yyvsp[(1) - (2)].f), &(yyvsp[(2) - (2)].operand)); }
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 330 "xpl.y"
    { process_instruction(0, (yyvsp[(1) - (2)].f), &(yyvsp[(2) - (2)].operand)); }
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 331 "xpl.y"
    { process_instruction(0, (yyvsp[(1) - (2)].f), &(yyvsp[(2) - (2)].operand)); }
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 332 "xpl.y"
    { process_instruction(0, 23, &(yyvsp[(3) - (3)].operand)); }
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 333 "xpl.y"
    { process_instruction(0, (yyvsp[(1) - (2)].f), &(yyvsp[(2) - (2)].operand)); }
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 336 "xpl.y"
    { (yyval.f) = 1; }
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 337 "xpl.y"
    { set_operand_label_context(JUMP_ABSOLUTE); (yyval.f) = 4; }
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 338 "xpl.y"
    { set_operand_label_context(JUMP_ABSOLUTE); (yyval.f) = 4; }
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 339 "xpl.y"
    { set_operand_label_context(JUMP_RELATIVE_LONG); (yyval.f) = 15; }
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 340 "xpl.y"
    { (yyval.f) = 19; }
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 342 "xpl.y"
    { (yyval.f) = 16; }
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 344 "xpl.y"
    { (yyval.f) = 24; }
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 345 "xpl.y"
    { (yyval.f) = 25; }
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 346 "xpl.y"
    { (yyval.f) = 26; }
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 347 "xpl.y"
    { (yyval.f) = 27; }
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 350 "xpl.y"
    { (yyval.f) = 28; }
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 351 "xpl.y"
    { (yyval.f) = 29; }
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 352 "xpl.y"
    { (yyval.f) = 30; }
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 355 "xpl.y"
    { (yyval.f) = 20; }
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 356 "xpl.y"
    { (yyval.f) = 22; }
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 359 "xpl.y"
    { (yyval.f) = 21; }
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 360 "xpl.y"
    { (yyval.f) = 17; }
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 361 "xpl.y"
    { (yyval.f) = 18; }
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 364 "xpl.y"
    { process_instruction((yyvsp[(1) - (2)].instruction).cr, (yyvsp[(1) - (2)].instruction).f, &(yyvsp[(2) - (2)].operand)); }
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 365 "xpl.y"
    { process_instruction((yyvsp[(1) - (2)].instruction).cr, (yyvsp[(1) - (2)].instruction).f, &(yyvsp[(2) - (2)].operand)); }
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 368 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 0; }
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 369 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 1; }
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 370 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 2; }
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 371 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 0; }
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 372 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 1; }
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 373 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 2; }
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 376 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 3; }
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 377 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 4; }
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 378 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 7; }
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 379 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 3; }
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 380 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 4; }
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 381 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 6; }
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 382 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 5; }
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 383 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 5; }
    break;

  case 154:
/* Line 1792 of yacc.c  */
#line 384 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 10; }
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 385 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 9; }
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 386 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 14; }
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 387 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 8; }
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 388 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 13; }
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 389 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 10; }
    break;

  case 160:
/* Line 1792 of yacc.c  */
#line 390 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 9; }
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 391 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 14; }
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 392 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 8; }
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 393 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 11; }
    break;

  case 164:
/* Line 1792 of yacc.c  */
#line 394 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 12; }
    break;

  case 165:
/* Line 1792 of yacc.c  */
#line 397 "xpl.y"
    { operand_t operand; set_operand_label((yyvsp[(2) - (2)].nameval), (yyvsp[(1) - (2)].jumptype), &operand); process_instruction(0, 0, &operand); }
    break;

  case 166:
/* Line 1792 of yacc.c  */
#line 398 "xpl.y"
    { operand_t operand; set_operand_label((yyvsp[(5) - (5)].nameval), (yyvsp[(4) - (5)].jumptype), &operand); process_instruction(0, 32 + (yyvsp[(2) - (5)].f), &operand); }
    break;

  case 167:
/* Line 1792 of yacc.c  */
#line 399 "xpl.y"
    { operand_t operand; operand.operand_type = OPERAND_LITERAL; make_int_literal(0, (yyvsp[(2) - (4)].f), &operand.literal);;process_instruction(0, 40 + (yyvsp[(4) - (4)].f), &operand); }
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 400 "xpl.y"
    { process_instruction(0, 48 + (yyvsp[(2) - (3)].f), &(yyvsp[(3) - (3)].operand)); }
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 403 "xpl.y"
    { (yyval.jumptype) = JUMP_RELATIVE_LONG; }
    break;

  case 170:
/* Line 1792 of yacc.c  */
#line 404 "xpl.y"
    { (yyval.jumptype) = JUMP_RELATIVE_SHORT; }
    break;

  case 171:
/* Line 1792 of yacc.c  */
#line 405 "xpl.y"
    { (yyval.jumptype) = JUMP_RELATIVE_DEFAULT; }
    break;

  case 172:
/* Line 1792 of yacc.c  */
#line 408 "xpl.y"
    { (yyval.f) = 0; }
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 409 "xpl.y"
    { (yyval.f) = 1; }
    break;

  case 174:
/* Line 1792 of yacc.c  */
#line 410 "xpl.y"
    { (yyval.f) = 2; }
    break;

  case 175:
/* Line 1792 of yacc.c  */
#line 411 "xpl.y"
    { (yyval.f) = 3; }
    break;

  case 176:
/* Line 1792 of yacc.c  */
#line 412 "xpl.y"
    { (yyval.f) = 4; }
    break;

  case 177:
/* Line 1792 of yacc.c  */
#line 413 "xpl.y"
    { (yyval.f) = 5; }
    break;

  case 178:
/* Line 1792 of yacc.c  */
#line 414 "xpl.y"
    { (yyval.f) = 6; }
    break;

  case 179:
/* Line 1792 of yacc.c  */
#line 415 "xpl.y"
    { (yyval.f) = 7; }
    break;

  case 180:
/* Line 1792 of yacc.c  */
#line 418 "xpl.y"
    { (yyval.f) = 10; }
    break;

  case 181:
/* Line 1792 of yacc.c  */
#line 419 "xpl.y"
    { (yyval.f) = 3; }
    break;

  case 183:
/* Line 1792 of yacc.c  */
#line 423 "xpl.y"
    { (yyval.operand).operand_type = OPERAND_VARIABLE_B_REL; (yyval.operand).symbol = &d_symbol; }
    break;

  case 184:
/* Line 1792 of yacc.c  */
#line 424 "xpl.y"
    { (yyval.operand).operand_type = OPERAND_VARIABLE_B_REL; (yyval.operand).symbol = find_symbol((yyvsp[(1) - (2)].nameval)); }
    break;

  case 185:
/* Line 1792 of yacc.c  */
#line 425 "xpl.y"
    { (yyval.operand).operand_type = OPERAND_VARIABLE_0_REL; (yyval.operand).symbol = &d_symbol; }
    break;

  case 186:
/* Line 1792 of yacc.c  */
#line 426 "xpl.y"
    { (yyval.operand).operand_type = OPERAND_VARIABLE_0_REL; (yyval.operand).symbol = find_symbol((yyvsp[(1) - (2)].nameval)); }
    break;

  case 187:
/* Line 1792 of yacc.c  */
#line 429 "xpl.y"
    { set_operand((yyvsp[(1) - (1)].nameval), &(yyval.operand)); }
    break;

  case 188:
/* Line 1792 of yacc.c  */
#line 430 "xpl.y"
    { (yyval.operand).operand_type = OPERAND_VARIABLE; (yyval.operand).symbol = &sn_ir_symbol; }
    break;

  case 189:
/* Line 1792 of yacc.c  */
#line 431 "xpl.y"
    { (yyval.operand).operand_type = OPERAND_VARIABLE; (yyval.operand).symbol = &a_ir_symbol; }
    break;

  case 190:
/* Line 1792 of yacc.c  */
#line 432 "xpl.y"
    { (yyval.operand).operand_type = OPERAND_VARIABLE; (yyval.operand).symbol = &b_ir_symbol; }
    break;

  case 191:
/* Line 1792 of yacc.c  */
#line 433 "xpl.y"
    { (yyval.operand).operand_type = OPERAND_VARIABLE; (yyval.operand).symbol = &bn_ir_symbol; }
    break;

  case 192:
/* Line 1792 of yacc.c  */
#line 434 "xpl.y"
    { (yyval.operand).operand_type = OPERAND_VARIABLE; (yyval.operand).symbol = &d_ir_symbol; }
    break;

  case 193:
/* Line 1792 of yacc.c  */
#line 435 "xpl.y"
    { (yyval.operand).operand_type = OPERAND_LITERAL; (yyval.operand).literal = (yyvsp[(1) - (1)].literal); }
    break;

  case 195:
/* Line 1792 of yacc.c  */
#line 439 "xpl.y"
    { make_int_literal(0, (yyvsp[(1) - (1)].unsignedval), &(yyval.literal)); }
    break;

  case 196:
/* Line 1792 of yacc.c  */
#line 442 "xpl.y"
    { make_int_literal((int)(yyvsp[(1) - (2)].sign), (yyvsp[(2) - (2)].unsignedval), &(yyval.literal)); /* TODO: can't express largest negative number */ }
    break;

  case 197:
/* Line 1792 of yacc.c  */
#line 443 "xpl.y"
    { make_int_literal(0, (yyvsp[(1) - (1)].unsignedval), &(yyval.literal)); }
    break;

  case 198:
/* Line 1792 of yacc.c  */
#line 445 "xpl.y"
    { (yyval.sign) = 1; }
    break;

  case 199:
/* Line 1792 of yacc.c  */
#line 445 "xpl.y"
    { (yyval.sign) = -1; }
    break;

  case 201:
/* Line 1792 of yacc.c  */
#line 448 "xpl.y"
    { process_line_directive((yyvsp[(2) - (2)].unsignedval)); }
    break;

  case 202:
/* Line 1792 of yacc.c  */
#line 450 "xpl.y"
    { process_datavec_start((yyvsp[(4) - (6)].unsignedval)); }
    break;

  case 203:
/* Line 1792 of yacc.c  */
#line 450 "xpl.y"
    { t_uint64 d = process_datavec_end(); add_symbol(DESCRIPTOR, NOT_REL, (yyvsp[(2) - (9)].nameval), d);}
    break;

  case 206:
/* Line 1792 of yacc.c  */
#line 452 "xpl.y"
    { process_datavec_line_end(); }
    break;

  case 207:
/* Line 1792 of yacc.c  */
#line 453 "xpl.y"
    { process_datavec_literal(&(yyvsp[(1) - (1)].literal)); }
    break;

  case 209:
/* Line 1792 of yacc.c  */
#line 453 "xpl.y"
    { process_datavec_literal(&(yyvsp[(1) - (1)].literal)); }
    break;

  case 211:
/* Line 1792 of yacc.c  */
#line 454 "xpl.y"
    { process_datavec_line_repeat((unsigned int)(yyvsp[(2) - (3)].unsignedval));}
    break;

  case 212:
/* Line 1792 of yacc.c  */
#line 455 "xpl.y"
    { t_uint64 d = process_text((yyvsp[(2) - (3)].nameval), (yyvsp[(3) - (3)].stringval)); add_symbol(DESCRIPTOR, NOT_REL, (yyvsp[(2) - (3)].nameval), d); }
    break;

  case 214:
/* Line 1792 of yacc.c  */
#line 459 "xpl.y"
    { start_proc((yyvsp[(2) - (2)].nameval)); }
    break;

  case 215:
/* Line 1792 of yacc.c  */
#line 459 "xpl.y"
    { end_proc((yyvsp[(2) - (5)].nameval)); }
    break;

  case 217:
/* Line 1792 of yacc.c  */
#line 462 "xpl.y"
    { operand_t operand; set_operand_label((yyvsp[(2) - (5)].nameval), JUMP_RELATIVE_LONG, &operand); process_instruction(0, 0, &operand);}
    break;

  case 218:
/* Line 1792 of yacc.c  */
#line 463 "xpl.y"
    { operand_t operand; set_operand_label((yyvsp[(2) - (5)].nameval), JUMP_ABSOLUTE, &operand); process_instruction(0, 4, &operand);}
    break;

  case 219:
/* Line 1792 of yacc.c  */
#line 466 "xpl.y"
    { stack_call_link((yyvsp[(1) - (1)].nameval)); }
    break;

  case 220:
/* Line 1792 of yacc.c  */
#line 467 "xpl.y"
    { stack_call_link((yyvsp[(1) - (1)].nameval)); }
    break;

  case 222:
/* Line 1792 of yacc.c  */
#line 470 "xpl.y"
    { stack_call_parameter(&(yyvsp[(1) - (1)].operand)); }
    break;

  case 223:
/* Line 1792 of yacc.c  */
#line 471 "xpl.y"
    { stack_call_parameter(&(yyvsp[(3) - (3)].operand)); }
    break;


/* Line 1792 of yacc.c  */
#line 2985 "xpl.tab.cpp"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 474 "xpl.y"


extern FILE *binary;
extern FILE *yyin;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "usage: xpl [infile] [outfile]\n");
    }
    else
    {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL)
        {
            fprintf(stderr, "cannot open %s\n", argv[1]);
        }

		binary = fopen(argv[2], "wb");
        if (yyin == NULL)
        {
            fprintf(stderr, "cannot open %s\n", argv[2]);
        }

        if (yyin != NULL && binary != NULL)
        {
            /* first pass picks up the forward declarations, but the operand sizes are unknown for forward declarations, so instruction locations will be incorrect */
		    set_pass(PASS_GET_FORWARDS);
            do
            {
                yyparse();
            }
            while (!feof(yyin));

            /* Second pass generates the right instructions as all the data types of forward declared items are now known, but byte origins of any forward declared
               descriptors will be unknown, so they will be incorrect in the symbol table at this point
            */
			if (!error_in_pass)
			{
			    rewind(yyin);
			    set_pass(PASS_CALC_SIZES);
                do
                {
                    yyparse();
                }
                while (!feof(yyin));
			}

            /* Third pass will run with forward declared descriptors having the right byte origin values.
            */
			if (!error_in_pass)
			{
			    rewind(yyin);
			    set_pass(PASS_CODE_GEN);
                do
                {
                    yyparse();
                }
                while (!feof(yyin));
			}

			fclose(binary);
        }
    }
}
