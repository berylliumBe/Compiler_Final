/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     CHAR = 259,
     FLOAT = 260,
     DOUBLE = 261,
     IF = 262,
     ELSE = 263,
     WHILE = 264,
     FOR = 265,
     TIDENTIFIER = 266,
     TINTEGER = 267,
     TDOUBLE = 268,
     TCHAR = 269,
     TCEQ = 270,
     TCNE = 271,
     TCLT = 272,
     TCLE = 273,
     TCGT = 274,
     TCGE = 275,
     TEQUAL = 276,
     TLPAREN = 277,
     TRPAREN = 278,
     TLBRACE = 279,
     TRBRACE = 280,
     TCOMMA = 281,
     TDOT = 282,
     TSEMICOLON = 283,
     TPLUS = 284,
     TMINUS = 285,
     TMUL = 286,
     TDIV = 287,
     TMOD = 288,
     TSADD = 289,
     TSMINUS = 290,
     TREAD = 291,
     TWRITE = 292,
     TNOT = 293,
     TAND = 294,
     TOR = 295,
     TBNOT = 296,
     TBAND = 297,
     TBOR = 298,
     TBXOR = 299,
     TBLEFT = 300,
     TBRIGHT = 301,
     TRETURN = 302,
     TMINASS = 303,
     TADDASS = 304,
     TMODASS = 305,
     TDIVASS = 306,
     TMULASS = 307,
     TBORASS = 308,
     TBXORASS = 309,
     TBANDASS = 310,
     TBRIGHTASS = 311,
     TBLEFTASS = 312
   };
