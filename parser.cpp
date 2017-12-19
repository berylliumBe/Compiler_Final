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
     TREAD = 289,
     TWRITE = 290,
     TNOT = 291,
     TAND = 292,
     TOR = 293,
     TBNOT = 294,
     TBAND = 295,
     TBOR = 296,
     TBXOR = 297,
     TBLEFT = 298,
     TBRIGHT = 299
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
#define TREAD 289
#define TWRITE 290
#define TNOT 291
#define TAND 292
#define TOR 293
#define TBNOT 294
#define TBAND 295
#define TBOR 296
#define TBXOR 297
#define TBLEFT 298
#define TBRIGHT 299




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

    std::map<std::string, std::string> IdTable;

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
    char *str;
}
/* Line 193 of yacc.c.  */
#line 239 "parser.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 252 "parser.cpp"

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
#define YYLAST   167

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNRULES -- Number of states.  */
#define YYNSTATES  138

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     9,    13,    15,    18,    19,    21,    23,
      31,    34,    36,    42,    48,    54,    64,    70,    78,    80,
      83,    85,    87,    89,    91,    93,    97,   101,   103,   107,
     109,   111,   112,   116,   118,   122,   124,   128,   130,   134,
     136,   140,   142,   146,   150,   152,   156,   160,   164,   168,
     170,   174,   178,   180,   184,   188,   190,   194,   198,   202,
     204,   207,   210,   212,   216,   218,   220,   222,   224,   227,
     230
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,     3,    11,    22,    23,    47,    -1,    24,
      48,    25,    -1,    28,    -1,    49,    48,    -1,    -1,    50,
      -1,    51,    -1,     7,    22,    56,    23,    50,     8,    50,
      -1,    52,    28,    -1,    47,    -1,    34,    22,    70,    23,
      28,    -1,    35,    22,    56,    23,    28,    -1,     9,    22,
      52,    23,    50,    -1,    10,    22,    57,    28,    57,    28,
      57,    23,    50,    -1,     7,    22,    56,    23,    49,    -1,
       7,    22,    56,    23,    50,     8,    51,    -1,    56,    -1,
      53,    54,    -1,     3,    -1,     4,    -1,     5,    -1,     6,
      -1,    55,    -1,    55,    26,    54,    -1,    69,    21,    58,
      -1,    69,    -1,    58,    21,    56,    -1,    58,    -1,    52,
      -1,    -1,    59,    38,    58,    -1,    59,    -1,    60,    37,
      59,    -1,    60,    -1,    61,    41,    60,    -1,    61,    -1,
      62,    42,    61,    -1,    62,    -1,    63,    40,    62,    -1,
      63,    -1,    64,    15,    63,    -1,    64,    16,    63,    -1,
      64,    -1,    65,    17,    64,    -1,    65,    19,    64,    -1,
      65,    18,    64,    -1,    65,    20,    64,    -1,    65,    -1,
      66,    43,    65,    -1,    66,    44,    65,    -1,    66,    -1,
      66,    29,    67,    -1,    66,    30,    67,    -1,    67,    -1,
      68,    31,    67,    -1,    68,    32,    67,    -1,    68,    33,
      67,    -1,    68,    -1,    36,    69,    -1,    39,    69,    -1,
      69,    -1,    22,    56,    23,    -1,    70,    -1,    12,    -1,
      13,    -1,    14,    -1,    30,    12,    -1,    29,    12,    -1,
      11,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    97,    97,   100,   101,   104,   108,   111,   112,   115,
     123,   125,   126,   129,   132,   137,   148,   154,   164,   165,
     181,   182,   183,   184,   187,   189,   196,   200,   205,   210,
     213,   214,   217,   234,   237,   254,   257,   269,   272,   284,
     287,   299,   302,   317,   332,   335,   350,   365,   380,   395,
     398,   410,   422,   425,   440,   455,   458,   473,   488,   500,
     503,   516,   525,   528,   529,   530,   532,   534,   536,   538,
     542
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
  "TMINUS", "TMUL", "TDIV", "TMOD", "TREAD", "TWRITE", "TNOT", "TAND",
  "TOR", "TBNOT", "TBAND", "TBOR", "TBXOR", "TBLEFT", "TBRIGHT", "$accept",
  "start", "comp_stmt", "stmts", "stmt", "matched_stmt", "open_stmt",
  "expr_and_decl", "type", "args_list", "arg", "expr", "optional_expr",
  "expr1", "expr2", "expr3", "expr4", "expr5", "expr6", "expr7", "expr8",
  "expr_alg", "term", "factor", "factor0", "identifier", 0
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
     295,   296,   297,   298,   299
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    49,    49,    50,
      50,    50,    50,    50,    50,    50,    51,    51,    52,    52,
      53,    53,    53,    53,    54,    54,    55,    55,    56,    56,
      57,    57,    58,    58,    59,    59,    60,    60,    61,    61,
      62,    62,    63,    63,    63,    64,    64,    64,    64,    64,
      65,    65,    65,    66,    66,    66,    67,    67,    67,    67,
      68,    68,    68,    69,    69,    69,    69,    69,    69,    69,
      70
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     1,     2,     0,     1,     1,     7,
       2,     1,     5,     5,     5,     9,     5,     7,     1,     2,
       1,     1,     1,     1,     1,     3,     3,     1,     3,     1,
       1,     0,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       2,     2,     1,     3,     1,     1,     1,     1,     2,     2,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     6,     4,     2,
      20,    21,    22,    23,     0,     0,     0,    70,    65,    66,
      67,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       6,     7,     8,     0,     0,    18,    29,    33,    35,    37,
      39,    41,    44,    49,    52,    55,    59,    62,    64,     0,
       0,    31,     0,    69,    68,     0,     0,    60,    61,     3,
       5,    10,    19,    24,    27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    30,     0,    63,     0,
       0,     0,     0,    28,    32,    34,    36,    38,    40,    42,
      43,    45,    47,    46,    48,    53,    54,    50,    51,    56,
      57,    58,     0,     0,    31,     0,     0,    25,    26,    16,
       7,     0,    14,     0,    12,    13,     0,     0,    31,     9,
      17,     0,     0,     0,     0,     0,    15,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    28,    29,    30,    31,    32,    33,    34,    62,
      63,    35,    87,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -110
