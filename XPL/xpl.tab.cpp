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
#line 160 "xpl.y"

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
#line 172 "xpl.y"

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
#line 241 "xpl.tab.cpp"
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
#line 269 "xpl.tab.cpp"

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
#define YYLAST   400

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  102
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  209
/* YYNRULES -- Number of states.  */
#define YYNSTATES  296

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
      30,    33,    36,    39,    42,    45,    48,    50,    55,    56,
      57,    65,    68,    70,    75,    77,    79,    81,    83,    85,
      87,    89,    91,    93,    97,   101,   104,   106,   108,   110,
     112,   114,   116,   119,   122,   125,   128,   131,   133,   135,
     137,   139,   141,   143,   145,   147,   149,   151,   153,   155,
     157,   159,   161,   163,   166,   169,   171,   173,   175,   177,
     179,   181,   183,   185,   187,   189,   191,   193,   195,   197,
     199,   202,   205,   207,   209,   211,   213,   215,   217,   219,
     221,   223,   225,   227,   229,   231,   233,   235,   237,   238,
     240,   242,   244,   246,   248,   250,   252,   254,   256,   258,
     260,   263,   266,   269,   272,   274,   277,   280,   283,   286,
     289,   292,   294,   296,   298,   300,   302,   305,   308,   311,
     314,   317,   320,   323,   326,   329,   332,   335,   338,   341,
     344,   347,   350,   352,   355,   358,   361,   364,   367,   369,
     372,   375,   377,   379,   381,   383,   385,   387,   389,   391,
     393,   395,   397,   399,   401,   403,   406,   412,   417,   421,
     424,   427,   429,   431,   433,   435,   437,   439,   441,   443,
     445,   447,   449,   451,   454,   457,   460,   463,   465,   467,
     469,   471,   473,   475,   478,   480,   482,   484,   485,   495,
     498,   502,   504,   505,   510,   512,   514,   518,   522,   524
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     103,     0,    -1,   104,    -1,   104,   103,    -1,    -1,    12,
     106,   105,     3,    15,     3,   107,    16,     3,    13,     3,
      -1,   147,    -1,   108,    -1,   107,   108,    -1,   112,    -1,
     112,   157,    -1,   113,   157,    -1,   120,   157,    -1,   149,
     157,    -1,   156,   157,    -1,   109,   157,    -1,   157,    -1,
      15,     3,   107,    16,    -1,    -1,    -1,    14,    21,   110,
       3,   107,   111,    16,    -1,    21,     5,    -1,   114,    -1,
     115,     6,   116,   117,    -1,    18,    -1,    19,    -1,    20,
      -1,    59,    -1,    60,    -1,    61,    -1,    22,    -1,    62,
      -1,   118,    -1,   117,     4,   118,    -1,    21,     5,   119,
      -1,    70,    22,    -1,    22,    -1,    11,    -1,   121,    -1,
     137,    -1,   130,    -1,   140,    -1,   122,   144,    -1,   124,
     144,    -1,   126,   144,    -1,   129,   144,    -1,    56,   123,
      -1,    65,    -1,    66,    -1,    67,    -1,    68,    -1,    69,
      -1,    70,    -1,    71,    -1,     6,    -1,    72,    -1,    73,
      -1,    75,    -1,    74,    -1,    76,    -1,    77,    -1,    78,
      -1,    80,    -1,    57,   125,    -1,    58,   125,    -1,    65,
      -1,    67,    -1,    68,    -1,    69,    -1,    70,    -1,    71,
      -1,     6,    -1,    72,    -1,    73,    -1,    75,    -1,    74,
      -1,    76,    -1,    77,    -1,    79,    -1,    80,    -1,    53,
     127,    -1,    54,   128,    -1,    65,    -1,    66,    -1,    67,
      -1,    68,    -1,    69,    -1,    70,    -1,    71,    -1,     6,
      -1,    72,    -1,    73,    -1,    75,    -1,    74,    -1,    76,
      -1,    77,    -1,    79,    -1,    80,    -1,    -1,    69,    -1,
      70,    -1,    71,    -1,     6,    -1,    72,    -1,    73,    -1,
      75,    -1,    74,    -1,    76,    -1,    77,    -1,    80,    -1,
      55,    65,    -1,    55,    67,    -1,    55,    68,    -1,    55,
      77,    -1,    94,    -1,   131,   144,    -1,   132,   144,    -1,
     133,   144,    -1,   134,   144,    -1,   135,   144,    -1,   136,
     144,    -1,    95,    -1,    96,    -1,    97,    -1,    98,    -1,
      99,    -1,    30,    65,    -1,    61,    65,    -1,    61,    69,
      -1,    61,    63,    -1,    59,    65,    -1,    59,    64,    -1,
      59,    69,    -1,    60,    65,    -1,    60,    69,    -1,    31,
      65,    -1,    32,    65,    -1,    33,    65,    -1,   138,   144,
      -1,   139,   145,    -1,    27,    65,    -1,    26,    65,    -1,
      83,    -1,    25,    65,    -1,    24,    65,    -1,    24,    67,
      -1,    26,    68,    -1,    29,    68,    -1,    37,    -1,    24,
      68,    -1,    28,    68,    -1,    34,    -1,    38,    -1,    39,
      -1,    40,    -1,    41,    -1,    42,    -1,    43,    -1,    44,
      -1,    45,    -1,    46,    -1,    47,    -1,    48,    -1,    49,
      -1,    50,    -1,   141,    21,    -1,    84,   142,     4,   141,
      21,    -1,    92,   143,    84,   142,    -1,    92,   143,   144,
      -1,    69,    93,    -1,    70,    93,    -1,    93,    -1,    85,
      -1,    86,    -1,    90,    -1,    87,    -1,    88,    -1,    89,
      -1,    91,    -1,    92,    -1,     6,    -1,    65,    -1,   145,
      -1,    24,    81,    -1,    21,    81,    -1,    24,    82,    -1,
      21,    82,    -1,    21,    -1,    56,    -1,    92,    -1,   146,
      -1,   147,    -1,    11,    -1,   148,    22,    -1,    22,    -1,
      69,    -1,    70,    -1,    -1,   100,    21,     7,    22,     8,
       3,   150,   151,    16,    -1,   152,     3,    -1,   152,     3,
     151,    -1,   153,    -1,    -1,   146,   154,     4,   155,    -1,
     146,    -1,   153,    -1,     9,    22,    10,    -1,   101,    21,
      23,    -1,     3,    -1,    17,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   190,   190,   190,   191,   191,   192,   194,   195,   198,
     199,   200,   201,   202,   203,   204,   205,   208,   209,   209,
     209,   211,   214,   216,   217,   217,   217,   219,   220,   221,
     222,   223,   224,   224,   225,   227,   228,   229,   232,   233,
     234,   235,   238,   239,   240,   241,   243,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   263,   264,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     284,   285,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     319,   320,   321,   322,   325,   326,   327,   328,   329,   330,
     331,   334,   335,   336,   337,   338,   340,   342,   343,   344,
     347,   348,   349,   352,   353,   356,   357,   358,   361,   362,
     365,   366,   367,   368,   369,   370,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   394,   395,   396,   397,   400,
     401,   402,   405,   406,   407,   408,   409,   410,   411,   412,
     415,   416,   419,   420,   421,   422,   423,   426,   427,   428,
     429,   432,   433,   436,   437,   439,   439,   441,   441,   442,
     442,   443,   444,   444,   444,   445,   445,   446,   448,   448
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
  "program", "statement", "block", "$@2", "$@3", "label", "declarative",
  "var_dec", "var_type", "var_rel", "var_spec_list", "var_spec",
  "displacement", "instruction", "comput", "b_ord", "b_operator", "x_ord",
  "x_operator", "a_ord", "a_operator", "au_operator", "aod_ord", "org",
  "misc_org_ord", "ms_ord", "sf_ord", "nb_ord", "xnb_ord", "misc_ord",
  "sts", "fn_1", "fn_2", "condit", "jump_spec", "cond", "b_fn", "operand",
  "simple_operand", "literal", "decimal", "sign", "table", "$@4",
  "lit_list", "lit_line", "lit_items", "$@5", "lit_repeat", "text", "sep", YY_NULL
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
     108,   108,   108,   108,   108,   108,   108,   109,   110,   111,
     109,   112,   113,   114,   115,   115,   115,   116,   116,   116,
     116,   116,   117,   117,   118,   119,   119,   119,   120,   120,
     120,   120,   121,   121,   121,   121,   122,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   124,   124,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     126,   126,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     129,   129,   129,   129,   130,   130,   130,   130,   130,   130,
     130,   131,   131,   131,   131,   131,   132,   133,   133,   133,
     134,   134,   134,   135,   135,   136,   136,   136,   137,   137,
     138,   138,   138,   138,   138,   138,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   140,   140,   140,   140,   141,
     141,   141,   142,   142,   142,   142,   142,   142,   142,   142,
     143,   143,   144,   144,   144,   144,   144,   145,   145,   145,
     145,   146,   146,   147,   147,   148,   148,   150,   149,   151,
     151,   152,   154,   153,   153,   155,   155,   156,   157,   157
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,    11,     1,     1,     2,     1,
       2,     2,     2,     2,     2,     2,     1,     4,     0,     0,
       7,     2,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     1,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     2,     2,     2,     2,     2,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     5,     4,     3,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     0,     9,     2,
       3,     1,     0,     4,     1,     1,     3,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,   194,   195,   196,     4,     6,     0,
       1,     3,     0,   193,     0,     0,     0,   208,     0,     0,
     209,    24,    25,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   151,   148,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
       0,    98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   142,     0,     0,   171,   114,   121,   122,   123,   124,
     125,     0,     0,     0,     7,     0,     9,     0,    22,     0,
       0,    38,     0,     0,     0,     0,    40,     0,     0,     0,
       0,     0,     0,    39,     0,     0,    41,     0,     0,     0,
      16,    18,     0,    21,   144,   145,   149,   143,   141,   146,
     140,   150,   147,   126,   135,   136,   137,    89,    82,    83,
      84,    85,    86,    87,    88,    90,    91,    93,    92,    94,
      95,    96,    97,    80,   102,    99,   100,   101,   103,   104,
     106,   105,   107,   108,   109,    81,   110,   111,   112,   113,
      54,    47,    48,    49,    50,    51,    52,    53,    55,    56,
      58,    57,    59,    60,    61,    62,    46,    71,    65,    66,
      67,    68,    69,    70,    72,    73,    75,    74,    76,    77,
      78,    79,    63,    64,   131,   130,   132,   133,   134,   129,
     127,   128,   169,   170,   172,   173,   175,   176,   177,   174,
     178,   179,     0,   180,   181,     0,     0,     0,     0,     8,
      15,    10,    11,     0,    12,   192,   187,     0,   188,   189,
      42,   182,   190,   191,    43,    44,    45,   115,   116,   117,
     118,   119,   120,   138,   187,   139,   165,    13,    14,     0,
       0,     0,     0,   168,     0,   207,     0,    30,    27,    28,
      29,    31,     0,   184,   186,   183,   185,     0,    17,     0,
     167,     0,     0,     0,    23,    32,    19,   166,     0,     5,
       0,     0,     0,   197,    37,    36,     0,    34,    33,    20,
       0,    35,   202,     0,     0,   201,     0,   198,   199,     0,
     200,     0,   205,   203,     0,   206
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    12,     7,    73,    74,    75,   239,   272,
      76,    77,    78,    79,   252,   264,   265,   277,    80,    81,
      82,   166,    83,   182,    84,   133,   145,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
     202,   205,   220,   221,   222,   223,     9,    98,   280,   283,
     284,   285,   286,   293,    99,   100
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -170
static const yytype_int16 yypact[] =
{
       0,    69,    37,     0,  -170,  -170,  -170,  -170,  -170,    32,
    -170,  -170,    66,  -170,    75,   113,   245,  -170,   100,   122,
    -170,  -170,  -170,  -170,   125,    85,    82,    78,    86,    68,
      87,    94,    96,    97,    99,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
     290,   159,    40,   306,   320,   320,    64,    45,    79,    73,
      77,  -170,   262,    47,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,   147,   148,     2,  -170,    89,    89,    89,  -170,   173,
      89,  -170,    57,    57,    57,    57,  -170,    57,    57,    57,
      57,    57,    57,  -170,    57,    62,  -170,   171,    89,    89,
    -170,  -170,   245,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,   176,  -170,  -170,    53,   201,   186,   216,  -170,
    -170,  -170,  -170,   258,  -170,  -170,   -57,    76,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,   217,
     157,   -55,   262,  -170,   199,  -170,   209,  -170,  -170,  -170,
    -170,  -170,   202,  -170,  -170,  -170,  -170,   245,  -170,   203,
    -170,   229,   222,   233,   238,  -170,   245,  -170,   240,  -170,
      93,   202,   228,  -170,  -170,  -170,   223,  -170,  -170,  -170,
      65,  -170,   243,   231,   264,  -170,   257,  -170,    65,    71,
    -170,   246,  -170,  -170,   271,  -170
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -170,   294,  -170,  -170,  -170,  -101,   -73,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,    36,  -170,  -170,  -170,
    -170,  -170,  -170,   253,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,    70,
      67,  -170,   -81,   215,  -169,   312,  -170,  -170,  -170,    28,
    -170,    33,  -170,  -170,  -170,   -10
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -205
static const yytype_int16 yytable[] =
{
     209,   240,   224,   225,   226,    17,   227,   228,   229,   230,
     231,   232,     1,   233,    59,    60,    18,    19,   208,    20,
      21,    22,    23,    24,   253,   254,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    10,    64,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,   203,    13,    50,    51,    52,    53,    54,
      55,    56,    57,    58,   215,   210,   211,   212,   215,    14,
     214,    59,    60,   215,   216,     4,   215,   217,   216,     4,
     291,   217,   215,   234,     4,    61,    62,     4,   237,   238,
      15,     4,    17,     4,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,   274,   146,    20,   147,   148,   218,
     187,   282,   204,   218,   188,   275,    16,   149,   218,   282,
     282,   101,     5,     6,   243,   102,     5,     6,   184,   185,
     103,     5,     6,   186,     5,     6,   111,   242,     5,     6,
       5,     6,   189,   108,   190,   219,   109,   107,   191,   219,
     104,   110,   105,   106,   219,   112,   266,   255,   256,   113,
      17,   114,   115,   276,   116,   134,   192,   209,   206,   207,
     193,    18,    19,   258,    20,    21,    22,    23,    24,   213,
     241,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,   236,   209,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,   244,   245,
      50,    51,    52,    53,    54,    55,    56,    57,    58,   246,
     257,   261,   262,   263,   267,   269,    59,    60,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   268,   270,   144,
      61,    62,   271,   273,   279,   281,  -204,   287,    17,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    18,
      19,   289,    20,    21,    22,    23,    24,   288,   294,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
     247,   295,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,   117,    11,    50,    51,
      52,    53,    54,    55,    56,    57,    58,   278,   183,   260,
     235,   259,   150,     8,    59,    60,   290,   248,   249,   250,
     251,     0,   292,     0,     0,     0,   167,     0,    61,    62,
       0,     0,     0,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,   194,   195,   196,
     197,   198,   199,   200,   201,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,     0,   131,
     132,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   168,   165,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,     0,   180,
     181
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-170)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      73,   102,    83,    84,    85,     3,    87,    88,    89,    90,
      91,    92,    12,    94,    69,    70,    14,    15,    16,    17,
      18,    19,    20,    21,    81,    82,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     0,    93,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,     6,    22,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    11,    75,    76,    77,    11,     3,
      80,    69,    70,    11,    21,    22,    11,    24,    21,    22,
       9,    24,    11,    21,    22,    83,    84,    22,    98,    99,
      15,    22,     3,    22,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    11,    65,    17,    67,    68,    56,
      65,   280,    65,    56,    69,    22,     3,    77,    56,   288,
     289,    21,    69,    70,   205,     3,    69,    70,    64,    65,
       5,    69,    70,    69,    69,    70,    68,    84,    69,    70,
      69,    70,    63,    65,    65,    92,    68,    65,    69,    92,
      65,    65,    67,    68,    92,    68,   257,    81,    82,    65,
       3,    65,    65,    70,    65,     6,    93,   240,    21,    21,
      93,    14,    15,    16,    17,    18,    19,    20,    21,     6,
       4,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    21,   266,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,     7,    23,
      53,    54,    55,    56,    57,    58,    59,    60,    61,     3,
       3,    22,    13,    21,    21,     3,    69,    70,    69,    70,
      71,    72,    73,    74,    75,    76,    77,     8,     5,    80,
      83,    84,     4,     3,    16,    22,     3,    16,     3,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    14,
      15,     4,    17,    18,    19,    20,    21,     3,    22,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      22,    10,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,     6,     3,    53,    54,
      55,    56,    57,    58,    59,    60,    61,   271,    55,   242,
      95,   241,     6,     1,    69,    70,   288,    59,    60,    61,
      62,    -1,   289,    -1,    -1,    -1,     6,    -1,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    85,    86,    87,
      88,    89,    90,    91,    92,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    79,
      80,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    65,    80,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    79,
      80
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,   103,   104,    22,    69,    70,   106,   147,   148,
       0,   103,   105,    22,     3,    15,     3,     3,    14,    15,
      17,    18,    19,    20,    21,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    69,
      70,    83,    84,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   107,   108,   109,   112,   113,   114,   115,
     120,   121,   122,   124,   126,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   149,   156,
     157,    21,     3,     5,    65,    67,    68,    65,    65,    68,
      65,    68,    68,    65,    65,    65,    65,     6,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    79,    80,   127,     6,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    80,   128,    65,    67,    68,    77,
       6,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    80,   123,     6,    65,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      79,    80,   125,   125,    64,    65,    69,    65,    69,    63,
      65,    69,    93,    93,    85,    86,    87,    88,    89,    90,
      91,    92,   142,     6,    65,   143,    21,    21,    16,   108,
     157,   157,   157,     6,   157,    11,    21,    24,    56,    92,
     144,   145,   146,   147,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,    21,   145,    21,   157,   157,   110,
     107,     4,    84,   144,     7,    23,     3,    22,    59,    60,
      61,    62,   116,    81,    82,    81,    82,     3,    16,   141,
     142,    22,    13,    21,   117,   118,   107,    21,     8,     3,
       5,     4,   111,     3,    11,    22,    70,   119,   118,    16,
     150,    22,   146,   151,   152,   153,   154,    16,     3,     4,
     151,     9,   153,   155,    22,    10
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
#line 191 "xpl.y"
    { start_segment((unsigned int)(yyvsp[(2) - (2)].signedval)); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 191 "xpl.y"
    { end_segment(); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 192 "xpl.y"
    { (yyval.signedval) = (yyvsp[(1) - (1)].literal).signed_val; }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 209 "xpl.y"
    { start_proc((yyvsp[(2) - (2)].nameval)); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 209 "xpl.y"
    { end_proc((yyvsp[(2) - (5)].nameval)); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 211 "xpl.y"
    { add_label((yyvsp[(1) - (2)].nameval)); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 216 "xpl.y"
    { add_declaration((yyvsp[(1) - (4)].vartype), (yyvsp[(3) - (4)].varrelativeto), &(yyvsp[(4) - (4)].varspeclist)); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 217 "xpl.y"
    { (yyval.vartype)=V32; }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 217 "xpl.y"
    { (yyval.vartype) = V64; }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 217 "xpl.y"
    { (yyval.vartype) = VV; }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 219 "xpl.y"
    { (yyval.varrelativeto) = NB; }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 220 "xpl.y"
    { (yyval.varrelativeto) = XNB; }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 221 "xpl.y"
    { (yyval.varrelativeto) =SF; }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 222 "xpl.y"
    { if ((yyvsp[(1) - (1)].unsignedval) != 0) yyerror("invalid relative-to"); (yyval.varrelativeto) = ZERO; }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 223 "xpl.y"
    { (yyval.varrelativeto) = STK; }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 224 "xpl.y"
    { init_var_spec_list(&(yyval.varspeclist)); add_var_spec_list(&(yyval.varspeclist), &(yyvsp[(1) - (1)].varspec)); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 224 "xpl.y"
    { add_var_spec_list(&(yyval.varspeclist), &(yyvsp[(3) - (3)].varspec)); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 225 "xpl.y"
    { (yyval.varspec).name = (yyvsp[(1) - (3)].nameval); (yyval.varspec).displacement = (int)(yyvsp[(3) - (3)].signedval); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 227 "xpl.y"
    { (yyval.signedval) = 0 - (yyvsp[(2) - (2)].unsignedval); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 228 "xpl.y"
    { (yyval.signedval) = (yyvsp[(1) - (1)].unsignedval); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 229 "xpl.y"
    { (yyval.signedval) = (yyvsp[(1) - (1)].unsignedval); }
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
#line 240 "xpl.y"
    { process_instruction((yyvsp[(1) - (2)].instruction).cr, (yyvsp[(1) - (2)].instruction).f, &(yyvsp[(2) - (2)].operand)); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 241 "xpl.y"
    { process_instruction((yyvsp[(1) - (2)].instruction).cr, (yyvsp[(1) - (2)].instruction).f, &(yyvsp[(2) - (2)].operand)); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 243 "xpl.y"
    { (yyval.instruction).cr = 1; (yyval.instruction).f = (yyvsp[(2) - (2)].f); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 245 "xpl.y"
    { (yyval.f) = 0; }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 246 "xpl.y"
    { (yyval.f) = 1; }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 247 "xpl.y"
    { (yyval.f) = 2; }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 248 "xpl.y"
    { (yyval.f) = 3; }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 249 "xpl.y"
    { (yyval.f) = 4; }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 250 "xpl.y"
    { (yyval.f) = 5; }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 251 "xpl.y"
    { (yyval.f) = 6; }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 252 "xpl.y"
    { (yyval.f) = 7; }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 253 "xpl.y"
    { (yyval.f) = 8; }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 254 "xpl.y"
    { (yyval.f) = 9; }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 255 "xpl.y"
    { (yyval.f) = 10; }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 256 "xpl.y"
    { (yyval.f) = 11; }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 257 "xpl.y"
    { (yyval.f) = 12; }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 258 "xpl.y"
    { (yyval.f) = 13; }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 259 "xpl.y"
    { (yyval.f) = 14; }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 260 "xpl.y"
    { (yyval.f) = 15; }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 263 "xpl.y"
    { (yyval.instruction).cr = 4; (yyval.instruction).f = (yyvsp[(2) - (2)].f); }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 264 "xpl.y"
    { (yyval.instruction).cr = 4; (yyval.instruction).f = (yyvsp[(2) - (2)].f); }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 267 "xpl.y"
    { (yyval.f) = 0; }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 268 "xpl.y"
    { (yyval.f) = 2; }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 269 "xpl.y"
    { (yyval.f) = 3; }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 270 "xpl.y"
    { (yyval.f) = 4; }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 271 "xpl.y"
    { (yyval.f) = 5; }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 272 "xpl.y"
    { (yyval.f) = 6; }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 273 "xpl.y"
    { (yyval.f) = 7; }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 274 "xpl.y"
    { (yyval.f) = 8; }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 275 "xpl.y"
    { (yyval.f) = 9; }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 276 "xpl.y"
    { (yyval.f) = 10; }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 277 "xpl.y"
    { (yyval.f) = 11; }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 278 "xpl.y"
    { (yyval.f) = 12; }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 279 "xpl.y"
    { (yyval.f) = 13; }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 280 "xpl.y"
    { (yyval.f) = 14; }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 281 "xpl.y"
    { (yyval.f) = 15; }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 284 "xpl.y"
    { (yyval.instruction).cr = 7; (yyval.instruction).f = (yyvsp[(2) - (2)].f); }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 285 "xpl.y"
    { (yyval.instruction).cr = 5; (yyval.instruction).f = (yyvsp[(2) - (2)].f); }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 288 "xpl.y"
    { (yyval.f) = 0; }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 289 "xpl.y"
    { (yyval.f) = 1; }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 290 "xpl.y"
    { (yyval.f) = 2; }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 291 "xpl.y"
    { (yyval.f) = 3; }
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 292 "xpl.y"
    { (yyval.f) = 4; }
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 293 "xpl.y"
    { (yyval.f) = 5; }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 294 "xpl.y"
    { (yyval.f) = 6; }
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 295 "xpl.y"
    { (yyval.f) = 7; }
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 296 "xpl.y"
    { (yyval.f) = 8; }
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 297 "xpl.y"
    { (yyval.f) = 9; }
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 298 "xpl.y"
    { (yyval.f) = 10; }
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 299 "xpl.y"
    { (yyval.f) = 11; }
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 300 "xpl.y"
    { (yyval.f) = 12; }
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 301 "xpl.y"
    { (yyval.f) = 13; }
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 302 "xpl.y"
    { (yyval.f) = 14; }
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 303 "xpl.y"
    { (yyval.f) = 15; }
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 306 "xpl.y"
    { (yyval.f) = 4; }
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 307 "xpl.y"
    { (yyval.f) = 5; }
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 308 "xpl.y"
    { (yyval.f) = 6; }
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 309 "xpl.y"
    { (yyval.f) = 7; }
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 310 "xpl.y"
    { (yyval.f) = 8; }
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 311 "xpl.y"
    { (yyval.f) = 9; }
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 312 "xpl.y"
    { (yyval.f) = 10; }
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 313 "xpl.y"
    { (yyval.f) = 11; }
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 314 "xpl.y"
    { (yyval.f) = 12; }
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 315 "xpl.y"
    { (yyval.f) = 13; }
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 316 "xpl.y"
    { (yyval.f) = 15; }
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 319 "xpl.y"
    { (yyval.instruction).cr = 5; (yyval.instruction).f = 0; }
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 320 "xpl.y"
    { (yyval.instruction).cr = 5; (yyval.instruction).f = 2; }
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 321 "xpl.y"
    { (yyval.instruction).cr = 5; (yyval.instruction).f = 3; }
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 322 "xpl.y"
    { (yyval.instruction).cr = 6; (yyval.instruction).f = 12; }
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 325 "xpl.y"
    { emit_extended_instruction(0, 5, 2, 4); }
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 326 "xpl.y"
    { process_instruction(0, (yyvsp[(1) - (2)].f), &(yyvsp[(2) - (2)].operand)); }
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 327 "xpl.y"
    { process_instruction(0, (yyvsp[(1) - (2)].f), &(yyvsp[(2) - (2)].operand)); }
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 328 "xpl.y"
    { process_instruction(0, (yyvsp[(1) - (2)].f), &(yyvsp[(2) - (2)].operand)); }
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
#line 334 "xpl.y"
    { (yyval.f) = 1; }
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 335 "xpl.y"
    { set_operand_label_context(JUMP_ABSOLUTE); (yyval.f) = 4; }
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 336 "xpl.y"
    { set_operand_label_context(JUMP_ABSOLUTE); (yyval.f) = 4; }
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 337 "xpl.y"
    { set_operand_label_context(JUMP_RELATIVE_LONG); (yyval.f) = 15; }
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 338 "xpl.y"
    { (yyval.f) = 19; }
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 340 "xpl.y"
    { (yyval.f) = 16; }
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 342 "xpl.y"
    { (yyval.f) = 24; }
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 343 "xpl.y"
    { (yyval.f) = 25; }
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 344 "xpl.y"
    { (yyval.f) = 26; }
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 347 "xpl.y"
    { (yyval.f) = 28; }
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 348 "xpl.y"
    { (yyval.f) = 29; }
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 349 "xpl.y"
    { (yyval.f) = 30; }
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 352 "xpl.y"
    { (yyval.f) = 20; }
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 353 "xpl.y"
    { (yyval.f) = 22; }
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 356 "xpl.y"
    { (yyval.f) = 21; }
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 357 "xpl.y"
    { (yyval.f) = 17; }
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 358 "xpl.y"
    { (yyval.f) = 18; }
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 361 "xpl.y"
    { process_instruction((yyvsp[(1) - (2)].instruction).cr, (yyvsp[(1) - (2)].instruction).f, &(yyvsp[(2) - (2)].operand)); }
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 362 "xpl.y"
    { process_instruction((yyvsp[(1) - (2)].instruction).cr, (yyvsp[(1) - (2)].instruction).f, &(yyvsp[(2) - (2)].operand)); }
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 365 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 0; }
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 366 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 1; }
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 367 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 2; }
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 368 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 0; }
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 369 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 1; }
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 370 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 2; }
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 373 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 3; }
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 374 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 4; }
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 375 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 7; }
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 376 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 3; }
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 377 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 4; }
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 378 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 6; }
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 379 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 5; }
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 380 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 5; }
    break;

  case 154:
/* Line 1792 of yacc.c  */
#line 381 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 10; }
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 382 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 9; }
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 383 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 14; }
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 384 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 8; }
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 385 "xpl.y"
    { (yyval.instruction).cr = 3; (yyval.instruction).f = 13; }
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 386 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 10; }
    break;

  case 160:
/* Line 1792 of yacc.c  */
#line 387 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 9; }
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 388 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 14; }
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 389 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 8; }
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 390 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 11; }
    break;

  case 164:
/* Line 1792 of yacc.c  */
#line 391 "xpl.y"
    { (yyval.instruction).cr = 2; (yyval.instruction).f = 12; }
    break;

  case 165:
/* Line 1792 of yacc.c  */
#line 394 "xpl.y"
    { operand_t operand; set_operand_label((yyvsp[(2) - (2)].nameval), (yyvsp[(1) - (2)].jumptype), &operand); process_instruction(0, 0, &operand); }
    break;

  case 166:
/* Line 1792 of yacc.c  */
#line 395 "xpl.y"
    { operand_t operand; set_operand_label((yyvsp[(5) - (5)].nameval), (yyvsp[(4) - (5)].jumptype), &operand); process_instruction(0, 32 + (yyvsp[(2) - (5)].f), &operand); }
    break;

  case 167:
/* Line 1792 of yacc.c  */
#line 396 "xpl.y"
    { operand_t operand; operand.operand_type = OPERAND_LITERAL; make_int_literal(0, (yyvsp[(2) - (4)].f), &operand.literal);;process_instruction(0, 40 + (yyvsp[(4) - (4)].f), &operand); }
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 397 "xpl.y"
    { process_instruction(0, 48 + (yyvsp[(2) - (3)].f), &(yyvsp[(3) - (3)].operand)); }
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 400 "xpl.y"
    { (yyval.jumptype) = JUMP_RELATIVE_LONG; }
    break;

  case 170:
/* Line 1792 of yacc.c  */
#line 401 "xpl.y"
    { (yyval.jumptype) = JUMP_RELATIVE_SHORT; }
    break;

  case 171:
/* Line 1792 of yacc.c  */
#line 402 "xpl.y"
    { (yyval.jumptype) = JUMP_RELATIVE_DEFAULT; }
    break;

  case 172:
/* Line 1792 of yacc.c  */
#line 405 "xpl.y"
    { (yyval.f) = 0; }
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 406 "xpl.y"
    { (yyval.f) = 1; }
    break;

  case 174:
/* Line 1792 of yacc.c  */
#line 407 "xpl.y"
    { (yyval.f) = 2; }
    break;

  case 175:
/* Line 1792 of yacc.c  */
#line 408 "xpl.y"
    { (yyval.f) = 3; }
    break;

  case 176:
/* Line 1792 of yacc.c  */
#line 409 "xpl.y"
    { (yyval.f) = 4; }
    break;

  case 177:
/* Line 1792 of yacc.c  */
#line 410 "xpl.y"
    { (yyval.f) = 5; }
    break;

  case 178:
/* Line 1792 of yacc.c  */
#line 411 "xpl.y"
    { (yyval.f) = 6; }
    break;

  case 179:
/* Line 1792 of yacc.c  */
#line 412 "xpl.y"
    { (yyval.f) = 7; }
    break;

  case 180:
/* Line 1792 of yacc.c  */
#line 415 "xpl.y"
    { (yyval.f) = 10; }
    break;

  case 181:
/* Line 1792 of yacc.c  */
#line 416 "xpl.y"
    { (yyval.f) = 3; }
    break;

  case 183:
/* Line 1792 of yacc.c  */
#line 420 "xpl.y"
    { (yyval.operand).operand_type = OPERAND_VARIABLE_B_REL; (yyval.operand).symbol = &d_symbol; }
    break;

  case 184:
/* Line 1792 of yacc.c  */
#line 421 "xpl.y"
    { (yyval.operand).operand_type = OPERAND_VARIABLE_B_REL; (yyval.operand).symbol = find_symbol((yyvsp[(1) - (2)].nameval)); }
    break;

  case 185:
/* Line 1792 of yacc.c  */
#line 422 "xpl.y"
    { (yyval.operand).operand_type = OPERAND_VARIABLE_0_REL; (yyval.operand).symbol = &d_symbol; }
    break;

  case 186:
/* Line 1792 of yacc.c  */
#line 423 "xpl.y"
    { (yyval.operand).operand_type = OPERAND_VARIABLE_0_REL; (yyval.operand).symbol = find_symbol((yyvsp[(1) - (2)].nameval)); }
    break;

  case 187:
/* Line 1792 of yacc.c  */
#line 426 "xpl.y"
    { set_operand((yyvsp[(1) - (1)].nameval), &(yyval.operand)); }
    break;

  case 188:
/* Line 1792 of yacc.c  */
#line 427 "xpl.y"
    { (yyval.operand).operand_type = OPERAND_VARIABLE; (yyval.operand).symbol = &b_symbol; }
    break;

  case 189:
/* Line 1792 of yacc.c  */
#line 428 "xpl.y"
    { (yyval.operand).operand_type = OPERAND_VARIABLE; (yyval.operand).symbol = &bn_symbol; }
    break;

  case 190:
/* Line 1792 of yacc.c  */
#line 429 "xpl.y"
    { (yyval.operand).operand_type = OPERAND_LITERAL; (yyval.operand).literal = (yyvsp[(1) - (1)].literal); }
    break;

  case 192:
/* Line 1792 of yacc.c  */
#line 433 "xpl.y"
    { make_int_literal(0, (yyvsp[(1) - (1)].unsignedval), &(yyval.literal)); }
    break;

  case 193:
/* Line 1792 of yacc.c  */
#line 436 "xpl.y"
    { make_int_literal((int)(yyvsp[(1) - (2)].sign), (yyvsp[(2) - (2)].unsignedval), &(yyval.literal)); /* TODO: can't express largest negative number */ }
    break;

  case 194:
/* Line 1792 of yacc.c  */
#line 437 "xpl.y"
    { make_int_literal(0, (yyvsp[(1) - (1)].unsignedval), &(yyval.literal)); }
    break;

  case 195:
/* Line 1792 of yacc.c  */
#line 439 "xpl.y"
    { (yyval.sign) = 1; }
    break;

  case 196:
/* Line 1792 of yacc.c  */
#line 439 "xpl.y"
    { (yyval.sign) = -1; }
    break;

  case 197:
/* Line 1792 of yacc.c  */
#line 441 "xpl.y"
    { process_datavec_start((yyvsp[(4) - (6)].unsignedval)); }
    break;

  case 198:
/* Line 1792 of yacc.c  */
#line 441 "xpl.y"
    { t_uint64 d = process_datavec_end(); add_symbol(DESCRIPTOR, NOT_REL, (yyvsp[(2) - (9)].nameval), d);}
    break;

  case 201:
/* Line 1792 of yacc.c  */
#line 443 "xpl.y"
    { process_datavec_line_end(); }
    break;

  case 202:
/* Line 1792 of yacc.c  */
#line 444 "xpl.y"
    { process_datavec_literal(&(yyvsp[(1) - (1)].literal)); }
    break;

  case 204:
/* Line 1792 of yacc.c  */
#line 444 "xpl.y"
    { process_datavec_literal(&(yyvsp[(1) - (1)].literal)); }
    break;

  case 206:
/* Line 1792 of yacc.c  */
#line 445 "xpl.y"
    { process_datavec_line_repeat((unsigned int)(yyvsp[(2) - (3)].unsignedval));}
    break;

  case 207:
/* Line 1792 of yacc.c  */
#line 446 "xpl.y"
    { t_uint64 d = process_text((yyvsp[(2) - (3)].nameval), (yyvsp[(3) - (3)].stringval)); add_symbol(DESCRIPTOR, NOT_REL, (yyvsp[(2) - (3)].nameval), d); }
    break;


/* Line 1792 of yacc.c  */
#line 2875 "xpl.tab.cpp"
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
#line 449 "xpl.y"


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