#endif
/* Tokens.  */
#define INT 258
#define CHAR 259
#define FLOAT 260
#define DOUBLE 261
#define IF 262
#define ELSE 263
#define WHILE 264
#define FOR 265
#define TIDENTIFIER 266
#define TINTEGER 267
#define TDOUBLE 268
#define TCHAR 269
#define TCEQ 270
#define TCNE 271
#define TCLT 272
#define TCLE 273
#define TCGT 274
#define TCGE 275
#define TEQUAL 276
#define TLPAREN 277
#define TRPAREN 278
#define TLBRACE 279
#define TRBRACE 280
#define TCOMMA 281
#define TDOT 282
#define TSEMICOLON 283
#define TPLUS 284
#define TMINUS 285
#define TMUL 286
#define TDIV 287
#define TMOD 288
#define TSADD 289
#define TSMINUS 290
#define TREAD 291
#define TWRITE 292
#define TNOT 293
#define TAND 294
#define TOR 295
#define TBNOT 296
#define TBAND 297
#define TBOR 298
#define TBXOR 299
#define TBLEFT 300
#define TBRIGHT 301
#define TRETURN 302
#define TMINASS 303
#define TADDASS 304
#define TMODASS 305
#define TDIVASS 306
#define TMULASS 307
#define TBORASS 308
#define TBXORASS 309
#define TBANDASS 310
#define TBRIGHTASS 311
#define TBLEFTASS 312




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

    #include <iostream>
    #include "node.h"
    #include "stdio.h"
    #include <map>
    #include <assert.h>
    #define YYDEBUG 1
    #define YYERROR_VERBOSE

    Node *RootNode; /* the top level root node of our final AST */

    extern int yylex();
    void yyerror(const char *s) { printf("ERROR: %sn", s); }

    std::map<std::string, std::string> IdTable; // Id, OrigType

    std::string GetType(std::string ori_type) {
      if (ori_type == "int" || ori_type == "char") {
        return "int_char";
      }
      else if (ori_type == "double" || ori_type == "float") {
        return "double_float";
      }
      return "";
    }

    std::string MoreAccurate(std::string t1, std::string t2) {
      if (t1 == "double_float") {
        return "double_float";
      } else if (t2 == "double_float") {
        return "double_float";
      }
      else {
        return "int_char";
      }
    }


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 41 "parser.y"
{
    Node *start;
    Node *stmt;
    Node *stmts;
    Node *comp_stmt;
    Node *type;
    Node *args_list;
    Node *arg;
    Node *factor;
    Node *term;
    Node *expr;
    Node *expr_alg;
    Node *expr_and_decl;
    Node *identifier;
    Node *decl;
    char *str;
}
/* Line 193 of yacc.c.  */
#line 266 "parser.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 279 "parser.cpp"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   227

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNRULES -- Number of states.  */
#define YYNSTATES  173

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

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
      55,    56,    57
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    13,    15,    18,    19,    21,    23,
      31,    34,    36,    38,    44,    50,    56,    66,    70,    76,
      84,    87,    90,    92,    94,    96,    98,   100,   104,   108,
     110,   114,   118,   122,   126,   130,   134,   138,   142,   146,
     150,   154,   156,   158,   160,   161,   165,   167,   171,   173,
     177,   179,   183,   185,   189,   191,   195,   199,   201,   205,
     209,   213,   217,   219,   223,   227,   229,   233,   237,   239,
     243,   247,   251,   253,   256,   259,   262,   265,   268,   271,
     274,   277,   279,   283,   285,   287,   289,   291,   293
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      59,     0,    -1,     3,    11,    22,    23,    60,    -1,    24,
      61,    25,    -1,    28,    -1,    62,    61,    -1,    -1,    63,
      -1,    64,    -1,     7,    22,    70,    23,    63,     8,    63,
      -1,    70,    28,    -1,    65,    -1,    60,    -1,    36,    22,
      85,    23,    28,    -1,    37,    22,    70,    23,    28,    -1,
       9,    22,    70,    23,    63,    -1,    10,    22,    71,    28,
      71,    28,    71,    23,    62,    -1,    47,    70,    28,    -1,
       7,    22,    70,    23,    62,    -1,     7,    22,    70,    23,
      63,     8,    64,    -1,    66,    28,    -1,    67,    68,    -1,
       3,    -1,     4,    -1,     5,    -1,     6,    -1,    69,    -1,
      69,    26,    68,    -1,    85,    21,    70,    -1,    85,    -1,
      83,    21,    70,    -1,    83,    49,    70,    -1,    83,    48,
      70,    -1,    83,    52,    70,    -1,    83,    51,    70,    -1,
      83,    50,    70,    -1,    83,    55,    70,    -1,    83,    54,
      70,    -1,    83,    53,    70,    -1,    83,    57,    70,    -1,
      83,    56,    70,    -1,    72,    -1,    70,    -1,    66,    -1,
      -1,    73,    40,    72,    -1,    73,    -1,    74,    39,    73,
      -1,    74,    -1,    75,    43,    74,    -1,    75,    -1,    76,
      44,    75,    -1,    76,    -1,    77,    42,    76,    -1,    77,
      -1,    78,    15,    77,    -1,    78,    16,    77,    -1,    78,
      -1,    79,    17,    78,    -1,    79,    19,    78,    -1,    79,
      18,    78,    -1,    79,    20,    78,    -1,    79,    -1,    80,
      45,    79,    -1,    80,    46,    79,    -1,    80,    -1,    80,
      29,    81,    -1,    80,    30,    81,    -1,    81,    -1,    81,
      31,    82,    -1,    81,    32,    82,    -1,    81,    33,    82,
      -1,    82,    -1,    30,    12,    -1,    29,    12,    -1,    34,
      85,    -1,    35,    85,    -1,    85,    34,    -1,    85,    35,
      -1,    38,    83,    -1,    41,    83,    -1,    83,    -1,    22,
      70,    23,    -1,    84,    -1,    85,    -1,    12,    -1,    13,
      -1,    14,    -1,    11,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   108,   109,   112,   116,   119,   120,   123,
     131,   133,   134,   135,   138,   141,   146,   155,   159,   165,
     175,   178,   196,   197,   198,   199,   202,   204,   211,   215,
     220,   225,   230,   235,   240,   245,   250,   255,   260,   265,
     270,   275,   278,   279,   280,   283,   300,   303,   320,   323,
     335,   338,   350,   353,   365,   368,   383,   398,   401,   416,
     431,   446,   461,   464,   476,   488,   491,   506,   521,   524,
     539,   554,   566,   569,   571,   573,   577,   581,   585,   589,
     602,   611,   614,   615,   618,   619,   621,   623,   627
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "CHAR", "FLOAT", "DOUBLE", "IF",
  "ELSE", "WHILE", "FOR", "TIDENTIFIER", "TINTEGER", "TDOUBLE", "TCHAR",
  "TCEQ", "TCNE", "TCLT", "TCLE", "TCGT", "TCGE", "TEQUAL", "TLPAREN",
  "TRPAREN", "TLBRACE", "TRBRACE", "TCOMMA", "TDOT", "TSEMICOLON", "TPLUS",
  "TMINUS", "TMUL", "TDIV", "TMOD", "TSADD", "TSMINUS", "TREAD", "TWRITE",
  "TNOT", "TAND", "TOR", "TBNOT", "TBAND", "TBOR", "TBXOR", "TBLEFT",
  "TBRIGHT", "TRETURN", "TMINASS", "TADDASS", "TMODASS", "TDIVASS",
  "TMULASS", "TBORASS", "TBXORASS", "TBANDASS", "TBRIGHTASS", "TBLEFTASS",
  "$accept", "start", "comp_stmt", "stmts", "stmt", "matched_stmt",
  "open_stmt", "decl_stmt", "decl", "type", "args_list", "arg", "expr",
  "optional_expr", "expr12", "expr11", "expr10", "expr9", "expr8", "expr7",
  "expr6", "expr5", "expr4", "expr3", "expr2", "expr1", "expr0",
  "identifier", 0
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
     305,   306,   307,   308,   309,   310,   311,   312
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    60,    60,    61,    61,    62,    62,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    64,    64,
      65,    66,    67,    67,    67,    67,    68,    68,    69,    69,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    71,    71,    72,    72,    73,    73,    74,
      74,    75,    75,    76,    76,    77,    77,    77,    78,    78,
      78,    78,    78,    79,    79,    79,    80,    80,    80,    81,
      81,    81,    81,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    83,    83,    84,    84,    84,    84,    85
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     1,     2,     0,     1,     1,     7,
       2,     1,     1,     5,     5,     5,     9,     3,     5,     7,
       2,     2,     1,     1,     1,     1,     1,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     0,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     3,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     6,     4,     2,
      22,    23,    24,    25,     0,     0,     0,    88,    85,    86,
      87,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,     0,     6,     7,     8,    11,     0,     0,     0,
      41,    46,    48,    50,    52,    54,    57,    62,    65,    68,
      72,    81,    83,    84,     0,     0,    44,     0,    74,    73,
      75,    76,     0,     0,    79,    84,    80,     0,     3,     5,
      20,    21,    26,    29,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,    78,     0,     0,    43,    42,
       0,    82,     0,     0,    17,     0,     0,    45,    81,    47,
      49,    51,    53,    55,    56,    58,    60,    59,    61,    66,
      67,    63,    64,    69,    70,    71,    30,    32,    31,    35,
      34,    33,    38,    37,    36,    40,    39,     0,     0,    44,
       0,     0,    27,    28,    18,     7,     0,    15,     0,    13,
      14,     0,     0,    44,     9,    19,     0,     0,     0,     0,
       0,    16,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    31,    32,    33,    34,    35,    36,    37,    38,
      71,    72,    39,   110,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -140
static const yytype_int16 yypact[] =
{
      14,     8,    25,     7,  -140,    18,     0,   109,  -140,  -140,
    -140,  -140,  -140,  -140,    69,    70,    95,  -140,  -140,  -140,
    -140,   179,   117,   118,   121,   121,   112,   114,   113,   113,
     179,  -140,   115,   109,  -140,  -140,  -140,   120,   121,   138,
    -140,   127,   110,   125,   131,   129,    21,    66,   -19,    78,
    -140,    48,  -140,    11,   179,   179,     9,   146,  -140,  -140,
    -140,  -140,   121,   179,  -140,  -140,  -140,   151,  -140,  -140,
    -140,  -140,   154,   160,  -140,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,  -140,  -140,   165,   173,  -140,  -140,
     169,  -140,   176,   177,  -140,   121,   179,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,    78,
      78,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,   109,   148,     9,
     174,   175,  -140,  -140,  -140,   196,   183,  -140,   178,  -140,
    -140,   109,   179,     9,  -140,  -140,   184,   187,   148,   109,
     203,  -140,   148
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -140,  -140,   206,   182,  -139,    26,    55,  -140,   -55,  -140,
     103,  -140,   -21,  -131,   144,   145,   147,   149,   143,   -32,
       5,   -18,  -140,    20,    73,   -24,  -140,   -22
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      57,   108,    60,    61,    64,    66,    65,    65,   154,    67,
      86,    87,    10,    11,    12,    13,    73,     1,   158,     3,
      17,    18,    19,    20,     7,     4,    88,    89,     8,     5,
     171,    21,   167,   106,   107,   109,    80,    81,    22,    23,
     112,     6,   113,    24,    25,   104,   105,    28,   123,   124,
      29,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,    93,
     131,   132,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    82,    83,    84,    85,   125,   126,   127,
     128,    54,    55,    73,   108,   153,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   129,   130,   108,    90,
      91,    92,    10,    11,    12,    13,    14,    56,    15,    16,
      17,    18,    19,    20,    17,    18,    19,    20,   109,    58,
      59,    21,    17,     7,    62,    21,    63,     8,    22,    23,
      68,   166,   109,    24,    25,    26,    27,    28,    70,    76,
      29,    10,    11,    12,    13,   156,    30,    15,    16,    17,
      18,    19,    20,   133,   134,   135,    74,    75,    77,   111,
      21,    79,     7,   155,   157,    78,     8,    22,    23,   114,
     115,   116,    24,    25,    26,    27,    28,   164,   147,    29,
      17,    18,    19,    20,   170,    30,   148,   149,   164,   150,
     151,    21,   159,   160,   161,   162,   163,   168,    22,    23,
     169,   172,     9,    24,    25,    69,   165,    28,   152,   117,
      29,   119,   122,     0,   120,     0,     0,   121
};

