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
#line 159 "xpl.y"

#include <stdio.h>
#include "xpl.h"

extern int yylex();
extern char *yytext;
extern int yylineno;


/* Line 371 of yacc.c  */
#line 78 "xpl.tab.cpp"

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
     T_V32 = 273,
     T_V64 = 274,
     T_VV = 275,
     T_NAME = 276,
     T_INTEGER = 277,
     T_CHARACTER_STRING = 278,
     T_D = 279,
     T_DO = 280,
     T_XD = 281,
     T_XDO = 282,
     T_DB = 283,
     T_XDB = 284,
     T_MS = 285,
     T_SN = 286,
     T_DL = 287,
     T_SPM = 288,
     T_MOD = 289,
     T_RMOD = 290,
     T_SMOD = 291,
     T_XMOD = 292,
     T_MDR = 293,
     T_XCHK = 294,
     T_BMVE = 295,
     T_BMVB = 296,
     T_BCMP = 297,
     T_BLGC = 298,
     T_BSCN = 299,
     T_SMVE = 300,
     T_SMVB = 301,
     T_SCMP = 302,
     T_SLGC = 303,
     T_SMVF = 304,
     T_TALU = 305,
     T_TCHK = 306,
     T_TRNS = 307,
     T_A = 308,
     T_AU = 309,
     T_AOD = 310,
     T_B = 311,
     T_X = 312,
     T_XS = 313,
     T_NB = 314,
     T_XNB = 315,
     T_SF = 316,
     T_STK = 317,
     T_LOAD_NB_ADD = 318,
     T_LOAD_SF_ADD = 319,
     T_LOAD = 320,
     T_LOAD_DEC = 321,
     T_STACK_LOAD = 322,
     T_STORE = 323,
     T_PLUS = 324,
     T_MINUS = 325,
     T_MUL = 326,
     T_NEQV = 327,
     T_OR = 328,
     T_AND = 329,
     T_SHIFT = 330,
     T_RSUB = 331,
     T_COMP = 332,
     T_CINC = 333,
     T_CONV = 334,
     T_RDIV = 335,
     T_B_REL = 336,
     T_0_REL = 337,
     T_STACK = 338,
     T_IF = 339,
     T_EQ = 340,
     T_NE = 341,
     T_LT = 342,
     T_LE = 343,
     T_GT = 344,
     T_GE = 345,
     T_OV = 346,
     T_BN = 347,
     T_RJUMP = 348,
     T_RETURN = 349,
     T_EXIT = 350,
     T_JUMP = 351,
     T_XJUMP = 352,
     T_STKLINK = 353,
     T_SETLINK = 354,
     T_DATAVEC = 355,
     T_DATASTR = 356
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 170 "xpl.y"

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