static const yytype_int16 yypact[] =
{
      20,    15,    34,    14,  -110,    44,    -6,     3,  -110,  -110,
    -110,  -110,  -110,  -110,    21,    47,    53,  -110,  -110,  -110,
    -110,    75,    68,    82,    73,    74,   113,   113,  -110,    77,
       3,  -110,  -110,    72,   113,  -110,    86,    65,    76,    69,
      80,    81,     5,   111,    30,  -110,   101,  -110,  -110,    75,
      79,    79,    93,  -110,  -110,   106,    75,  -110,  -110,  -110,
    -110,  -110,  -110,   114,   120,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,   121,   122,  -110,   118,  -110,   124,
     125,   113,    75,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,     3,    42,    79,   123,   126,  -110,  -110,  -110,
     141,   128,  -110,   127,  -110,  -110,     3,    75,    79,  -110,
    -110,   129,   130,    42,    42,   148,  -110,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -110,  -110,   151,   131,    46,   -14,    33,   -49,  -110,    71,
    -110,   -21,  -109,   -42,    96,    92,    95,    97,   -31,    63,
     -50,  -110,   -20,  -110,   -23,   110
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      52,    85,    86,    57,    58,   123,    10,    11,    12,    13,
      14,    64,    15,    16,    17,    18,    19,    20,     7,   132,
      71,    72,     8,     1,    94,    21,     3,     7,    84,   107,
     108,     8,    22,    23,     4,    90,     5,    24,    25,    26,
      99,   100,    27,    49,    93,    10,    11,    12,    13,   121,
     118,    15,    16,    17,    18,    19,    20,   105,   106,    77,
      78,   109,   110,   111,    21,    86,     7,     6,    64,    50,
       8,    22,    23,    79,    80,    51,    24,    25,    26,    86,
      53,    27,    10,    11,    12,    13,    17,    18,    19,    20,
      17,    18,    19,    20,    54,    55,    56,    21,   120,   122,
      61,    21,    59,    66,    22,    23,   131,    65,    22,    23,
      68,    26,   129,    67,    27,    26,    88,    17,    27,   135,
     136,    70,    69,   129,    17,    18,    19,    20,    73,    74,
      75,    76,    81,    82,    83,    21,   101,   102,   103,   104,
      91,    92,    22,    23,   112,   113,   114,   115,   116,   126,
     127,   124,   133,   134,   125,   128,   137,     9,   119,   130,
      96,    60,   117,    95,    97,    89,     0,    98
};