static const yytype_int16 yycheck[] =
{
      21,    56,    24,    25,    28,    29,    28,    29,   147,    30,
      29,    30,     3,     4,     5,     6,    38,     3,   149,    11,
      11,    12,    13,    14,    24,     0,    45,    46,    28,    22,
     169,    22,   163,    54,    55,    56,    15,    16,    29,    30,
      62,    23,    63,    34,    35,    34,    35,    38,    80,    81,
      41,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    21,
      88,    89,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    17,    18,    19,    20,    82,    83,    84,
      85,    22,    22,   115,   149,   116,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    86,    87,   163,    31,
      32,    33,     3,     4,     5,     6,     7,    22,     9,    10,
      11,    12,    13,    14,    11,    12,    13,    14,   149,    12,
      12,    22,    11,    24,    22,    22,    22,    28,    29,    30,
      25,   162,   163,    34,    35,    36,    37,    38,    28,    39,
      41,     3,     4,     5,     6,     7,    47,     9,    10,    11,
      12,    13,    14,    90,    91,    92,    28,    40,    43,    23,
      22,    42,    24,   147,   148,    44,    28,    29,    30,    28,
      26,    21,    34,    35,    36,    37,    38,   161,    23,    41,
      11,    12,    13,    14,   168,    47,    23,    28,   172,    23,
      23,    22,    28,    28,     8,    22,    28,    23,    29,    30,
      23,     8,     6,    34,    35,    33,   161,    38,   115,    75,
      41,    76,    79,    -1,    77,    -1,    -1,    78
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    59,    11,     0,    22,    23,    24,    28,    60,
       3,     4,     5,     6,     7,     9,    10,    11,    12,    13,
      14,    22,    29,    30,    34,    35,    36,    37,    38,    41,
      47,    60,    61,    62,    63,    64,    65,    66,    67,    70,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    22,    22,    22,    70,    12,    12,
      85,    85,    22,    22,    83,    85,    83,    70,    25,    61,
      28,    68,    69,    85,    28,    40,    39,    43,    44,    42,
      15,    16,    17,    18,    19,    20,    29,    30,    45,    46,
      31,    32,    33,    21,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    34,    35,    70,    70,    66,    70,
      71,    23,    85,    70,    28,    26,    21,    72,    83,    73,
      74,    75,    76,    77,    77,    78,    78,    78,    78,    81,
      81,    79,    79,    82,    82,    82,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    23,    23,    28,
      23,    23,    68,    70,    62,    63,     7,    63,    71,    28,
      28,     8,    22,    28,    63,    64,    70,    71,    23,    23,
      63,    62,     8
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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


/* Prevent warnings from -Wmissing-prototypes.  */

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
        case 2:
#line 102 "parser.y"
    {
                                     (yyval.stmt) = new Node("START");
                                     (yyval.stmt)->Children.push_back((yyvsp[(5) - (5)].stmt));
                                     RootNode = (yyval.stmt); ;}
    break;

  case 3:
#line 108 "parser.y"
    { (yyval.stmt) = (yyvsp[(2) - (3)].stmt); ;}
    break;

  case 4:
#line 109 "parser.y"
    { (yyval.stmt) = new Node("SEMICOLON"); ;}
    break;

  case 5:
#line 112 "parser.y"
    { (yyval.stmt) = (yyvsp[(2) - (2)].stmt);
                     std::vector<Node*>::iterator it;
                     it = (yyval.stmt)->Children.begin();
                     (yyval.stmt)->Children.insert(it, (yyvsp[(1) - (2)].stmt)); ;}
    break;

  case 6:
#line 116 "parser.y"
    { (yyval.stmt) = new Node("COMP_STMT"); ;}
    break;

  case 7:
#line 119 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 8:
#line 120 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 9:
#line 123 "parser.y"
    {
                                    (yyval.stmt) = new Node("STMT", "IF");
                                    (yyvsp[(3) - (7)].stmt)->NodeInfo = "CONDITION";
                                    (yyvsp[(5) - (7)].stmt)->NodeInfo = "IF BRANCH";
                                    (yyvsp[(7) - (7)].stmt)->NodeInfo = "ELSE BRANCH";
                                    (yyval.stmt)->Children.push_back((yyvsp[(3) - (7)].stmt));
                                    (yyval.stmt)->Children.push_back((yyvsp[(5) - (7)].stmt));
                                    (yyval.stmt)->Children.push_back((yyvsp[(7) - (7)].stmt)); ;}
    break;

  case 10:
#line 131 "parser.y"
    { (yyval.stmt) = new Node("STMT", "EXPR");
                                 (yyval.stmt)->Children.push_back((yyvsp[(1) - (2)].expr)); ;}
    break;

  case 11:
#line 133 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 12:
#line 134 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 13:
#line 135 "parser.y"
    {
                                    (yyval.stmt) = new Node("STMT", "READ");
                                    (yyval.stmt)->Children.push_back((yyvsp[(3) - (5)].expr)); ;}
    break;

  case 14:
#line 138 "parser.y"
    {
                                    (yyval.stmt) = new Node("STMT", "WRITE");
                                    (yyval.stmt)->Children.push_back((yyvsp[(3) - (5)].expr)); ;}
    break;

  case 15:
#line 141 "parser.y"
    {
                                    (yyval.stmt) = new Node("STMT", "WHILE");
                                    (yyvsp[(3) - (5)].expr)->NodeInfo = "CONDITION";
                                    (yyval.stmt)->Children.push_back((yyvsp[(3) - (5)].expr));
                                    (yyval.stmt)->Children.push_back((yyvsp[(5) - (5)].stmt)); ;}
    break;

  case 16:
#line 146 "parser.y"
    {
                                    (yyval.stmt) = new Node("STMT", "FOR");
                                    (yyvsp[(3) - (9)].expr)->NodeInfo = "START";
                                    (yyvsp[(5) - (9)].expr)->NodeInfo = "CONDITION";
                                    (yyvsp[(7) - (9)].expr)->NodeInfo = "ITER_ACTION";
                                    (yyval.stmt)->Children.push_back((yyvsp[(3) - (9)].expr));
                                    (yyval.stmt)->Children.push_back((yyvsp[(5) - (9)].expr));
                                    (yyval.stmt)->Children.push_back((yyvsp[(7) - (9)].expr));
                                    (yyval.stmt)->Children.push_back((yyvsp[(9) - (9)].stmt)); ;}
    break;

  case 17:
#line 155 "parser.y"
    { (yyval.stmt) = new Node("STMT", "RET");
                              (yyval.stmt)->Children.push_back((yyvsp[(2) - (3)].expr)); ;}
    break;

  case 18:
#line 159 "parser.y"
    {
                                    (yyval.stmt) = new Node("STMT", "IF");
                                    (yyvsp[(3) - (5)].stmt)->NodeInfo = "CONDITION";
                                    (yyvsp[(5) - (5)].stmt)->NodeInfo = "IF BRANCH";
                                    (yyval.stmt)->Children.push_back((yyvsp[(3) - (5)].stmt));
                                    (yyval.stmt)->Children.push_back((yyvsp[(5) - (5)].stmt)); ;}
    break;

  case 19:
#line 165 "parser.y"
    {
                                    (yyval.stmt) = new Node("STMT", "IF");
                                    (yyvsp[(3) - (7)].stmt)->NodeInfo = "CONDITION";
                                    (yyvsp[(5) - (7)].stmt)->NodeInfo = "IF BRANCH";
                                    (yyvsp[(7) - (7)].stmt)->NodeInfo = "ELSE BRANCH";
                                    (yyval.stmt)->Children.push_back((yyvsp[(3) - (7)].stmt));
                                    (yyval.stmt)->Children.push_back((yyvsp[(5) - (7)].stmt));
                                    (yyval.stmt)->Children.push_back((yyvsp[(7) - (7)].stmt)); ;}
    break;

  case 20:
#line 175 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (2)].expr); ;}
    break;

  case 21:
#line 178 "parser.y"
    { (yyval.expr) = new Node("STMT", "DECL");
                        std::string tOrig = (yyvsp[(1) - (2)].type)->NodeValue;
                        std::string t = GetType(tOrig);
                        for (auto arg : (yyvsp[(2) - (2)].args_list)->Children) {
                          std::string var = arg->Children[0]->NodeValue;
                          if (IdTable.find(var) == IdTable.end()) {
                            IdTable[var] = tOrig;
                            arg->Children[0]->type = t;
                            arg->Children[0]->NodeInfo = tOrig;
                          }
                          else {
                            std::cout << "Error: Replicated Declaration: " << var << std::endl;
                          }
                       }
                       (yyval.expr)->Children.push_back((yyvsp[(1) - (2)].type));
                       (yyval.expr)->Children.push_back((yyvsp[(2) - (2)].expr)); ;}
    break;

  case 22:
#line 196 "parser.y"
    { (yyval.type) = new Node("TYPE", "int"); ;}
    break;

  case 23:
#line 197 "parser.y"
    { (yyval.type) = new Node("TYPE", "char"); ;}
    break;

  case 24:
#line 198 "parser.y"
    { (yyval.type) = new Node("TYPE", "float"); ;}
    break;

  case 25:
#line 199 "parser.y"
    { (yyval.type) = new Node("TYPE", "double"); ;}
    break;

  case 26:
#line 202 "parser.y"
    { (yyval.args_list) = new Node("ARGS_LIST");
                  (yyval.args_list)->Children.push_back((yyvsp[(1) - (1)].expr)); ;}
    break;

  case 27:
#line 204 "parser.y"
    {
                          (yyval.args_list) = (yyvsp[(3) - (3)].args_list);
                          std::vector<Node*>::iterator it;
                          it = (yyval.args_list)->Children.begin();
                          (yyval.args_list)->Children.insert(it, (yyvsp[(1) - (3)].expr)); ;}
    break;

  case 28:
#line 211 "parser.y"
    { (yyval.expr) = new Node("EXPR", "DECL_ASSIGN");
                               assert((yyvsp[(1) - (3)].expr)->IsLit == false);
                               (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].expr));
                               (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].expr)); ;}
    break;

  case 29:
#line 215 "parser.y"
    { assert((yyvsp[(1) - (1)].expr)->IsLit == false);
                   (yyval.expr) = new Node("EXPR", "DECL_ARG");
                   (yyval.expr)->Children.push_back((yyvsp[(1) - (1)].expr)); ;}
    break;

  case 30:
#line 220 "parser.y"
    { (yyval.expr) = new Node("EXPR", "ASSIGN");
                            (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].expr));
                            (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].expr));
                            assert((yyvsp[(1) - (3)].expr)->IsLit == false);
                          ;}
    break;

  case 31:
#line 225 "parser.y"
    { (yyval.expr) = new Node("EXPR", "ASSIGN", "ADD");
                            (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].expr));
                            (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].expr));
                            assert((yyvsp[(1) - (3)].expr)->IsLit == false);
                          ;}
    break;

  case 32:
#line 230 "parser.y"
    { (yyval.expr) = new Node("EXPR", "ASSIGN", "MIN");
                            (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].expr));
                            (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].expr));
                            assert((yyvsp[(1) - (3)].expr)->IsLit == false);
                          ;}
    break;

  case 33:
#line 235 "parser.y"
    { (yyval.expr) = new Node("EXPR", "ASSIGN", "MUL");
                            (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].expr));
                            (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].expr));
                            assert((yyvsp[(1) - (3)].expr)->IsLit == false);
                          ;}
    break;

  case 34:
#line 240 "parser.y"
    { (yyval.expr) = new Node("EXPR", "ASSIGN", "DIV");
                            (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].expr));
                            (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].expr));
                            assert((yyvsp[(1) - (3)].expr)->IsLit == false);
                          ;}
    break;

  case 35:
#line 245 "parser.y"
    { (yyval.expr) = new Node("EXPR", "ASSIGN", "MOD");
                            (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].expr));
                            (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].expr));
                            assert((yyvsp[(1) - (3)].expr)->IsLit == false);
                          ;}
    break;

  case 36:
#line 250 "parser.y"
    { (yyval.expr) = new Node("EXPR", "ASSIGN", "BAND");
                             (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].expr));
                             (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].expr));
                             assert((yyvsp[(1) - (3)].expr)->IsLit == false);
                           ;}
    break;

  case 37:
#line 255 "parser.y"
    { (yyval.expr) = new Node("EXPR", "ASSIGN", "BXOR");
                             (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].expr));
                             (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].expr));
                             assert((yyvsp[(1) - (3)].expr)->IsLit == false);
                           ;}
    break;

  case 38:
#line 260 "parser.y"
    { (yyval.expr) = new Node("EXPR", "ASSIGN", "BOR");
                             (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].expr));
                             (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].expr));
                             assert((yyvsp[(1) - (3)].expr)->IsLit == false);
                           ;}
    break;

  case 39:
#line 265 "parser.y"
    { (yyval.expr) = new Node("EXPR", "ASSIGN", "BLEFT");
                             (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].expr));
                             (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].expr));
                             assert((yyvsp[(1) - (3)].expr)->IsLit == false);
                           ;}
    break;

  case 40:
#line 270 "parser.y"
    { (yyval.expr) = new Node("EXPR", "ASSIGN", "BRIGHT");
                             (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].expr));
                             (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].expr));
                             assert((yyvsp[(1) - (3)].expr)->IsLit == false);
                           ;}
    break;

  case 41:
#line 275 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 42:
#line 278 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 43:
#line 279 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 44:
#line 280 "parser.y"
    { (yyval.expr) = new Node("OPTIONAL_EXPR", "EMPTY"); ;}
    break;

  case 45:
#line 283 "parser.y"
    { (yyval.expr) = new Node("EXPR", "OR");
                             assert((yyvsp[(1) - (3)].expr)->type == "int_char" || (yyvsp[(1) - (3)].expr)->type == "double_float");
                             assert((yyvsp[(3) - (3)].expr)->type == "int_char" || (yyvsp[(3) - (3)].expr)->type == "double_float");
                             (yyval.expr)->type = "int_char";
                             if ((yyvsp[(1) - (3)].expr)->IsLit && (yyvsp[(3) - (3)].expr)->IsLit) {
                               (yyval.expr)->IsLit = true;
                               if (std::stod((yyvsp[(1) - (3)].expr)->NodeValue) != 0.0 || std::stod((yyvsp[(3) - (3)].expr)->NodeValue) != 0.0) {
                                 (yyval.expr)->NodeValue = "1";
                               }
                               else {
                                 (yyval.expr)->NodeValue = "0";
                               }
                             } else {
                               (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].factor));
                               (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].term));
                             }
                           ;}
    break;

  case 46:
#line 300 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 47:
#line 303 "parser.y"
    { (yyval.expr) = new Node("EXPR", "AND");
                             assert((yyvsp[(1) - (3)].expr)->type == "int_char" || (yyvsp[(1) - (3)].expr)->type == "double_float");
                             assert((yyvsp[(3) - (3)].expr)->type == "int_char" || (yyvsp[(3) - (3)].expr)->type == "double_float");
                             (yyval.expr)->type = "int_char";
                             if ((yyvsp[(1) - (3)].expr)->IsLit && (yyvsp[(3) - (3)].expr)->IsLit) {
                               (yyval.expr)->IsLit = true;
                               if (std::stod((yyvsp[(1) - (3)].expr)->NodeValue) != 0.0 && std::stod((yyvsp[(3) - (3)].expr)->NodeValue) != 0.0) {
                                 (yyval.expr)->NodeValue = "1";
                               }
                               else {
                                 (yyval.expr)->NodeValue = "0";
                               }
                             } else {
                               (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].factor));
                               (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].term));
                             }
                           ;}
    break;

  case 48:
#line 320 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 49:
#line 323 "parser.y"
    { (yyval.expr) = new Node("EXPR", "BOR");
                             assert((yyvsp[(1) - (3)].expr)->type == "int_char");
                             assert((yyvsp[(3) - (3)].expr)->type == "int_char");
                             (yyval.expr)->type = "int_char";
                             if ((yyvsp[(1) - (3)].expr)->IsLit && (yyvsp[(3) - (3)].expr)->IsLit) {
                               (yyval.expr)->IsLit = true;
                               (yyval.expr)->NodeValue = std::to_string(std::stoi((yyvsp[(1) - (3)].expr)->NodeValue) | std::stoi((yyvsp[(3) - (3)].expr)->NodeValue));
                             } else {
                               (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].factor));
                               (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].term));
                             }
                           ;}
    break;

  case 50:
#line 335 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 51:
#line 338 "parser.y"
    { (yyval.expr) = new Node("EXPR", "BXOR");
                            assert((yyvsp[(1) - (3)].expr)->type == "int_char");
                            assert((yyvsp[(3) - (3)].expr)->type == "int_char");
                            (yyval.expr)->type = "int_char";
                            if ((yyvsp[(1) - (3)].expr)->IsLit && (yyvsp[(3) - (3)].expr)->IsLit) {
                              (yyval.expr)->IsLit = true;
                              (yyval.expr)->NodeValue = std::to_string(std::stoi((yyvsp[(1) - (3)].expr)->NodeValue) ^ std::stoi((yyvsp[(3) - (3)].expr)->NodeValue));
                            } else {
                              (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].factor));
                              (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].term));
                            }
                          ;}
    break;

  case 52:
#line 350 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 53:
#line 353 "parser.y"
    { (yyval.expr) = new Node("EXPR", "TBAND");
                            assert((yyvsp[(1) - (3)].expr)->type == "int_char");
                            assert((yyvsp[(3) - (3)].expr)->type == "int_char");
                            (yyval.expr)->type = "int_char";
                            if ((yyvsp[(1) - (3)].expr)->IsLit && (yyvsp[(3) - (3)].expr)->IsLit) {
                              (yyval.expr)->IsLit = true;
                              (yyval.expr)->NodeValue = std::to_string(std::stoi((yyvsp[(1) - (3)].expr)->NodeValue) & std::stoi((yyvsp[(3) - (3)].expr)->NodeValue));
                            } else {
                              (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].factor));
                              (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].term));
                            }
                          ;}
    break;

  case 54:
#line 365 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 55:
#line 368 "parser.y"
    { (yyval.expr) = new Node("EXPR", "COMP_EQL");
                           assert((yyvsp[(1) - (3)].expr)->type == "int_char" || (yyvsp[(1) - (3)].expr)->type == "double_float");
                           assert((yyvsp[(3) - (3)].expr)->type == "int_char" || (yyvsp[(3) - (3)].expr)->type == "double_float");
                           (yyval.expr)->type = "int_char";
                           if ((yyvsp[(1) - (3)].expr)->IsLit && (yyvsp[(3) - (3)].expr)->IsLit) {
                             (yyval.expr)->IsLit = true;
                             if (std::stod((yyvsp[(1) - (3)].expr)->NodeValue) == std::stod((yyvsp[(3) - (3)].expr)->NodeValue))
                               (yyval.expr)->NodeValue = "1";
                             else
                               (yyval.expr)->NodeValue = "0";
                           } else {
                             (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].factor));
                             (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].term));
                           }
                         ;}
    break;

  case 56:
#line 383 "parser.y"
    { (yyval.expr) = new Node("EXPR", "COMP_NE");
                            assert((yyvsp[(1) - (3)].expr)->type == "int_char" || (yyvsp[(1) - (3)].expr)->type == "double_float");
                            assert((yyvsp[(3) - (3)].expr)->type == "int_char" || (yyvsp[(3) - (3)].expr)->type == "double_float");
                            (yyval.expr)->type = "int_char";
                            if ((yyvsp[(1) - (3)].expr)->IsLit && (yyvsp[(3) - (3)].expr)->IsLit) {
                              (yyval.expr)->IsLit = true;
                              if (std::stod((yyvsp[(1) - (3)].expr)->NodeValue) != std::stod((yyvsp[(3) - (3)].expr)->NodeValue))
                                (yyval.expr)->NodeValue = "1";
                              else
                                (yyval.expr)->NodeValue = "0";
                            } else {
                              (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].factor));
                              (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].term));
                            }
                          ;}
    break;

  case 57:
#line 398 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 58:
#line 401 "parser.y"
    { (yyval.expr) = new Node("EXPR", "COMP_LT");
                           assert((yyvsp[(1) - (3)].expr)->type == "int_char" || (yyvsp[(1) - (3)].expr)->type == "double_float");
                           assert((yyvsp[(3) - (3)].expr)->type == "int_char" || (yyvsp[(3) - (3)].expr)->type == "double_float");
                           (yyval.expr)->type = "int_char";
                           if ((yyvsp[(1) - (3)].expr)->IsLit && (yyvsp[(3) - (3)].expr)->IsLit) {
                             (yyval.expr)->IsLit = true;
                             if (std::stod((yyvsp[(1) - (3)].expr)->NodeValue) < std::stod((yyvsp[(3) - (3)].expr)->NodeValue))
                               (yyval.expr)->NodeValue = "1";
                             else
                               (yyval.expr)->NodeValue = "0";
                           } else {
                             (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].factor));
                             (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].term));
                           }
                         ;}
    break;

  case 59:
#line 416 "parser.y"
    { (yyval.expr) = new Node("EXPR", "COMP_GT");
                            assert((yyvsp[(1) - (3)].expr)->type == "int_char" || (yyvsp[(1) - (3)].expr)->type == "double_float");
                            assert((yyvsp[(3) - (3)].expr)->type == "int_char" || (yyvsp[(3) - (3)].expr)->type == "double_float");
                            (yyval.expr)->type = "int_char";
                            if ((yyvsp[(1) - (3)].expr)->IsLit && (yyvsp[(3) - (3)].expr)->IsLit) {
                              (yyval.expr)->IsLit = true;
                              if (std::stod((yyvsp[(1) - (3)].expr)->NodeValue) > std::stod((yyvsp[(3) - (3)].expr)->NodeValue))
                                (yyval.expr)->NodeValue = "1";
                              else
                                (yyval.expr)->NodeValue = "0";
                            } else {
                              (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].factor));
                              (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].term));
                            }
                          ;}
    break;

  case 60:
#line 431 "parser.y"
    { (yyval.expr) = new Node("EXPR", "COMP_LE");
                            assert((yyvsp[(1) - (3)].expr)->type == "int_char" || (yyvsp[(1) - (3)].expr)->type == "double_float");
                            assert((yyvsp[(3) - (3)].expr)->type == "int_char" || (yyvsp[(3) - (3)].expr)->type == "double_float");
                            (yyval.expr)->type = "int_char";
                            if ((yyvsp[(1) - (3)].expr)->IsLit && (yyvsp[(3) - (3)].expr)->IsLit) {
                              (yyval.expr)->IsLit = true;
                              if (std::stod((yyvsp[(1) - (3)].expr)->NodeValue) <= std::stod((yyvsp[(3) - (3)].expr)->NodeValue))
                                (yyval.expr)->NodeValue = "1";
                              else
                                (yyval.expr)->NodeValue = "0";
                            } else {
                              (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].factor));
                              (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].term));
                            }
                          ;}
    break;

  case 61:
#line 446 "parser.y"
    { (yyval.expr) = new Node("EXPR", "COMP_GE");
                            assert((yyvsp[(1) - (3)].expr)->type == "int_char" || (yyvsp[(1) - (3)].expr)->type == "double_float");
                            assert((yyvsp[(3) - (3)].expr)->type == "int_char" || (yyvsp[(3) - (3)].expr)->type == "double_float");
                            (yyval.expr)->type = "int_char";
                            if ((yyvsp[(1) - (3)].expr)->IsLit && (yyvsp[(3) - (3)].expr)->IsLit) {
                              (yyval.expr)->IsLit = true;
                              if (std::stod((yyvsp[(1) - (3)].expr)->NodeValue) >= std::stod((yyvsp[(3) - (3)].expr)->NodeValue))
                                (yyval.expr)->NodeValue = "1";
                              else
                                (yyval.expr)->NodeValue = "0";
                            } else {
                              (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].factor));
                              (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].term));
                            }
                          ;}
    break;

  case 62:
#line 461 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 63:
#line 464 "parser.y"
    { (yyval.expr) = new Node("EXPR", "BLEFT");
                             assert((yyvsp[(1) - (3)].expr)->type == "int_char");
                             assert((yyvsp[(3) - (3)].expr)->type == "int_char");
                             (yyval.expr)->type = "int_char";
                             if ((yyvsp[(1) - (3)].expr)->IsLit && (yyvsp[(3) - (3)].expr)->IsLit) {
                               (yyval.expr)->IsLit = true;
                               (yyval.expr)->NodeValue = std::to_string(std::stoi((yyvsp[(1) - (3)].expr)->NodeValue) << std::stoi((yyvsp[(3) - (3)].expr)->NodeValue));
                             } else {
                               (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].factor));
                               (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].term));
                             }
                           ;}
    break;

  case 64:
#line 476 "parser.y"
    { (yyval.expr) = new Node("EXPR", "BRIGHT");
                              assert((yyvsp[(1) - (3)].expr)->type == "int_char");
                              assert((yyvsp[(3) - (3)].expr)->type == "int_char");
                              (yyval.expr)->type = "int_char";
                              if ((yyvsp[(1) - (3)].expr)->IsLit && (yyvsp[(3) - (3)].expr)->IsLit) {
                                (yyval.expr)->IsLit = true;
                                (yyval.expr)->NodeValue = std::to_string(std::stoi((yyvsp[(1) - (3)].expr)->NodeValue) >> std::stoi((yyvsp[(3) - (3)].expr)->NodeValue));
                              } else {
                                (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].factor));
                                (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].term));
                              }
                            ;}
    break;

  case 65:
#line 488 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 66:
#line 491 "parser.y"
    { (yyval.expr) = new Node("EXPR", "ADD");
                            assert((yyvsp[(1) - (3)].expr)->type == "int_char" || (yyvsp[(1) - (3)].expr)->type == "double_float");
                            assert((yyvsp[(3) - (3)].expr)->type == "int_char" || (yyvsp[(3) - (3)].expr)->type == "double_float");
                            (yyval.expr)->type = MoreAccurate((yyvsp[(1) - (3)].expr)->type, (yyvsp[(3) - (3)].expr)->type);
                            if ((yyvsp[(1) - (3)].expr)->IsLit && (yyvsp[(3) - (3)].expr)->IsLit) {
                              (yyval.expr)->IsLit = true;
                              if ((yyval.expr)->type == "int_char")
                                (yyval.expr)->NodeValue = std::to_string(std::stoi((yyvsp[(1) - (3)].expr)->NodeValue) + std::stoi((yyvsp[(3) - (3)].expr)->NodeValue));
                              else
                                (yyval.expr)->NodeValue = std::to_string(std::stod((yyvsp[(1) - (3)].expr)->NodeValue) + std::stod((yyvsp[(3) - (3)].expr)->NodeValue));
                            } else {
                              (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].factor));
                              (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].term));
                            }
                          ;}
    break;

  case 67:
#line 506 "parser.y"
    { (yyval.expr) = new Node("EXPR", "MINUS");
                             assert((yyvsp[(1) - (3)].expr)->type == "int_char" || (yyvsp[(1) - (3)].expr)->type == "double_float");
                             assert((yyvsp[(3) - (3)].expr)->type == "int_char" || (yyvsp[(3) - (3)].expr)->type == "double_float");
                             (yyval.expr)->type = MoreAccurate((yyvsp[(1) - (3)].expr)->type, (yyvsp[(3) - (3)].expr)->type);
                             if ((yyvsp[(1) - (3)].expr)->IsLit && (yyvsp[(3) - (3)].expr)->IsLit) {
                               (yyval.expr)->IsLit = true;
                               if ((yyval.expr)->type == "int_char")
                                 (yyval.expr)->NodeValue = std::to_string(std::stoi((yyvsp[(1) - (3)].expr)->NodeValue) - std::stoi((yyvsp[(3) - (3)].expr)->NodeValue));
                               else
                                 (yyval.expr)->NodeValue = std::to_string(std::stod((yyvsp[(1) - (3)].expr)->NodeValue) - std::stod((yyvsp[(3) - (3)].expr)->NodeValue));
                             } else {
                               (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].factor));
                               (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].term));
                             }
                           ;}
    break;

  case 68:
#line 521 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 69:
#line 524 "parser.y"
    { (yyval.expr) = new Node("EXPR", "MUL");
                          assert((yyvsp[(1) - (3)].expr)->type == "int_char" || (yyvsp[(1) - (3)].expr)->type == "double_float");
                          assert((yyvsp[(3) - (3)].expr)->type == "int_char" || (yyvsp[(3) - (3)].expr)->type == "double_float");
                          (yyval.expr)->type = MoreAccurate((yyvsp[(1) - (3)].expr)->type, (yyvsp[(3) - (3)].expr)->type);
                          if ((yyvsp[(1) - (3)].expr)->IsLit && (yyvsp[(3) - (3)].expr)->IsLit) {
                            (yyval.expr)->IsLit = true;
                            if ((yyval.expr)->type == "int_char")
                              (yyval.expr)->NodeValue = std::to_string(std::stoi((yyvsp[(1) - (3)].expr)->NodeValue) * std::stoi((yyvsp[(3) - (3)].expr)->NodeValue));
                            else
                              (yyval.expr)->NodeValue = std::to_string(std::stod((yyvsp[(1) - (3)].expr)->NodeValue) * std::stod((yyvsp[(3) - (3)].expr)->NodeValue));
                          } else {
                            (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].factor));
                            (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].term));
                          }
                        ;}
    break;

  case 70:
#line 539 "parser.y"
    { (yyval.expr) = new Node("EXPR", "DIV");
                          assert((yyvsp[(1) - (3)].expr)->type == "int_char" || (yyvsp[(1) - (3)].expr)->type == "double_float");
                          assert((yyvsp[(3) - (3)].expr)->type == "int_char" || (yyvsp[(3) - (3)].expr)->type == "double_float");
                          (yyval.expr)->type = MoreAccurate((yyvsp[(1) - (3)].expr)->type, (yyvsp[(3) - (3)].expr)->type);
                          if ((yyvsp[(1) - (3)].expr)->IsLit && (yyvsp[(3) - (3)].expr)->IsLit) {
                            (yyval.expr)->IsLit = true;
                            if ((yyval.expr)->type == "int_char")
                              (yyval.expr)->NodeValue = std::to_string(std::stoi((yyvsp[(1) - (3)].expr)->NodeValue) / std::stoi((yyvsp[(3) - (3)].expr)->NodeValue));
                            else
                              (yyval.expr)->NodeValue = std::to_string(std::stod((yyvsp[(1) - (3)].expr)->NodeValue) / std::stod((yyvsp[(3) - (3)].expr)->NodeValue));
                          } else {
                            (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].factor));
                            (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].term));
                          }
                        ;}
    break;

  case 71:
#line 554 "parser.y"
    { (yyval.expr) = new Node("EXPR", "MOD");
                          assert((yyvsp[(1) - (3)].expr)->type == "int_char");
                          assert((yyvsp[(3) - (3)].expr)->type == "int_char");
                          (yyval.expr)->type = "int_char";
                          if ((yyvsp[(1) - (3)].expr)->IsLit && (yyvsp[(3) - (3)].expr)->IsLit) {
                            (yyval.expr)->IsLit = true;
                            (yyval.expr)->NodeValue = std::to_string(std::stoi((yyvsp[(1) - (3)].expr)->NodeValue) % std::stoi((yyvsp[(3) - (3)].expr)->NodeValue));
                          } else {
                            (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].factor));
                            (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].term));
                          }
                        ;}
    break;

  case 72:
#line 566 "parser.y"
    { (yyval.term) = (yyvsp[(1) - (1)].term); ;}
    break;

  case 73:
#line 569 "parser.y"
    { (yyval.factor) = new Node("VAL", (yyvsp[(2) - (2)].str), "NEG", "int_char");
                          (yyval.expr)->IsLit = true; ;}
    break;

  case 74:
#line 571 "parser.y"
    { (yyval.factor) = new Node("VAL", (yyvsp[(2) - (2)].str), "", "int_char");
                         (yyval.expr)->IsLit = true; ;}
    break;

  case 75:
#line 573 "parser.y"
    { (yyval.expr) = new Node("EXPR", "PRSADD");
                           assert((yyvsp[(2) - (2)].expr)->type == "int_char");
                           (yyval.expr)->type = "int_char";
                           (yyval.expr)->Children.push_back((yyvsp[(2) - (2)].expr)); ;}
    break;

  case 76:
#line 577 "parser.y"
    { (yyval.expr) = new Node("EXPR", "PRSMINUS");
                             assert((yyvsp[(2) - (2)].expr)->type == "int_char");
                             (yyval.expr)->type = "int_char";
                             (yyval.expr)->Children.push_back((yyvsp[(2) - (2)].expr)); ;}
    break;

  case 77:
#line 581 "parser.y"
    { (yyval.expr) = new Node("EXPR", "SUSADD");
                           assert((yyvsp[(1) - (2)].expr)->type == "int_char");
                           (yyval.expr)->type = "int_char";
                           (yyval.expr)->Children.push_back((yyvsp[(1) - (2)].expr)); ;}
    break;

  case 78:
#line 585 "parser.y"
    { (yyval.expr) = new Node("EXPR", "SUSMINUS");
                             assert((yyvsp[(1) - (2)].expr)->type == "int_char");
                             (yyval.expr)->type = "int_char";
                             (yyval.expr)->Children.push_back((yyvsp[(1) - (2)].expr)); ;}
    break;

  case 79:
#line 589 "parser.y"
    { (yyval.expr) = new Node("EXPR", "NOT");
                     assert((yyvsp[(2) - (2)].expr)->type == "int_char" || (yyvsp[(2) - (2)].expr)->type == "double_float");
                     (yyval.expr)->type = "int_char";
                     if ((yyvsp[(2) - (2)].expr)->IsLit) {
                        (yyval.expr)->IsLit = true;
                        if (std::stod((yyvsp[(2) - (2)].expr)->NodeValue) != 0.0) {
                          (yyval.expr)->NodeValue = "0";
                        } else {
                          (yyval.expr)->NodeValue = "1";
                        }
                     } else {
                        (yyval.expr)->Children.push_back((yyvsp[(2) - (2)].expr));
                     } ;}
    break;

  case 80:
#line 602 "parser.y"
    { (yyval.expr) = new Node("EXPR", "BNOT");
                      assert((yyvsp[(2) - (2)].expr)->type == "int_char");
                      (yyval.expr)->type = "int_char";
                      if ((yyvsp[(2) - (2)].expr)->IsLit) {
                        (yyval.expr)->IsLit = true;
                        (yyval.expr)->NodeValue = std::to_string(~std::stoi((yyvsp[(2) - (2)].expr)->NodeValue));
                      } else {
                        (yyval.expr)->Children.push_back((yyvsp[(2) - (2)].expr));
                      } ;}
    break;

  case 81:
#line 611 "parser.y"
    { (yyval.term) = (yyvsp[(1) - (1)].term); ;}
    break;

  case 82:
#line 614 "parser.y"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); ;}
    break;

  case 83:
#line 615 "parser.y"
    { (yyval.factor) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 84:
#line 618 "parser.y"
    { (yyval.factor) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 85:
#line 619 "parser.y"
    { (yyval.factor) = new Node("VAL", (yyvsp[(1) - (1)].str), "", "int_char");
                   (yyval.expr)->IsLit = true; ;}
    break;

  case 86:
#line 621 "parser.y"
    { (yyval.factor) = new Node("VAL", (yyvsp[(1) - (1)].str), "", "double_float");
                  (yyval.expr)->IsLit = true; ;}
    break;

  case 87:
#line 623 "parser.y"
    { (yyval.factor) = new Node("VAL", (yyvsp[(1) - (1)].str), "", "int_char");
                (yyval.expr)->IsLit = true; ;}
    break;

  case 88:
#line 627 "parser.y"
    { (yyval.identifier) = new Node("VAR", (yyvsp[(1) - (1)].str));
                           std::string var = (yyvsp[(1) - (1)].str);
                           if (IdTable.find(var) != IdTable.end()) {
                             (yyval.identifier)->type = GetType(IdTable.find(var)->second);
                             (yyval.identifier)->NodeInfo = IdTable.find(var)->second;
                           }
                          ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2468 "parser.cpp"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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


#line 636 "parser.y"