/* Line 387 of yacc.c  */
#line 240 "xpl.tab.cpp"
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
#line 268 "xpl.tab.cpp"

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
#define YYLAST   517

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  102
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  206
/* YYNRULES -- Number of states.  */
#define YYNSTATES  297

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   356

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
      95,    96,    97,    98,    99,   100,   101
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    21,    23,    25,    28,
      30,    33,    36,    39,    42,    45,    48,    50,    55,    61,
      64,    66,    71,    73,    75,    77,    79,    81,    83,    85,
      87,    89,    93,    97,   100,   102,   104,   106,   108,   110,
     112,   115,   118,   121,   124,   127,   129,   131,   133,   135,
     137,   139,   141,   143,   145,   147,   149,   151,   153,   155,
     157,   159,   162,   165,   167,   169,   171,   173,   175,   177,
     179,   181,   183,   185,   187,   189,   191,   193,   195,   198,
     201,   203,   205,   207,   209,   211,   213,   215,   217,   219,
     221,   223,   225,   227,   229,   231,   233,   234,   236,   238,
     240,   242,   244,   246,   248,   250,   252,   254,   256,   259,
     262,   265,   268,   270,   273,   276,   279,   282,   285,   288,
     291,   294,   297,   300,   303,   306,   309,   312,   315,   318,
     321,   324,   327,   330,   333,   336,   339,   342,   345,   348,
     350,   353,   356,   359,   362,   365,   367,   370,   373,   375,
     377,   379,   381,   383,   385,   387,   389,   391,   393,   395,
     397,   399,   401,   404,   410,   415,   419,   422,   425,   427,
     429,   431,   433,   435,   437,   439,   441,   443,   445,   447,
     449,   452,   455,   458,   461,   463,   465,   467,   469,   471,
     473,   476,   478,   480,   482,   483,   493,   496,   500,   502,
     503,   508,   510,   512,   516,   520,   522
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     103,     0,    -1,   104,    -1,   104,   103,    -1,    -1,    12,
     106,   105,     3,    15,     3,   107,    16,     3,    13,     3,
      -1,   144,    -1,   108,    -1,   107,   108,    -1,   110,    -1,
     110,   154,    -1,   111,   154,    -1,   118,   154,    -1,   146,
     154,    -1,   153,   154,    -1,   109,   154,    -1,   154,    -1,
      15,     3,   107,    16,    -1,    14,    21,     3,   107,    16,
      -1,    21,     5,    -1,   112,    -1,   113,     6,   114,   115,
      -1,    18,    -1,    19,    -1,    20,    -1,    59,    -1,    60,
      -1,    61,    -1,    22,    -1,    62,    -1,   116,    -1,   115,
       4,   116,    -1,    21,     5,   117,    -1,    70,    22,    -1,
      22,    -1,    11,    -1,   119,    -1,   134,    -1,   128,    -1,
     137,    -1,   120,   141,    -1,   122,   141,    -1,   124,   141,
      -1,   127,   141,    -1,    56,   121,    -1,    65,    -1,    66,
      -1,    67,    -1,    68,    -1,    69,    -1,    70,    -1,    71,
      -1,     6,    -1,    72,    -1,    73,    -1,    75,    -1,    74,
      -1,    76,    -1,    77,    -1,    78,    -1,    80,    -1,    57,
     123,    -1,    58,   123,    -1,    65,    -1,    67,    -1,    68,
      -1,    69,    -1,    70,    -1,    71,    -1,     6,    -1,    72,
      -1,    73,    -1,    75,    -1,    74,    -1,    76,    -1,    77,
      -1,    79,    -1,    80,    -1,    53,   125,    -1,    54,   126,
      -1,    65,    -1,    66,    -1,    67,    -1,    68,    -1,    69,
      -1,    70,    -1,    71,    -1,     6,    -1,    72,    -1,    73,
      -1,    75,    -1,    74,    -1,    76,    -1,    77,    -1,    79,
      -1,    80,    -1,    -1,    69,    -1,    70,    -1,    71,    -1,
       6,    -1,    72,    -1,    73,    -1,    75,    -1,    74,    -1,
      76,    -1,    77,    -1,    80,    -1,    55,    65,    -1,    55,
      67,    -1,    55,    68,    -1,    55,    77,    -1,    94,    -1,
      95,   141,    -1,    96,   141,    -1,    97,   141,    -1,    98,
     141,    -1,    99,   142,    -1,   129,   141,    -1,   130,   141,
      -1,   131,   141,    -1,   132,   141,    -1,   133,   141,    -1,
      30,    65,    -1,    61,    65,    -1,    61,    69,    -1,    61,
      63,    -1,    59,    65,    -1,    59,    64,    -1,    59,    69,
      -1,    60,    65,    -1,    60,    69,    -1,    31,    65,    -1,
      32,    65,    -1,    33,    65,    -1,   135,   141,    -1,   136,
     142,    -1,    27,    65,    -1,    26,    65,    -1,    83,    -1,
      25,    65,    -1,    24,    65,    -1,    24,    67,    -1,    26,
      68,    -1,    29,    68,    -1,    37,    -1,    24,    68,    -1,
      28,    68,    -1,    34,    -1,    38,    -1,    39,    -1,    40,
      -1,    41,    -1,    42,    -1,    43,    -1,    44,    -1,    45,
      -1,    46,    -1,    47,    -1,    48,    -1,    49,    -1,    50,
      -1,   138,    21,    -1,    84,   139,     4,   138,    21,    -1,
      92,   140,    84,   139,    -1,    92,   140,   141,    -1,    69,
      93,    -1,    70,    93,    -1,    93,    -1,    85,    -1,    86,
      -1,    90,    -1,    87,    -1,    88,    -1,    89,    -1,    91,
      -1,    92,    -1,     6,    -1,    65,    -1,   142,    -1,    24,
      81,    -1,    21,    81,    -1,    24,    82,    -1,    21,    82,
      -1,    21,    -1,    56,    -1,    92,    -1,   143,    -1,   144,
      -1,    11,    -1,   145,    22,    -1,    22,    -1,    69,    -1,
      70,    -1,    -1,   100,    21,     7,    22,     8,     3,   147,
     148,    16,    -1,   149,     3,    -1,   149,     3,   148,    -1,
     150,    -1,    -1,   143,   151,     4,   152,    -1,   143,    -1,
     150,    -1,     9,    22,    10,    -1,   101,    21,    23,    -1,
       3,    -1,    17,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   188,   188,   188,   189,   189,   190,   192,   193,   196,
     197,   198,   199,   200,   201,   202,   203,   206,   207,   209,
     212,   214,   215,   215,   215,   217,   218,   219,   220,   221,
     222,   222,   223,   225,   226,   227,   230,   231,   232,   233,
     236,   237,   238,   239,   241,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   261,   262,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   282,   283,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   317,   318,
     319,   320,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   335,   337,   338,   339,   342,   343,   344,
     347,   348,   351,   352,   353,   356,   357,   360,   361,   362,
     363,   364,   365,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   389,   390,   391,   392,   395,   396,   397,   400,
     401,   402,   403,   404,   405,   406,   407,   410,   411,   414,
     415,   416,   417,   418,   421,   422,   423,   424,   427,   428,
     431,   432,   434,   434,   436,   436,   437,   437,   438,   439,
     439,   439,   440,   440,   441,   443,   443
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_NL", "T_COMMA", "T_COLON", "T_SLASH",
  "T_L_BR", "T_R_BR", "T_L_SQ", "T_R_SQ", "T_HEX_DIGITS", "T_SEGMENT",
  "T_ENDOFSEGMENT", "T_PROC", "T_BEGIN", "T_END", "T_COMMENT", "T_V32",
  "T_V64", "T_VV", "T_NAME", "T_INTEGER", "T_CHARACTER_STRING", "T_D",
  "T_DO", "T_XD", "T_XDO", "T_DB", "T_XDB", "T_MS", "T_SN", "T_DL",
  "T_SPM", "T_MOD", "T_RMOD", "T_SMOD", "T_XMOD", "T_MDR", "T_XCHK",
  "T_BMVE", "T_BMVB", "T_BCMP", "T_BLGC", "T_BSCN", "T_SMVE", "T_SMVB",
  "T_SCMP", "T_SLGC", "T_SMVF", "T_TALU", "T_TCHK", "T_TRNS", "T_A",
  "T_AU", "T_AOD", "T_B", "T_X", "T_XS", "T_NB", "T_XNB", "T_SF", "T_STK",
  "T_LOAD_NB_ADD", "T_LOAD_SF_ADD", "T_LOAD", "T_LOAD_DEC", "T_STACK_LOAD",
  "T_STORE", "T_PLUS", "T_MINUS", "T_MUL", "T_NEQV", "T_OR", "T_AND",
  "T_SHIFT", "T_RSUB", "T_COMP", "T_CINC", "T_CONV", "T_RDIV", "T_B_REL",
  "T_0_REL", "T_STACK", "T_IF", "T_EQ", "T_NE", "T_LT", "T_LE", "T_GT",
  "T_GE", "T_OV", "T_BN", "T_RJUMP", "T_RETURN", "T_EXIT", "T_JUMP",
  "T_XJUMP", "T_STKLINK", "T_SETLINK", "T_DATAVEC", "T_DATASTR", "$accept",
  "xpl_program", "program_of_a_segment", "$@1", "execute_seg_no",
  "program", "statement", "block", "label", "declarative", "var_dec",
  "var_type", "var_rel", "var_spec_list", "var_spec", "displacement",
  "instruction", "comput", "b_ord", "b_operator", "x_ord", "x_operator",
  "a_ord", "a_operator", "au_operator", "aod_ord", "org", "ms_ord",
  "sf_ord", "nb_ord", "xnb_ord", "misc_ord", "sts", "fn_1", "fn_2",
  "condit", "jump_spec", "cond", "b_fn", "operand", "simple_operand",
  "literal", "decimal", "sign", "table", "$@2", "lit_list", "lit_line",
  "lit_items", "$@3", "lit_repeat", "text", "sep", YY_NULL
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
     355,   356
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   102,   103,   103,   105,   104,   106,   107,   107,   108,
     108,   108,   108,   108,   108,   108,   108,   109,   109,   110,
     111,   112,   113,   113,   113,   114,   114,   114,   114,   114,
     115,   115,   116,   117,   117,   117,   118,   118,   118,   118,
     119,   119,   119,   119,   120,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   122,   122,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   124,   124,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   127,   127,
     127,   127,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   129,   130,   130,   130,   131,   131,   131,
     132,   132,   133,   133,   133,   134,   134,   135,   135,   135,
     135,   135,   135,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   137,   137,   137,   137,   138,   138,   138,   139,
     139,   139,   139,   139,   139,   139,   139,   140,   140,   141,
     141,   141,   141,   141,   142,   142,   142,   142,   143,   143,
     144,   144,   145,   145,   147,   146,   148,   148,   149,   151,
     150,   150,   152,   152,   153,   154,   154
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,    11,     1,     1,     2,     1,
       2,     2,     2,     2,     2,     2,     1,     4,     5,     2,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       2,     2,     2,     2,     2,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     5,     4,     3,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     0,     9,     2,     3,     1,     0,
       4,     1,     1,     3,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,   191,   192,   193,     4,     6,     0,
       1,     3,     0,   190,     0,     0,     0,   205,     0,     0,
     206,    22,    23,    24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,   145,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
       0,    96,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   139,     0,     0,   168,   112,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     0,     9,     0,    20,     0,
       0,    36,     0,     0,     0,     0,    38,     0,     0,     0,
       0,     0,    37,     0,     0,    39,     0,     0,     0,    16,
       0,     0,    19,   141,   142,   146,   140,   138,   143,   137,
     147,   144,   123,   132,   133,   134,    87,    80,    81,    82,
      83,    84,    85,    86,    88,    89,    91,    90,    92,    93,
      94,    95,    78,   100,    97,    98,    99,   101,   102,   104,
     103,   105,   106,   107,    79,   108,   109,   110,   111,    52,
      45,    46,    47,    48,    49,    50,    51,    53,    54,    56,
      55,    57,    58,    59,    60,    44,    69,    63,    64,    65,
      66,    67,    68,    70,    71,    73,    72,    74,    75,    76,
      77,    61,    62,   128,   127,   129,   130,   131,   126,   124,
     125,   166,   167,   169,   170,   172,   173,   174,   171,   175,
     176,     0,   177,   178,     0,   189,   184,     0,   185,   186,
     113,   179,   187,   188,   114,   115,   116,   184,   117,     0,
       0,     0,     8,    15,    10,    11,     0,    12,    40,    41,
      42,    43,   118,   119,   120,   121,   122,   135,   136,   162,
      13,    14,     0,     0,     0,     0,   165,   181,   183,   180,
     182,     0,   204,     0,    28,    25,    26,    27,    29,     0,
       0,    17,     0,   164,     0,     0,     0,    21,    30,    18,
     163,     0,     5,     0,     0,   194,    35,    34,     0,    32,
      31,     0,    33,   199,     0,     0,   198,     0,   195,   196,
       0,   197,     0,   202,   200,     0,   203
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    12,     7,    73,    74,    75,    76,    77,
      78,    79,   259,   267,   268,   279,    80,    81,    82,   165,
      83,   181,    84,   132,   144,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,   201,   204,   210,
     211,   212,   213,     9,    97,   281,   284,   285,   286,   287,
     294,    98,    99
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -200
static const yytype_int16 yypact[] =
{
      -7,   -16,    84,    -7,  -200,  -200,  -200,  -200,  -200,    64,
    -200,  -200,   102,  -200,   120,   134,   311,  -200,   123,   142,
    -200,  -200,  -200,  -200,   143,    39,    92,   -53,    93,   103,
     118,   132,   136,   137,   138,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
     407,    23,    66,   423,   437,   437,   -55,    16,    67,   106,
     113,  -200,   209,     5,  -200,  -200,   366,   366,   366,   366,
     371,   186,   187,    18,  -200,    10,    10,    10,  -200,   203,
      10,  -200,   366,   366,   366,   366,  -200,   366,   366,   366,
     366,   366,  -200,   366,   371,  -200,   191,    10,    10,  -200,
     207,   311,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,   210,  -200,  -200,   362,  -200,    27,    59,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,   206,
     192,   213,  -200,  -200,  -200,  -200,    61,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,   311,   135,   -62,   209,  -200,  -200,  -200,  -200,
    -200,   195,  -200,   208,  -200,  -200,  -200,  -200,  -200,   199,
     223,  -200,   201,  -200,   215,   221,   220,   241,  -200,  -200,
    -200,   243,  -200,    19,   199,  -200,  -200,  -200,   252,  -200,
    -200,    58,  -200,   272,   269,   283,  -200,   284,  -200,    58,
     189,  -200,   265,  -200,  -200,   279,  -200
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -200,   287,  -200,  -200,  -200,  -100,   -73,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,    17,  -200,  -200,  -200,  -200,  -200,
    -200,   247,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,    60,    63,  -200,   -65,
     -54,  -199,   302,  -200,  -200,  -200,    20,  -200,    15,  -200,
    -200,  -200,    49
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -202
static const yytype_int16 yytable[] =
{
     222,   243,   214,   215,   216,     1,     4,    59,    60,   183,
     184,   202,   107,    17,   185,   108,   218,   228,   229,   230,
     231,    17,   232,   233,   234,   235,   236,    20,   237,   133,
     276,    64,    18,    19,   221,    20,    21,    22,    23,    24,
     238,   277,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     5,     6,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,   205,
     203,    50,    51,    52,    53,    54,    55,    56,    57,    58,
       4,   186,   283,   254,    10,   187,    13,    59,    60,   278,
     283,   283,   134,   135,   136,   137,   138,   139,   140,   141,
     142,    61,    62,   143,   103,    14,   104,   105,   247,   248,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
     255,   256,   257,   258,   223,   224,   225,     5,     6,   227,
     188,   145,   189,   146,   147,    15,   190,    16,    17,   246,
     249,   250,   260,   148,   100,   101,   240,   241,   102,    18,
      19,   261,    20,    21,    22,    23,    24,   106,   109,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
     222,   110,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,   111,   222,    50,    51,
      52,    53,    54,    55,    56,    57,    58,   112,   292,   191,
     205,   113,   114,   115,    59,    60,   192,   219,   220,   226,
     242,     4,   239,   251,   244,   252,   253,   264,    61,    62,
     266,   265,   270,   271,   272,   273,    17,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    18,    19,   269,
      20,    21,    22,    23,    24,   274,   275,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     5,     6,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,   282,  -201,    50,    51,    52,    53,
      54,    55,    56,    57,    58,   288,   289,   295,   290,   296,
      11,   280,    59,    60,   193,   194,   195,   196,   197,   198,
     199,   200,   182,     8,   262,   293,    61,    62,   263,   291,
       0,     0,     0,     0,    17,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    18,    19,     0,    20,    21,
      22,    23,    24,     0,     0,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,     0,     0,    50,    51,    52,    53,    54,    55,
      56,    57,    58,   205,     0,     0,     0,   205,     0,     0,
      59,    60,   205,   206,     4,     0,   207,   206,     4,     0,
     207,     0,   217,     4,    61,    62,     0,     0,     0,     0,
       0,     0,     0,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,   116,     0,     0,     0,     0,   208,     0,
       0,     0,   208,     0,     0,     0,     0,   208,     0,   149,
       0,     5,     6,     0,     0,     5,     6,     0,     0,     0,
       5,     6,     0,   166,     0,     0,   245,     0,     0,     0,
       0,     0,     0,     0,   209,     0,     0,     0,   209,     0,
       0,     0,     0,   209,     0,     0,     0,     0,     0,     0,
       0,     0,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,     0,   130,   131,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   167,   164,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,     0,   179,   180
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-200)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      73,   101,    67,    68,    69,    12,    22,    69,    70,    64,
      65,     6,    65,     3,    69,    68,    70,    82,    83,    84,
      85,     3,    87,    88,    89,    90,    91,    17,    93,     6,
      11,    93,    14,    15,    16,    17,    18,    19,    20,    21,
      94,    22,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    69,    70,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    11,
      65,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      22,    65,   281,    22,     0,    69,    22,    69,    70,    70,
     289,   290,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    83,    84,    80,    65,     3,    67,    68,    81,    82,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
      59,    60,    61,    62,    75,    76,    77,    69,    70,    80,
      63,    65,    65,    67,    68,    15,    69,     3,     3,   204,
      81,    82,   242,    77,    21,     3,    97,    98,     5,    14,
      15,    16,    17,    18,    19,    20,    21,    65,    65,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
     243,    68,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    68,   260,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    65,     9,    93,
      11,    65,    65,    65,    69,    70,    93,    21,    21,     6,
       3,    22,    21,     7,     4,    23,     3,    22,    83,    84,
      21,    13,    21,     8,     3,     5,     3,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    14,    15,    16,
      17,    18,    19,    20,    21,     4,     3,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    69,    70,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    22,     3,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    16,     3,    22,     4,    10,
       3,   274,    69,    70,    85,    86,    87,    88,    89,    90,
      91,    92,    55,     1,   244,   290,    83,    84,   245,   289,
      -1,    -1,    -1,    -1,     3,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,    14,    15,    -1,    17,    18,
      19,    20,    21,    -1,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    11,    -1,    -1,    -1,    11,    -1,    -1,
      69,    70,    11,    21,    22,    -1,    24,    21,    22,    -1,
      24,    -1,    21,    22,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,     6,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    56,    -1,     6,
      -1,    69,    70,    -1,    -1,    69,    70,    -1,    -1,    -1,
      69,    70,    -1,     6,    -1,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    79,    80,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    65,    80,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    79,    80
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,   103,   104,    22,    69,    70,   106,   144,   145,
       0,   103,   105,    22,     3,    15,     3,     3,    14,    15,
      17,    18,    19,    20,    21,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    69,
      70,    83,    84,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   107,   108,   109,   110,   111,   112,   113,
     118,   119,   120,   122,   124,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   146,   153,   154,
      21,     3,     5,    65,    67,    68,    65,    65,    68,    65,
      68,    68,    65,    65,    65,    65,     6,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      79,    80,   125,     6,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    80,   126,    65,    67,    68,    77,     6,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    80,   121,     6,    65,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    79,
      80,   123,   123,    64,    65,    69,    65,    69,    63,    65,
      69,    93,    93,    85,    86,    87,    88,    89,    90,    91,
      92,   139,     6,    65,   140,    11,    21,    24,    56,    92,
     141,   142,   143,   144,   141,   141,   141,    21,   142,    21,
      21,    16,   108,   154,   154,   154,     6,   154,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   142,    21,
     154,   154,     3,   107,     4,    84,   141,    81,    82,    81,
      82,     7,    23,     3,    22,    59,    60,    61,    62,   114,
     107,    16,   138,   139,    22,    13,    21,   115,   116,    16,
      21,     8,     3,     5,     4,     3,    11,    22,    70,   117,
     116,   147,    22,   143,   148,   149,   150,   151,    16,     3,
       4,   148,     9,   150,   152,    22,    10
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
#line 189 "xpl.y"
    { start_segment((unsigned int)(yyvsp[(2) - (2)].signedval)); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 189 "xpl.y"
    { end_segment(); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 190 "xpl.y"
    { (yyval.signedval) = (yyvsp[(1) - (1)].literal).signed_val; }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 209 "xpl.y"
    { add_label((yyvsp[(1) - (2)].nameval)); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 214 "xpl.y"
    { add_declaration((yyvsp[(1) - (4)].vartype), (yyvsp[(3) - (4)].varrelativeto), &(yyvsp[(4) - (4)].varspeclist)); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 215 "xpl.y"
    { (yyval.vartype)=V32; }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 215 "xpl.y"
    { (yyval.vartype) = V64; }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 215 "xpl.y"
    { (yyval.vartype) = VV; }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 217 "xpl.y"
    { (yyval.varrelativeto) = NB; }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 218 "xpl.y"
    { (yyval.varrelativeto) = XNB; }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 219 "xpl.y"
    { (yyval.varrelativeto) =SF; }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 220 "xpl.y"
    { if ((yyvsp[(1) - (1)].unsignedval) != 0) yyerror("invalid relative-to"); (yyval.varrelativeto) = ZERO; }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 221 "xpl.y"
    { (yyval.varrelativeto) = STK; }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 222 "xpl.y"
    { init_var_spec_list(&(yyval.varspeclist)); add_var_spec_list(&(yyval.varspeclist), &(yyvsp[(1) - (1)].varspec)); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 222 "xpl.y"
    { add_var_spec_list(&(yyval.varspeclist), &(yyvsp[(3) - (3)].varspec)); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 223 "xpl.y"
    { (yyval.varspec).name = (yyvsp[(1) - (3)].nameval); (yyval.varspec).displacement = (int)(yyvsp[(3) - (3)].signedval); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 225 "xpl.y"
    { (yyval.signedval) = 0 - (yyvsp[(2) - (2)].unsignedval); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 226 "xpl.y"
    { (yyval.signedval) = (yyvsp[(1) - (1)].unsignedval); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 227 "xpl.y"
    { (yyval.signedval) = (yyvsp[(1) - (1)].unsignedval); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 236 "xpl.y"
    { process_instruction((yyvsp[(1) - (2)].instruction).cr, (yyvsp[(1) - (2)].instruction).f, &(yyvsp[(2) - (2)].operand)); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 237 "xpl.y"
    { process_instruction((yyvsp[(1) - (2)].instruction).cr, (yyvsp[(1) - (2)].instruction).f, &(yyvsp[(2) - (2)].operand)); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 238 "xpl.y"
    { process_instruction((yyvsp[(1) - (2)].instruction).cr, (yyvsp[(1) - (2)].instruction).f, &(yyvsp[(2) - (2)].operand)); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 239 "xpl.y"
    { process_instruction((yyvsp[(1) - (2)].instruction).cr, (yyvsp[(1) - (2)].instruction).f, &(yyvsp[(2) - (2)].operand)); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 241 "xpl.y"
    { (yyval.instruction).cr = 1; (yyval.instruction).f = (yyvsp[(2) - (2)].f); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 243 "xpl.y"
    { (yyval.f) = 0; }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 244 "xpl.y"
    { (yyval.f) = 1; }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 245 "xpl.y"
    { (yyval.f) = 2; }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 246 "xpl.y"
    { (yyval.f) = 3; }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 247 "xpl.y"
    { (yyval.f) = 4; }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 248 "xpl.y"
    { (yyval.f) = 5; }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 249 "xpl.y"
    { (yyval.f) = 6; }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 250 "xpl.y"
    { (yyval.f) = 7; }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 251 "xpl.y"
    { (yyval.f) = 8; }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 252 "xpl.y"
    { (yyval.f) = 9; }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 253 "xpl.y"
    { (yyval.f) = 10; }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 254 "xpl.y"
    { (yyval.f) = 11; }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 255 "xpl.y"
    { (yyval.f) = 12; }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 256 "xpl.y"
    { (yyval.f) = 13; }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 257 "xpl.y"
    { (yyval.f) = 14; }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 258 "xpl.y"
    { (yyval.f) = 15; }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 261 "xpl.y"
    { (yyval.instruction).cr = 4; (yyval.instruction).f = (yyvsp[(2) - (2)].f); }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 262 "xpl.y"
    { (yyval.instruction).cr = 4; (yyval.instruction).f = (yyvsp[(2) - (2)].f); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 265 "xpl.y"
    { (yyval.f) = 0; }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 266 "xpl.y"
    { (yyval.f) = 2; }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 267 "xpl.y"
    { (yyval.f) = 3; }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 268 "xpl.y"
    { (yyval.f) = 4; }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 269 "xpl.y"
    { (yyval.f) = 5; }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 270 "xpl.y"
    { (yyval.f) = 6; }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 271 "xpl.y"
    { (yyval.f) = 7; }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 272 "xpl.y"
    { (yyval.f) = 8; }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 273 "xpl.y"
    { (yyval.f) = 9; }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 274 "xpl.y"
    { (yyval.f) = 10; }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 275 "xpl.y"
    { (yyval.f) = 11; }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 276 "xpl.y"
    { (yyval.f) = 12; }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 277 "xpl.y"
    { (yyval.f) = 13; }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 278 "xpl.y"
    { (yyval.f) = 14; }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 279 "xpl.y"
    { (yyval.f) = 15; }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 282 "xpl.y"
    { (yyval.instruction).cr = 7; (yyval.instruction).f = (yyvsp[(2) - (2)].f); }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 283 "xpl.y"
    { (yyval.instruction).cr = 5; (yyval.instruction).f = (yyvsp[(2) - (2)].f); }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 286 "xpl.y"
    { (yyval.f) = 0; }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 287 "xpl.y"
    { (yyval.f) = 1; }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 288 "xpl.y"
    { (yyval.f) = 2; }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 289 "xpl.y"
    { (yyval.f) = 3; }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 290 "xpl.y"
    { (yyval.f) = 4; }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 291 "xpl.y"
    { (yyval.f) = 5; }
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 292 "xpl.y"
    { (yyval.f) = 6; }
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 293 "xpl.y"
    { (yyval.f) = 7; }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 294 "xpl.y"
    { (yyval.f) = 8; }
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 295 "xpl.y"
    { (yyval.f) = 9; }
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 296 "xpl.y"
    { (yyval.f) = 10; }
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 297 "xpl.y"
    { (yyval.f) = 11; }
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 298 "xpl.y"
    { (yyval.f) = 12; }
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 299 "xpl.y"
    { (yyval.f) = 13; }
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 300 "xpl.y"
    { (yyval.f) = 14; }
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 301 "xpl.y"
    { (yyval.f) = 15; }
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 304 "xpl.y"
    { (yyval.f) = 4; }
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 305 "xpl.y"
    { (yyval.f) = 5; }
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 306 "xpl.y"
    { (yyval.f) = 6; }
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 307 "xpl.y"
    { (yyval.f) = 7; }
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 308 "xpl.y"
    { (yyval.f) = 8; }
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 309 "xpl.y"
    { (yyval.f) = 9; }
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 310 "xpl.y"
    { (yyval.f) = 10; }
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 311 "xpl.y"
    { (yyval.f) = 11; }
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 312 "xpl.y"
    { (yyval.f) = 12; }
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 313 "xpl.y"
    { (yyval.f) = 13; }
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 314 "xpl.y"
    { (yyval.f) = 15; }
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 317 "xpl.y"
    { (yyval.instruction).cr = 5; (yyval.instruction).f = 0; }
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 318 "xpl.y"
    { (yyval.instruction).cr = 5; (yyval.instruction).f = 2; }
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 319 "xpl.y"
    { (yyval.instruction).cr = 5; (yyval.instruction).f = 3; }
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 320 "xpl.y"
    { (yyval.instruction).cr = 6; (yyval.instruction).f = 12; }
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 323 "xpl.y"
    { emit_extended_instruction(0, 5, 2, 4); }
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 324 "xpl.y"
    { process_instruction(0, 1, &(yyvsp[(2) - (2)].operand)); }
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 325 "xpl.y"
    { process_instruction(0, 4, &(yyvsp[(2) - (2)].operand)); }
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 326 "xpl.y"
    { process_instruction(0, 4, &(yyvsp[(2) - (2)].operand)); }
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 327 "xpl.y"
    { process_instruction(0, 15, &(yyvsp[(2) - (2)].operand)); }
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 328 "xpl.y"
    { process_instruction(0, 19, &(yyvsp[(2) - (2)].operand)); }
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 329 "xpl.y"
    { process_instruction(0, (yyvsp[(1) - (2)].f), &(yyvsp[(2) - (2)].operand)); }
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 330 "xpl.y"
    { process_instruction(0, (yyvsp[(1) - (2)].f), &(yyvsp[(2) - (2)].operand)); }
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 331 "xpl.y"
    { process_instruction(0, (yyvsp[(1) - (2)].f), &(yyvsp[(2) - (2)].operand)); }
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 332 "xpl.y"
    { process_instruction(0, (yyvsp[(1) - (2)].f), &(yyvsp[(2) - (2)].operand)); }
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 333 "xpl.y"
    { process_instruction(0, (yyvsp[(1) - (2)].f), &(yyvsp[(2) - (2)].operand)); }
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 335 "xpl.y"
    { (yyval.f) = 16; }
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 337 "xpl.y"
    { (yyval.f) = 24; }
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 338 "xpl.y"
    { (yyval.f) = 25; }
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 339 "xpl.y"
    { (yyval.f) = 26; }
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 342 "xpl.y"
    { (yyval.f) = 28; }
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 343 "xpl.y"
    { (yyval.f) = 29; }
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 344 "xpl.y"
    { (yyval.f) = 30; }
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 347 "xpl.y"
    { (yyval.f) = 20; }
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 348 "xpl.y"
    { (yyval.f) = 22; }
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 351 "xpl.y"
    { (yyval.f) = 21; }
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 352 "xpl.y"
    { (yyval.f) = 17; }
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 353 "xpl.y"
    { (yyval.f) = 18; }
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 356 "xpl.y"
    { process_instruction((yyvsp[(1) - (2)].instruction).cr, (yyvsp[(1) - (2)].instruction).f, &(yyvsp[(2) - (2)].operand)); }
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 357 "xpl.y"
    { process_instruction((yyvsp[(1) - (2)].instruction).cr, (yyvsp[(1) - (2)].instruction).f, &(yyvsp[(2) - (2)].operand)); }
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 360 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 0; }
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 361 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 1; }
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 362 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 2; }
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 363 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 0; }
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 364 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 1; }
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 365 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 2; }
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 368 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 3; }
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 369 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 4; }
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 370 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 7; }
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 371 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 3; }
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 372 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 4; }
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 373 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 6; }
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 374 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 5; }
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 375 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 5; }
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 376 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 10; }
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 377 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 9; }
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 378 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 14; }
    break;

  case 154:
/* Line 1792 of yacc.c  */
#line 379 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 8; }
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 380 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 13; }
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 381 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 10; }
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 382 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 9; }
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 383 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 14; }
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 384 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 8; }
    break;

  case 160:
/* Line 1792 of yacc.c  */
#line 385 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 11; }
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 386 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 12; }
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 389 "xpl.y"
    { operand_t operand; set_operand_label((yyvsp[(2) - (2)].nameval), (yyvsp[(1) - (2)].distance), &operand); process_instruction(0, 0, &operand); }
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 390 "xpl.y"
    { operand_t operand; set_operand_label((yyvsp[(5) - (5)].nameval), (yyvsp[(4) - (5)].distance), &operand); process_instruction(0, 32 + (yyvsp[(2) - (5)].f), &operand); }
    break;

  case 164:
/* Line 1792 of yacc.c  */
#line 391 "xpl.y"
    { operand_t operand; operand.operand_type = OPERAND_LITERAL; make_int_literal(0, (yyvsp[(2) - (4)].f), &operand.literal);;process_instruction(0, 40 + (yyvsp[(4) - (4)].f), &operand); }
    break;

  case 165:
/* Line 1792 of yacc.c  */
#line 392 "xpl.y"
    { process_instruction(0, 48 + (yyvsp[(2) - (3)].f), &(yyvsp[(3) - (3)].operand)); }
    break;

  case 166:
/* Line 1792 of yacc.c  */
#line 395 "xpl.y"
    { (yyval.distance) = 1; }
    break;

  case 167:
/* Line 1792 of yacc.c  */
#line 396 "xpl.y"
    { (yyval.distance) = -1; }
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 397 "xpl.y"
    { (yyval.distance) = 0; }
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 400 "xpl.y"
    { (yyval.f) = 0; }
    break;

  case 170:
/* Line 1792 of yacc.c  */
#line 401 "xpl.y"
    { (yyval.f) = 1; }
    break;

  case 171:
/* Line 1792 of yacc.c  */
#line 402 "xpl.y"
    { (yyval.f) = 2; }
    break;

  case 172:
/* Line 1792 of yacc.c  */
#line 403 "xpl.y"
    { (yyval.f) = 3; }
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 404 "xpl.y"
    { (yyval.f) = 4; }
    break;

  case 174:
/* Line 1792 of yacc.c  */
#line 405 "xpl.y"
    { (yyval.f) = 5; }
    break;

  case 175:
/* Line 1792 of yacc.c  */
#line 406 "xpl.y"
    { (yyval.f) = 6; }
    break;

  case 176:
/* Line 1792 of yacc.c  */
#line 407 "xpl.y"
    { (yyval.f) = 7; }
    break;

  case 177:
/* Line 1792 of yacc.c  */
#line 410 "xpl.y"
    { (yyval.f) = 10; }
    break;

  case 178:
/* Line 1792 of yacc.c  */
#line 411 "xpl.y"
    { (yyval.f) = 3; }
    break;

  case 180:
/* Line 1792 of yacc.c  */
#line 415 "xpl.y"
    { (yyval.operand).operand_type = OPERAND_VARIABLE_B_REL; (yyval.operand).symbol = &d_symbol; }
    break;

  case 181:
/* Line 1792 of yacc.c  */
#line 416 "xpl.y"
    { (yyval.operand).operand_type = OPERAND_VARIABLE_B_REL; (yyval.operand).symbol = find_symbol((yyvsp[(1) - (2)].nameval)); }
    break;

  case 182:
/* Line 1792 of yacc.c  */
#line 417 "xpl.y"
    { (yyval.operand).operand_type = OPERAND_VARIABLE_0_REL; (yyval.operand).symbol = &d_symbol; }
    break;

  case 183:
/* Line 1792 of yacc.c  */
#line 418 "xpl.y"
    { (yyval.operand).operand_type = OPERAND_VARIABLE_0_REL; (yyval.operand).symbol = find_symbol((yyvsp[(1) - (2)].nameval)); }
    break;

  case 184:
/* Line 1792 of yacc.c  */
#line 421 "xpl.y"
    { (yyval.operand).operand_type = OPERAND_VARIABLE; (yyval.operand).symbol = find_symbol((yyvsp[(1) - (1)].nameval)); }
    break;

  case 185:
/* Line 1792 of yacc.c  */
#line 422 "xpl.y"
    { (yyval.operand).operand_type = OPERAND_VARIABLE; (yyval.operand).symbol = &b_symbol; }
    break;

  case 186:
/* Line 1792 of yacc.c  */
#line 423 "xpl.y"
    { (yyval.operand).operand_type = OPERAND_VARIABLE; (yyval.operand).symbol = &bn_symbol; }
    break;

  case 187:
/* Line 1792 of yacc.c  */
#line 424 "xpl.y"
    { (yyval.operand).operand_type = OPERAND_LITERAL; (yyval.operand).literal = (yyvsp[(1) - (1)].literal); }
    break;

  case 189:
/* Line 1792 of yacc.c  */
#line 428 "xpl.y"
    { make_int_literal(0, (yyvsp[(1) - (1)].unsignedval), &(yyval.literal)); }
    break;

  case 190:
/* Line 1792 of yacc.c  */
#line 431 "xpl.y"
    { make_int_literal((int)(yyvsp[(1) - (2)].sign), (yyvsp[(2) - (2)].unsignedval), &(yyval.literal)); /* TODO: can't express largest negative number */ }
    break;

  case 191:
/* Line 1792 of yacc.c  */
#line 432 "xpl.y"
    { make_int_literal(0, (yyvsp[(1) - (1)].unsignedval), &(yyval.literal)); }
    break;

  case 192:
/* Line 1792 of yacc.c  */
#line 434 "xpl.y"
    { (yyval.sign) = 1; }
    break;

  case 193:
/* Line 1792 of yacc.c  */
#line 434 "xpl.y"
    { (yyval.sign) = -1; }
    break;

  case 194:
/* Line 1792 of yacc.c  */
#line 436 "xpl.y"
    { process_datavec_start((yyvsp[(4) - (6)].unsignedval)); }
    break;

  case 195:
/* Line 1792 of yacc.c  */
#line 436 "xpl.y"
    { t_uint64 d = process_datavec_end(); add_symbol(DESCRIPTOR, NOT_REL, (yyvsp[(2) - (9)].nameval), d);}
    break;

  case 198:
/* Line 1792 of yacc.c  */
#line 438 "xpl.y"
    { process_datavec_line_end(); }
    break;

  case 199:
/* Line 1792 of yacc.c  */
#line 439 "xpl.y"
    { process_datavec_literal(&(yyvsp[(1) - (1)].literal)); }
    break;

  case 201:
/* Line 1792 of yacc.c  */
#line 439 "xpl.y"
    { process_datavec_literal(&(yyvsp[(1) - (1)].literal)); }
    break;

  case 203:
/* Line 1792 of yacc.c  */
#line 440 "xpl.y"
    { process_datavec_line_repeat((unsigned int)(yyvsp[(2) - (3)].unsignedval));}
    break;

  case 204:
/* Line 1792 of yacc.c  */
#line 441 "xpl.y"
    { t_uint64 d = process_text((yyvsp[(2) - (3)].nameval), (yyvsp[(3) - (3)].stringval)); add_symbol(DESCRIPTOR, NOT_REL, (yyvsp[(2) - (3)].nameval), d); }
    break;


/* Line 1792 of yacc.c  */
#line 2878 "xpl.tab.cpp"
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
#line 444 "xpl.y"


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