static const yytype_int16 yycheck[] =
{
      21,    50,    51,    26,    27,   114,     3,     4,     5,     6,
       7,    34,     9,    10,    11,    12,    13,    14,    24,   128,
      15,    16,    28,     3,    66,    22,    11,    24,    49,    79,
      80,    28,    29,    30,     0,    56,    22,    34,    35,    36,
      71,    72,    39,    22,    65,     3,     4,     5,     6,     7,
      92,     9,    10,    11,    12,    13,    14,    77,    78,    29,
      30,    81,    82,    83,    22,   114,    24,    23,    91,    22,
      28,    29,    30,    43,    44,    22,    34,    35,    36,   128,
      12,    39,     3,     4,     5,     6,    11,    12,    13,    14,
      11,    12,    13,    14,    12,    22,    22,    22,   112,   113,
      28,    22,    25,    38,    29,    30,   127,    21,    29,    30,
      41,    36,   126,    37,    39,    36,    23,    11,    39,   133,
     134,    40,    42,   137,    11,    12,    13,    14,    17,    18,
      19,    20,    31,    32,    33,    22,    73,    74,    75,    76,
      26,    21,    29,    30,    23,    23,    28,    23,    23,     8,
      22,    28,    23,    23,    28,    28,     8,     6,   112,   126,
      68,    30,    91,    67,    69,    55,    -1,    70
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    46,    11,     0,    22,    23,    24,    28,    47,
       3,     4,     5,     6,     7,     9,    10,    11,    12,    13,
      14,    22,    29,    30,    34,    35,    36,    39,    47,    48,
      49,    50,    51,    52,    53,    56,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    22,
      22,    22,    56,    12,    12,    22,    22,    69,    69,    25,
      48,    28,    54,    55,    69,    21,    38,    37,    41,    42,
      40,    15,    16,    17,    18,    19,    20,    29,    30,    43,
      44,    31,    32,    33,    56,    52,    52,    57,    23,    70,
      56,    26,    21,    56,    58,    59,    60,    61,    62,    63,
      63,    64,    64,    64,    64,    67,    67,    65,    65,    67,
      67,    67,    23,    23,    28,    23,    23,    54,    58,    49,
      50,     7,    50,    57,    28,    28,     8,    22,    28,    50,
      51,    56,    57,    23,    23,    50,    50,     8
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
#line 97 "parser.y"
    { RootNode = (yyvsp[(5) - (5)].stmt); ;}
    break;

  case 3:
#line 100 "parser.y"
    { (yyval.stmt) = (yyvsp[(2) - (3)].stmt); ;}
    break;

  case 4:
#line 101 "parser.y"
    { (yyval.stmt) = new Node("SEMICOLON"); ;}
    break;

  case 5:
#line 104 "parser.y"
    { (yyval.stmt) = (yyvsp[(2) - (2)].stmt);
                     std::vector<Node*>::iterator it;
                     it = (yyval.stmt)->Children.begin();
                     (yyval.stmt)->Children.insert(it, (yyvsp[(1) - (2)].stmt)); ;}
    break;

  case 6:
#line 108 "parser.y"
    { (yyval.stmt) = new Node("COMP_STMT"); ;}
    break;

  case 7:
#line 111 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 8:
#line 112 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 9:
#line 115 "parser.y"
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
#line 123 "parser.y"
    { (yyval.stmt) = new Node("STMT", "EXPR");
                                          (yyval.stmt)->Children.push_back((yyvsp[(1) - (2)].expr)); ;}
    break;

  case 11:
#line 125 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 12:
#line 126 "parser.y"
    {
                                    (yyval.stmt) = new Node("STMT", "READ");
                                    (yyval.stmt)->Children.push_back((yyvsp[(3) - (5)].expr)); ;}
    break;

  case 13:
#line 129 "parser.y"
    {
                                    (yyval.stmt) = new Node("STMT", "WRITE");
                                    (yyval.stmt)->Children.push_back((yyvsp[(3) - (5)].expr)); ;}
    break;

  case 14:
#line 132 "parser.y"
    {
                                    (yyval.stmt) = new Node("STMT", "WHILE");
                                    (yyvsp[(3) - (5)].expr)->NodeInfo = "CONDITION";
                                    (yyval.stmt)->Children.push_back((yyvsp[(3) - (5)].expr));
                                    (yyval.stmt)->Children.push_back((yyvsp[(5) - (5)].stmt)); ;}
    break;

  case 15:
#line 137 "parser.y"
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

  case 16:
#line 148 "parser.y"
    {
                                    (yyval.stmt) = new Node("STMT", "IF");
                                    (yyvsp[(3) - (5)].stmt)->NodeInfo = "CONDITION";
                                    (yyvsp[(5) - (5)].stmt)->NodeInfo = "IF BRANCH";
                                    (yyval.stmt)->Children.push_back((yyvsp[(3) - (5)].stmt));
                                    (yyval.stmt)->Children.push_back((yyvsp[(5) - (5)].stmt)); ;}
    break;

  case 17:
#line 154 "parser.y"
    {
                                    (yyval.stmt) = new Node("STMT", "IF");
                                    (yyvsp[(3) - (7)].stmt)->NodeInfo = "CONDITION";
                                    (yyvsp[(5) - (7)].stmt)->NodeInfo = "IF BRANCH";
                                    (yyvsp[(7) - (7)].stmt)->NodeInfo = "ELSE BRANCH";
                                    (yyval.stmt)->Children.push_back((yyvsp[(3) - (7)].stmt));
                                    (yyval.stmt)->Children.push_back((yyvsp[(5) - (7)].stmt));
                                    (yyval.stmt)->Children.push_back((yyvsp[(7) - (7)].stmt)); ;}
    break;

  case 18:
#line 164 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 19:
#line 165 "parser.y"
    { (yyval.expr) = new Node("EXPR", "DECL");
                                 std::string t = GetType((yyvsp[(1) - (2)].type)->NodeValue);
                                 for (auto arg : (yyvsp[(2) - (2)].args_list)->Children) {
                                   std::string var = arg->Children[0]->NodeValue;
                                   if (IdTable.find(var) == IdTable.end()) {
                                     IdTable[var] = t;
                                     arg->Children[0]->type = t;
                                   }
                                   else {
                                     std::cout << "Error: Replicated Declaration: " << var << std::endl;
                                   }
                                 }
                                 (yyval.expr)->Children.push_back((yyvsp[(1) - (2)].type));
                                 (yyval.expr)->Children.push_back((yyvsp[(2) - (2)].expr)); ;}
    break;

  case 20:
#line 181 "parser.y"
    { (yyval.type) = new Node("TYPE", "int"); ;}
    break;

  case 21:
#line 182 "parser.y"
    { (yyval.type) = new Node("TYPE", "char"); ;}
    break;

  case 22:
#line 183 "parser.y"
    { (yyval.type) = new Node("TYPE", "float"); ;}
    break;

  case 23:
#line 184 "parser.y"
    { (yyval.type) = new Node("TYPE", "double"); ;}
    break;

  case 24:
#line 187 "parser.y"
    { (yyval.args_list) = new Node("ARGS_LIST");
                  (yyval.args_list)->Children.push_back((yyvsp[(1) - (1)].expr)); ;}
    break;

  case 25:
#line 189 "parser.y"
    {
                          (yyval.args_list) = (yyvsp[(3) - (3)].args_list);
                          std::vector<Node*>::iterator it;
                          it = (yyval.args_list)->Children.begin();
                          (yyval.args_list)->Children.insert(it, (yyvsp[(1) - (3)].expr)); ;}
    break;

  case 26:
#line 196 "parser.y"
    { (yyval.expr) = new Node("EXPR", "DECL_ASSIGN");
                             assert((yyvsp[(1) - (3)].expr)->IsLit == false);
                             (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].expr));
                             (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].expr)); ;}
    break;

  case 27:
#line 200 "parser.y"
    { assert((yyvsp[(1) - (1)].expr)->IsLit == false);
                (yyval.expr) = new Node("EXPR", "DECL_ARG");
                (yyval.expr)->Children.push_back((yyvsp[(1) - (1)].expr)); ;}
    break;

  case 28:
#line 205 "parser.y"
    { (yyval.expr) = new Node("EXPR", "ASSIGN");
                            (yyval.expr)->Children.push_back((yyvsp[(1) - (3)].expr));
                            (yyval.expr)->Children.push_back((yyvsp[(3) - (3)].expr));
                            assert((yyvsp[(1) - (3)].expr)->IsLit == false);
                          ;}
    break;

  case 29:
#line 210 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 30:
#line 213 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 31:
#line 214 "parser.y"
    { (yyval.expr) = new Node("OPTIONAL_EXPR", "EMPTY"); ;}
    break;

  case 32:
#line 217 "parser.y"
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

  case 33:
#line 234 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 34:
#line 237 "parser.y"
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

  case 35:
#line 254 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 36:
#line 257 "parser.y"
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

  case 37:
#line 269 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 38:
#line 272 "parser.y"
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

  case 39:
#line 284 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 40:
#line 287 "parser.y"
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

  case 41:
#line 299 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 42:
#line 302 "parser.y"
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

  case 43:
#line 317 "parser.y"
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

  case 44:
#line 332 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 45:
#line 335 "parser.y"
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

  case 46:
#line 350 "parser.y"
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

  case 47:
#line 365 "parser.y"
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

  case 48:
#line 380 "parser.y"
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

  case 49:
#line 395 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 50:
#line 398 "parser.y"
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

  case 51:
#line 410 "parser.y"
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

  case 52:
#line 422 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 53:
#line 425 "parser.y"
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

  case 54:
#line 440 "parser.y"
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

  case 55:
#line 455 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 56:
#line 458 "parser.y"
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

  case 57:
#line 473 "parser.y"
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

  case 58:
#line 488 "parser.y"
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

  case 59:
#line 500 "parser.y"
    { (yyval.term) = (yyvsp[(1) - (1)].term); ;}
    break;

  case 60:
#line 503 "parser.y"
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

  case 61:
#line 516 "parser.y"
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

  case 62:
#line 525 "parser.y"
    { (yyval.term) = (yyvsp[(1) - (1)].term); ;}
    break;

  case 63:
#line 528 "parser.y"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); ;}
    break;

  case 64:
#line 529 "parser.y"
    { (yyval.factor) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 65:
#line 530 "parser.y"
    { (yyval.factor) = new Node("VAL", (yyvsp[(1) - (1)].str), "", "int_char");
                    (yyval.expr)->IsLit = true; ;}
    break;

  case 66:
#line 532 "parser.y"
    { (yyval.factor) = new Node("VAL", (yyvsp[(1) - (1)].str), "", "double_float");
                   (yyval.expr)->IsLit = true; ;}
    break;

  case 67:
#line 534 "parser.y"
    { (yyval.factor) = new Node("VAL", (yyvsp[(1) - (1)].str), "", "int_char");
                 (yyval.expr)->IsLit = true; ;}
    break;

  case 68:
#line 536 "parser.y"
    { (yyval.factor) = new Node("VAL", (yyvsp[(2) - (2)].str), "NEG", "int_char");
                           (yyval.expr)->IsLit = true; ;}
    break;

  case 69:
#line 538 "parser.y"
    { (yyval.factor) = new Node("VAL", (yyvsp[(2) - (2)].str), "", "int_char");
                          (yyval.expr)->IsLit = true; ;}
    break;

  case 70:
#line 542 "parser.y"
    { (yyval.identifier) = new Node("VAR", (yyvsp[(1) - (1)].str));
                           std::string var = (yyvsp[(1) - (1)].str);
                           if (IdTable.find(var) != IdTable.end()) {
                             (yyval.identifier)->type = IdTable.find(var)->second;
                           }
                         ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2252 "parser.cpp"
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


#line 550 "parser.y"


