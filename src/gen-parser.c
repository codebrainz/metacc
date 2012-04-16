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
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 1

/* Substitute the variable and function names.  */
#define yyparse metac_parse
#define yylex   metac_lex
#define yyerror metac_error
#define yylval  metac_lval
#define yychar  metac_char
#define yydebug metac_debug
#define yynerrs metac_nerrs
#define yylloc metac_lloc

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     MCTOK_IDENTIFIER = 258,
     MCTOK_CONSTANT = 259,
     MCTOK_STRING_LITERAL = 260,
     MCTOK_SIZEOF = 261,
     MCTOK_TYPEOF = 262,
     MCTOK_PTR_OP = 263,
     MCTOK_INC_OP = 264,
     MCTOK_DEC_OP = 265,
     MCTOK_LEFT_OP = 266,
     MCTOK_RIGHT_OP = 267,
     MCTOK_LE_OP = 268,
     MCTOK_GE_OP = 269,
     MCTOK_EQ_OP = 270,
     MCTOK_NE_OP = 271,
     MCTOK_AND_OP = 272,
     MCTOK_OR_OP = 273,
     MCTOK_MUL_ASSIGN = 274,
     MCTOK_DIV_ASSIGN = 275,
     MCTOK_MOD_ASSIGN = 276,
     MCTOK_ADD_ASSIGN = 277,
     MCTOK_SUB_ASSIGN = 278,
     MCTOK_LEFT_ASSIGN = 279,
     MCTOK_RIGHT_ASSIGN = 280,
     MCTOK_AND_ASSIGN = 281,
     MCTOK_XOR_ASSIGN = 282,
     MCTOK_OR_ASSIGN = 283,
     MCTOK_TYPE_NAME = 284,
     MCTOK_TYPEDEF = 285,
     MCTOK_EXTERN = 286,
     MCTOK_STATIC = 287,
     MCTOK_INLINE = 288,
     MCTOK_LAMBDA = 289,
     MCTOK_PRIVATE = 290,
     MCTOK_PUBLIC = 291,
     MCTOK_VAR = 292,
     MCTOK_CHAR = 293,
     MCTOK_SHORT = 294,
     MCTOK_INT = 295,
     MCTOK_LONG = 296,
     MCTOK_UCHAR = 297,
     MCTOK_USHORT = 298,
     MCTOK_UINT = 299,
     MCTOK_ULONG = 300,
     MCTOK_BOOL = 301,
     MCTOK_FLOAT = 302,
     MCTOK_DOUBLE = 303,
     MCTOK_CONST = 304,
     MCTOK_VOID = 305,
     MCTOK_CATCH = 306,
     MCTOK_THROW = 307,
     MCTOK_TRY = 308,
     MCTOK_FINALLY = 309,
     MCTOK_CLASS = 310,
     MCTOK_STRUCT = 311,
     MCTOK_UNION = 312,
     MCTOK_ENUM = 313,
     MCTOK_ELLIPSIS = 314,
     MCTOK_NULL = 315,
     MCTOK_TRUE = 316,
     MCTOK_FALSE = 317,
     MCTOK_NEW = 318,
     MCTOK_DELETE = 319,
     MCTOK_CASE = 320,
     MCTOK_DEFAULT = 321,
     MCTOK_IF = 322,
     MCTOK_ELSE = 323,
     MCTOK_SWITCH = 324,
     MCTOK_WHILE = 325,
     MCTOK_DO = 326,
     MCTOK_FOR = 327,
     MCTOK_FOREACH = 328,
     MCTOK_GOTO = 329,
     MCTOK_CONTINUE = 330,
     MCTOK_BREAK = 331,
     MCTOK_RETURN = 332
   };
#endif
/* Tokens.  */
#define MCTOK_IDENTIFIER 258
#define MCTOK_CONSTANT 259
#define MCTOK_STRING_LITERAL 260
#define MCTOK_SIZEOF 261
#define MCTOK_TYPEOF 262
#define MCTOK_PTR_OP 263
#define MCTOK_INC_OP 264
#define MCTOK_DEC_OP 265
#define MCTOK_LEFT_OP 266
#define MCTOK_RIGHT_OP 267
#define MCTOK_LE_OP 268
#define MCTOK_GE_OP 269
#define MCTOK_EQ_OP 270
#define MCTOK_NE_OP 271
#define MCTOK_AND_OP 272
#define MCTOK_OR_OP 273
#define MCTOK_MUL_ASSIGN 274
#define MCTOK_DIV_ASSIGN 275
#define MCTOK_MOD_ASSIGN 276
#define MCTOK_ADD_ASSIGN 277
#define MCTOK_SUB_ASSIGN 278
#define MCTOK_LEFT_ASSIGN 279
#define MCTOK_RIGHT_ASSIGN 280
#define MCTOK_AND_ASSIGN 281
#define MCTOK_XOR_ASSIGN 282
#define MCTOK_OR_ASSIGN 283
#define MCTOK_TYPE_NAME 284
#define MCTOK_TYPEDEF 285
#define MCTOK_EXTERN 286
#define MCTOK_STATIC 287
#define MCTOK_INLINE 288
#define MCTOK_LAMBDA 289
#define MCTOK_PRIVATE 290
#define MCTOK_PUBLIC 291
#define MCTOK_VAR 292
#define MCTOK_CHAR 293
#define MCTOK_SHORT 294
#define MCTOK_INT 295
#define MCTOK_LONG 296
#define MCTOK_UCHAR 297
#define MCTOK_USHORT 298
#define MCTOK_UINT 299
#define MCTOK_ULONG 300
#define MCTOK_BOOL 301
#define MCTOK_FLOAT 302
#define MCTOK_DOUBLE 303
#define MCTOK_CONST 304
#define MCTOK_VOID 305
#define MCTOK_CATCH 306
#define MCTOK_THROW 307
#define MCTOK_TRY 308
#define MCTOK_FINALLY 309
#define MCTOK_CLASS 310
#define MCTOK_STRUCT 311
#define MCTOK_UNION 312
#define MCTOK_ENUM 313
#define MCTOK_ELLIPSIS 314
#define MCTOK_NULL 315
#define MCTOK_TRUE 316
#define MCTOK_FALSE 317
#define MCTOK_NEW 318
#define MCTOK_DELETE 319
#define MCTOK_CASE 320
#define MCTOK_DEFAULT 321
#define MCTOK_IF 322
#define MCTOK_ELSE 323
#define MCTOK_SWITCH 324
#define MCTOK_WHILE 325
#define MCTOK_DO 326
#define MCTOK_FOR 327
#define MCTOK_FOREACH 328
#define MCTOK_GOTO 329
#define MCTOK_CONTINUE 330
#define MCTOK_BREAK 331
#define MCTOK_RETURN 332




/* Copy the first part of user declarations.  */


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 37 "metac-parser.y"
{
	int mc_int;
	long mc_long;
	double mc_double;
	char mc_string[4096];
}
/* Line 193 of yacc.c.  */
#line 266 "gen-parser.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */
#line 66 "metac-parser.y"


#include <stdio.h>
#include "parser.h"

//int metac_lex(YYSTYPE* lvalp, YYLTYPE* llocp, void* scanner);

void metac_error(YYLTYPE* locp, MetaCParser* context, const char* err)
{
	if (context->fn[0] == '\0') {
		fprintf(stderr, "metac:%d: %s\n", locp->first_line, err);
	} else {
		fprintf(stderr, "metac:%s:%d: %s\n", context->fn, locp->first_line, err);
	}
}

#define scanner context->scanner



/* Line 216 of yacc.c.  */
#line 310 "gen-parser.c"

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
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  51
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1509

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  102
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  234
/* YYNRULES -- Number of states.  */
#define YYNSTATES  396

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   332

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    91,     2,     2,     2,    93,    86,     2,
      78,    79,    87,    88,    85,    89,    82,    92,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    99,   101,
      94,   100,    95,    98,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    80,     2,    81,    96,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    83,    97,    84,    90,     2,     2,     2,
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
      75,    76,    77
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    15,    20,    24,
      29,    33,    37,    40,    43,    50,    58,    60,    64,    66,
      69,    72,    75,    78,    83,    85,    87,    89,    91,    93,
      95,    97,   102,   104,   108,   112,   116,   118,   122,   126,
     128,   132,   136,   138,   142,   146,   150,   154,   156,   160,
     164,   166,   170,   172,   176,   178,   182,   184,   188,   190,
     194,   196,   202,   204,   208,   210,   212,   214,   216,   218,
     220,   222,   224,   226,   228,   230,   232,   236,   238,   241,
     245,   247,   250,   252,   255,   257,   260,   262,   265,   267,
     271,   273,   277,   279,   281,   283,   285,   287,   289,   291,
     293,   295,   297,   299,   301,   303,   305,   307,   309,   311,
     313,   319,   324,   327,   329,   331,   333,   336,   340,   343,
     345,   348,   350,   352,   356,   358,   361,   365,   370,   376,
     382,   389,   392,   394,   398,   400,   404,   406,   408,   411,
     413,   415,   419,   425,   430,   435,   442,   449,   455,   460,
     464,   469,   474,   478,   480,   483,   486,   490,   492,   495,
     497,   501,   503,   507,   510,   513,   515,   517,   521,   523,
     526,   528,   530,   533,   537,   540,   544,   548,   553,   557,
     562,   565,   569,   573,   578,   580,   584,   589,   591,   594,
     598,   603,   606,   608,   611,   615,   618,   620,   622,   624,
     626,   628,   630,   634,   639,   643,   646,   650,   652,   655,
     657,   659,   661,   664,   670,   678,   684,   690,   698,   705,
     713,   720,   728,   732,   735,   738,   741,   745,   747,   750,
     752,   754,   759,   763,   765
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     167,     0,    -1,     3,    -1,     4,    -1,     5,    -1,    78,
     122,    79,    -1,   103,    -1,   104,    80,   122,    81,    -1,
     104,    78,    79,    -1,   104,    78,   105,    79,    -1,   104,
      82,     3,    -1,   104,     8,     3,    -1,   104,     9,    -1,
     104,    10,    -1,    78,   150,    79,    83,   154,    84,    -1,
      78,   150,    79,    83,   154,    85,    84,    -1,   120,    -1,
     105,    85,   120,    -1,   104,    -1,     9,   106,    -1,    10,
     106,    -1,   107,   108,    -1,     6,   106,    -1,     6,    78,
     150,    79,    -1,    86,    -1,    87,    -1,    88,    -1,    89,
      -1,    90,    -1,    91,    -1,   106,    -1,    78,   150,    79,
     108,    -1,   108,    -1,   109,    87,   108,    -1,   109,    92,
     108,    -1,   109,    93,   108,    -1,   109,    -1,   110,    88,
     109,    -1,   110,    89,   109,    -1,   110,    -1,   111,    11,
     110,    -1,   111,    12,   110,    -1,   111,    -1,   112,    94,
     111,    -1,   112,    95,   111,    -1,   112,    13,   111,    -1,
     112,    14,   111,    -1,   112,    -1,   113,    15,   112,    -1,
     113,    16,   112,    -1,   113,    -1,   114,    86,   113,    -1,
     114,    -1,   115,    96,   114,    -1,   115,    -1,   116,    97,
     115,    -1,   116,    -1,   117,    17,   116,    -1,   117,    -1,
     118,    18,   117,    -1,   118,    -1,   118,    98,   122,    99,
     119,    -1,   119,    -1,   106,   121,   120,    -1,   100,    -1,
      19,    -1,    20,    -1,    21,    -1,    22,    -1,    23,    -1,
      24,    -1,    25,    -1,    26,    -1,    27,    -1,    28,    -1,
     120,    -1,   122,    85,   120,    -1,   119,    -1,   125,   101,
      -1,   125,   126,   101,    -1,   128,    -1,   128,   125,    -1,
     129,    -1,   129,   125,    -1,   140,    -1,   140,   125,    -1,
     141,    -1,   141,   125,    -1,   127,    -1,   126,    85,   127,
      -1,   142,    -1,   142,   100,   153,    -1,    30,    -1,    31,
      -1,    32,    -1,    50,    -1,    38,    -1,    42,    -1,    39,
      -1,    43,    -1,    40,    -1,    44,    -1,    41,    -1,    45,
      -1,    47,    -1,    48,    -1,    46,    -1,   130,    -1,   137,
      -1,    29,    -1,   131,     3,    83,   132,    84,    -1,   131,
      83,   132,    84,    -1,   131,     3,    -1,    56,    -1,    57,
      -1,   133,    -1,   132,   133,    -1,   134,   135,   101,    -1,
     129,   134,    -1,   129,    -1,   140,   134,    -1,   140,    -1,
     136,    -1,   135,    85,   136,    -1,   142,    -1,    99,   123,
      -1,   142,    99,   123,    -1,    58,    83,   138,    84,    -1,
      58,     3,    83,   138,    84,    -1,    58,    83,   138,    85,
      84,    -1,    58,     3,    83,   138,    85,    84,    -1,    58,
       3,    -1,   139,    -1,   138,    85,   139,    -1,     3,    -1,
       3,   100,   123,    -1,    49,    -1,    33,    -1,   144,   143,
      -1,   143,    -1,     3,    -1,    78,   142,    79,    -1,   143,
      80,   145,   120,    81,    -1,   143,    80,   145,    81,    -1,
     143,    80,   120,    81,    -1,   143,    80,    32,   145,   120,
      81,    -1,   143,    80,   145,    32,   120,    81,    -1,   143,
      80,   145,    87,    81,    -1,   143,    80,    87,    81,    -1,
     143,    80,    81,    -1,   143,    78,   146,    79,    -1,   143,
      78,   149,    79,    -1,   143,    78,    79,    -1,    87,    -1,
      87,   145,    -1,    87,   144,    -1,    87,   145,   144,    -1,
     140,    -1,   145,   140,    -1,   147,    -1,   147,    85,    59,
      -1,   148,    -1,   147,    85,   148,    -1,   125,   142,    -1,
     125,   151,    -1,   125,    -1,     3,    -1,   149,    85,     3,
      -1,   134,    -1,   134,   151,    -1,   144,    -1,   152,    -1,
     144,   152,    -1,    78,   151,    79,    -1,    80,    81,    -1,
      80,   120,    81,    -1,   152,    80,    81,    -1,   152,    80,
     120,    81,    -1,    80,    87,    81,    -1,   152,    80,    87,
      81,    -1,    78,    79,    -1,    78,   146,    79,    -1,   152,
      78,    79,    -1,   152,    78,   146,    79,    -1,   120,    -1,
      83,   154,    84,    -1,    83,   154,    85,    84,    -1,   153,
      -1,   155,   153,    -1,   154,    85,   153,    -1,   154,    85,
     155,   153,    -1,   156,   100,    -1,   157,    -1,   156,   157,
      -1,    80,   123,    81,    -1,    82,     3,    -1,   159,    -1,
     160,    -1,   163,    -1,   164,    -1,   165,    -1,   166,    -1,
       3,    99,   158,    -1,    65,   123,    99,   158,    -1,    66,
      99,   158,    -1,    83,    84,    -1,    83,   161,    84,    -1,
     162,    -1,   161,   162,    -1,   124,    -1,   158,    -1,   101,
      -1,   122,   101,    -1,    67,    78,   122,    79,   158,    -1,
      67,    78,   122,    79,   158,    68,   158,    -1,    69,    78,
     122,    79,   158,    -1,    70,    78,   122,    79,   158,    -1,
      71,   158,    70,    78,   122,    79,   101,    -1,    72,    78,
     163,   163,    79,   158,    -1,    72,    78,   163,   163,   122,
      79,   158,    -1,    72,    78,   124,   163,    79,   158,    -1,
      72,    78,   124,   163,   122,    79,   158,    -1,    74,     3,
     101,    -1,    75,   101,    -1,    76,   101,    -1,    77,   101,
      -1,    77,   122,   101,    -1,   168,    -1,   167,   168,    -1,
     169,    -1,   124,    -1,   125,   142,   170,   160,    -1,   125,
     142,   160,    -1,   124,    -1,   170,   124,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    89,    89,    90,    91,    92,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   109,   110,   114,   115,
     116,   117,   118,   119,   123,   124,   125,   126,   127,   128,
     132,   133,   137,   138,   139,   140,   144,   145,   146,   150,
     151,   152,   156,   157,   158,   159,   160,   164,   165,   166,
     170,   171,   175,   176,   180,   181,   185,   186,   190,   191,
     195,   196,   200,   201,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   219,   220,   224,   228,   229,
     233,   234,   235,   236,   237,   238,   239,   240,   244,   245,
     249,   250,   254,   255,   256,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     278,   279,   280,   284,   285,   289,   290,   294,   298,   299,
     300,   301,   305,   306,   310,   311,   312,   316,   317,   318,
     319,   320,   324,   325,   329,   330,   334,   338,   342,   343,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   364,   365,   366,   367,   371,   372,   377,
     378,   382,   383,   387,   388,   389,   393,   394,   398,   399,
     403,   404,   405,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   423,   424,   425,   429,   430,   431,
     432,   436,   440,   441,   445,   446,   450,   451,   452,   453,
     454,   455,   459,   460,   461,   465,   466,   470,   471,   475,
     476,   480,   481,   485,   486,   487,   491,   492,   493,   494,
     495,   496,   500,   501,   502,   503,   504,   508,   509,   513,
     514,   518,   519,   523,   524
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MCTOK_IDENTIFIER", "MCTOK_CONSTANT",
  "MCTOK_STRING_LITERAL", "MCTOK_SIZEOF", "MCTOK_TYPEOF", "MCTOK_PTR_OP",
  "MCTOK_INC_OP", "MCTOK_DEC_OP", "MCTOK_LEFT_OP", "MCTOK_RIGHT_OP",
  "MCTOK_LE_OP", "MCTOK_GE_OP", "MCTOK_EQ_OP", "MCTOK_NE_OP",
  "MCTOK_AND_OP", "MCTOK_OR_OP", "MCTOK_MUL_ASSIGN", "MCTOK_DIV_ASSIGN",
  "MCTOK_MOD_ASSIGN", "MCTOK_ADD_ASSIGN", "MCTOK_SUB_ASSIGN",
  "MCTOK_LEFT_ASSIGN", "MCTOK_RIGHT_ASSIGN", "MCTOK_AND_ASSIGN",
  "MCTOK_XOR_ASSIGN", "MCTOK_OR_ASSIGN", "MCTOK_TYPE_NAME",
  "MCTOK_TYPEDEF", "MCTOK_EXTERN", "MCTOK_STATIC", "MCTOK_INLINE",
  "MCTOK_LAMBDA", "MCTOK_PRIVATE", "MCTOK_PUBLIC", "MCTOK_VAR",
  "MCTOK_CHAR", "MCTOK_SHORT", "MCTOK_INT", "MCTOK_LONG", "MCTOK_UCHAR",
  "MCTOK_USHORT", "MCTOK_UINT", "MCTOK_ULONG", "MCTOK_BOOL", "MCTOK_FLOAT",
  "MCTOK_DOUBLE", "MCTOK_CONST", "MCTOK_VOID", "MCTOK_CATCH",
  "MCTOK_THROW", "MCTOK_TRY", "MCTOK_FINALLY", "MCTOK_CLASS",
  "MCTOK_STRUCT", "MCTOK_UNION", "MCTOK_ENUM", "MCTOK_ELLIPSIS",
  "MCTOK_NULL", "MCTOK_TRUE", "MCTOK_FALSE", "MCTOK_NEW", "MCTOK_DELETE",
  "MCTOK_CASE", "MCTOK_DEFAULT", "MCTOK_IF", "MCTOK_ELSE", "MCTOK_SWITCH",
  "MCTOK_WHILE", "MCTOK_DO", "MCTOK_FOR", "MCTOK_FOREACH", "MCTOK_GOTO",
  "MCTOK_CONTINUE", "MCTOK_BREAK", "MCTOK_RETURN", "'('", "')'", "'['",
  "']'", "'.'", "'{'", "'}'", "','", "'&'", "'*'", "'+'", "'-'", "'~'",
  "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='",
  "';'", "$accept", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "function_specifier", "declarator",
  "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "designation", "designator_list", "designator", "statement",
  "labeled_statement", "compound_statement", "block_item_list",
  "block_item", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "declaration_list", 0
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
     325,   326,   327,   328,   329,   330,   331,   332,    40,    41,
      91,    93,    46,   123,   125,    44,    38,    42,    43,    45,
     126,    33,    47,    37,    60,    62,    94,   124,    63,    58,
      61,    59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   102,   103,   103,   103,   103,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   105,   105,   106,   106,
     106,   106,   106,   106,   107,   107,   107,   107,   107,   107,
     108,   108,   109,   109,   109,   109,   110,   110,   110,   111,
     111,   111,   112,   112,   112,   112,   112,   113,   113,   113,
     114,   114,   115,   115,   116,   116,   117,   117,   118,   118,
     119,   119,   120,   120,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   122,   122,   123,   124,   124,
     125,   125,   125,   125,   125,   125,   125,   125,   126,   126,
     127,   127,   128,   128,   128,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     130,   130,   130,   131,   131,   132,   132,   133,   134,   134,
     134,   134,   135,   135,   136,   136,   136,   137,   137,   137,
     137,   137,   138,   138,   139,   139,   140,   141,   142,   142,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   144,   144,   144,   144,   145,   145,   146,
     146,   147,   147,   148,   148,   148,   149,   149,   150,   150,
     151,   151,   151,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   153,   153,   153,   154,   154,   154,
     154,   155,   156,   156,   157,   157,   158,   158,   158,   158,
     158,   158,   159,   159,   159,   160,   160,   161,   161,   162,
     162,   163,   163,   164,   164,   164,   165,   165,   165,   165,
     165,   165,   166,   166,   166,   166,   166,   167,   167,   168,
     168,   169,   169,   170,   170
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     6,     7,     1,     3,     1,     2,
       2,     2,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     3,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     4,     2,     1,     1,     1,     2,     3,     2,     1,
       2,     1,     1,     3,     1,     2,     3,     4,     5,     5,
       6,     2,     1,     3,     1,     3,     1,     1,     2,     1,
       1,     3,     5,     4,     4,     6,     6,     5,     4,     3,
       4,     4,     3,     1,     2,     2,     3,     1,     2,     1,
       3,     1,     3,     2,     2,     1,     1,     3,     1,     2,
       1,     1,     2,     3,     2,     3,     3,     4,     3,     4,
       2,     3,     3,     4,     1,     3,     4,     1,     2,     3,
       4,     2,     1,     2,     3,     2,     1,     1,     1,     1,
       1,     1,     3,     4,     3,     2,     3,     1,     2,     1,
       1,     1,     2,     5,     7,     5,     5,     7,     6,     7,
       6,     7,     3,     2,     2,     2,     3,     1,     2,     1,
       1,     4,     3,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   109,    92,    93,    94,   137,    96,    98,   100,   102,
      97,    99,   101,   103,   106,   104,   105,   136,    95,   113,
     114,     0,   230,     0,    80,    82,   107,     0,   108,    84,
      86,     0,   227,   229,   131,     0,   140,     0,   153,    78,
       0,    88,    90,   139,     0,    81,    83,   112,     0,    85,
      87,     1,   228,     0,   134,     0,   132,     0,   157,   155,
     154,     0,    79,     0,     0,   233,     0,   232,     0,     0,
       0,   138,     0,   119,     0,   115,     0,   121,     0,     0,
     127,     0,   141,   158,   156,    89,    90,     2,     3,     4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   205,    24,    25,    26,    27,
      28,    29,   211,     6,    18,    30,     0,    32,    36,    39,
      42,    47,    50,    52,    54,    56,    58,    60,    62,    75,
       0,   209,   210,   196,   197,     0,   207,   198,   199,   200,
     201,     2,     0,   184,    91,   234,   231,   166,   152,   165,
       0,   159,   161,     0,     0,   149,    25,     0,     0,     0,
     118,   111,   116,     0,     0,   122,   124,   120,   128,     0,
      30,    77,   135,   129,   133,     0,     0,    22,     0,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,   223,
     224,   225,     0,     0,   168,     0,     0,    12,    13,     0,
       0,     0,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    64,     0,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   212,   206,   208,     0,     0,
     187,     0,     0,     0,   192,     0,     0,   163,   170,   164,
     171,   150,     0,   151,     0,     0,   148,   144,     0,   143,
      25,     0,   110,   125,     0,   117,     0,   130,   202,     0,
       0,     0,   204,     0,     0,     0,     0,     0,     0,   222,
     226,     5,     0,   170,   169,     0,    11,     8,     0,    16,
       0,    10,    63,    33,    34,    35,    37,    38,    40,    41,
      45,    46,    43,    44,    48,    49,    51,    53,    55,    57,
      59,     0,    76,     0,   195,   185,     0,   188,   191,   193,
     180,     0,     0,   174,    25,     0,   172,     0,     0,   160,
     162,   167,     0,     0,   147,   142,   123,   126,    23,     0,
     203,     0,     0,     0,     0,     0,     0,     0,    31,     9,
       0,     7,     0,   194,   186,   189,     0,   181,   173,   178,
     175,   182,     0,   176,    25,     0,   145,   146,   213,   215,
     216,     0,     0,     0,     0,     0,     0,    17,    61,   190,
     183,   179,   177,     0,     0,   220,     0,   218,     0,    14,
       0,   214,   217,   221,   219,    15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   113,   114,   288,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   213,
     130,   172,    22,    66,    40,    41,    24,    25,    26,    27,
      74,    75,    76,   164,   165,    28,    55,    56,    29,    30,
      57,    43,    44,    60,   321,   151,   152,   153,   195,   322,
     250,   240,   241,   242,   243,   244,   132,   133,   134,   135,
     136,   137,   138,   139,   140,    31,    32,    33,    68
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -271
static const yytype_int16 yypact[] =
{
    1451,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,
    -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,
    -271,    11,  -271,    40,  1451,  1451,  -271,    18,  -271,  1451,
    1451,  1274,  -271,  -271,   -50,    89,  -271,    39,    -1,  -271,
     -25,  -271,  1192,    56,    61,  -271,  -271,    28,  1343,  -271,
    -271,  -271,  -271,    89,   -34,   142,  -271,    43,  -271,  -271,
      -1,    39,  -271,   344,   818,  -271,    40,  -271,  1365,  1150,
     728,    56,  1343,  1343,  1296,  -271,     4,  1343,   165,   995,
    -271,    15,  -271,  -271,  -271,  -271,    25,    71,  -271,  -271,
    1028,  1084,  1084,   995,    79,    97,   109,   113,   578,   116,
     159,   117,   127,   143,   667,  -271,  -271,  -271,  -271,  -271,
    -271,  -271,  -271,  -271,   415,   317,   995,  -271,    -9,   171,
      77,    49,   249,   149,   157,   184,   269,    32,  -271,  -271,
     -20,  -271,  -271,  -271,  -271,   433,  -271,  -271,  -271,  -271,
    -271,  -271,   770,  -271,  -271,  -271,  -271,  -271,  -271,    51,
     223,   219,  -271,     8,   256,  -271,   225,   227,   788,  1318,
    -271,  -271,  -271,   995,    65,  -271,   210,  -271,  -271,    31,
    -271,  -271,  -271,  -271,  -271,   578,   667,  -271,   667,  -271,
    -271,   211,   578,   995,   995,   995,   242,   522,   213,  -271,
    -271,  -271,    70,    84,    81,   239,   322,  -271,  -271,   362,
     995,   323,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,
    -271,  -271,  -271,   995,  -271,   995,   995,   995,   995,   995,
     995,   995,   995,   995,   995,   995,   995,   995,   995,   995,
     995,   995,   995,   995,   995,  -271,  -271,  -271,   995,   327,
    -271,   187,   818,    76,  -271,  1098,   835,  -271,    55,  -271,
      87,  -271,  1429,  -271,   328,   878,  -271,  -271,   995,  -271,
     251,   252,  -271,  -271,     4,  -271,   995,  -271,  -271,   267,
     272,   578,  -271,    98,   100,   110,   257,   538,   538,  -271,
    -271,  -271,  1222,   112,  -271,   925,  -271,  -271,   137,  -271,
     -29,  -271,  -271,  -271,  -271,  -271,    -9,    -9,   171,   171,
      77,    77,    77,    77,    49,    49,   249,   149,   157,   184,
     269,   -32,  -271,   271,  -271,  -271,   233,  -271,  -271,  -271,
    -271,   276,   277,  -271,   278,   279,    87,  1387,   939,  -271,
    -271,  -271,   282,   283,  -271,  -271,  -271,  -271,   275,   275,
    -271,   578,   578,   578,   995,   967,   981,   770,  -271,  -271,
     995,  -271,   995,  -271,  -271,  -271,   818,  -271,  -271,  -271,
    -271,  -271,   290,  -271,   289,   297,  -271,  -271,   312,  -271,
    -271,   138,   578,   140,   578,   161,   194,  -271,  -271,  -271,
    -271,  -271,  -271,   578,   294,  -271,   578,  -271,   578,  -271,
     681,  -271,  -271,  -271,  -271,  -271
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -271,  -271,  -271,  -271,   -18,  -271,  -111,    78,    63,    68,
      73,   168,   169,   167,   172,   173,  -271,   -78,   -62,  -271,
     -76,   -84,   -23,     0,  -271,   338,  -271,   -36,  -271,  -271,
     332,   -64,   -57,  -271,   144,  -271,   353,   -59,   203,  -271,
     -17,   -33,   -21,   -38,   -65,  -271,   155,  -271,  -121,  -123,
    -213,   -61,    82,  -270,  -271,   183,   -85,  -271,     9,  -271,
     309,  -164,  -271,  -271,  -271,  -271,   381,  -271,  -271
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      23,   171,   143,   144,   150,   214,    42,    36,   157,   181,
     162,    71,    73,   186,    34,   171,   160,    59,    54,    65,
     167,    47,   174,   278,    45,    46,   249,   192,   193,    49,
      50,    23,   158,    53,    54,   326,    73,    73,    73,    84,
     131,    73,    36,    36,    86,   145,   356,   194,    17,    86,
     232,    67,   351,   234,    36,   269,   234,   270,    36,   166,
      61,   170,   222,   223,    36,   234,    79,   352,    73,   149,
     326,   284,   177,   179,   180,   170,    62,   146,   215,   263,
     143,   235,    37,   216,   217,   171,    38,   253,   220,   221,
     268,    38,    54,   254,    35,   162,   261,   272,   170,   173,
     193,    48,   193,   163,   293,   294,   295,   273,   274,   275,
     174,    72,   131,   345,   346,   267,   255,    37,    37,   194,
     356,   194,    82,    73,   290,    64,    38,    38,   248,   245,
     233,   246,   247,   245,    69,   246,    70,   289,    38,    37,
      73,    39,    73,   224,   225,   170,   141,    88,    89,    90,
     264,   292,    91,    92,   313,   234,   238,   311,   239,   282,
     171,   246,   188,   281,   277,   327,   265,   328,    38,   234,
     175,   280,   312,   283,   348,   183,   318,   341,   182,   342,
     143,   317,   337,   234,   325,   234,   340,   184,   171,   343,
     282,   185,   246,   332,   187,   234,   333,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,    71,   349,   384,   189,   386,
     170,   104,   350,   234,   248,   234,    80,    81,   190,   106,
     107,   108,   109,   110,   111,   228,   141,    88,    89,    90,
     388,    58,    91,    92,   191,   149,   234,   166,   170,   168,
     169,    77,   149,   229,   143,   355,   368,   369,   370,   218,
     219,   283,   362,    83,   226,   227,   365,   170,   371,   373,
     375,   315,   316,    58,   378,    77,    77,    77,   389,   390,
      77,   230,   149,   298,   299,   143,   231,   385,   377,   387,
     300,   301,   302,   303,   143,   379,   296,   297,   391,   304,
     305,   393,   251,   394,   252,    17,   256,    77,   257,   266,
     271,   104,   276,   238,   279,   239,   142,   354,   285,   106,
     107,   108,   109,   110,   111,   286,   291,   149,   143,   355,
     314,   331,   334,   335,   170,   344,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   338,    87,    88,    89,
      90,   339,   353,    91,    92,   357,   358,    58,   347,   359,
     360,    83,    77,   366,   367,   141,    88,    89,    90,   380,
     381,    91,    92,     1,     2,     3,     4,     5,   382,    77,
     383,    77,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,   392,   306,   308,   307,    85,
      19,    20,    21,   309,   159,   310,    78,   330,   336,    93,
      94,    95,    52,    96,    97,    98,    99,   212,   100,   101,
     102,   103,   104,   196,   197,   198,   319,    63,   105,   376,
     106,   107,   108,   109,   110,   111,    87,    88,    89,    90,
     104,   287,    91,    92,   237,   112,     0,     0,   106,   107,
     108,   109,   110,   111,     0,     0,     0,     0,    83,     0,
       0,     0,     1,     2,     3,     4,     5,     0,     0,     0,
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,     0,     0,     0,     0,     0,    19,
      20,    21,     0,   199,     0,   200,     0,   201,    93,    94,
      95,     0,    96,    97,    98,    99,     0,   100,   101,   102,
     103,   104,     0,     0,     0,     0,    63,   236,     0,   106,
     107,   108,   109,   110,   111,   141,    88,    89,    90,     0,
       0,    91,    92,     0,   112,     0,     0,     0,     0,     0,
       0,   141,    88,    89,    90,     0,     0,    91,    92,     0,
       0,     1,     2,     3,     4,     5,     0,     0,     0,     0,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,     0,     0,     0,     0,     0,    19,    20,
      21,    87,    88,    89,    90,     0,     0,    91,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,     0,     0,     0,     0,     0,     0,     0,   106,   107,
     108,   109,   110,   111,     0,     0,   104,     0,     0,     0,
       0,     0,     0,   112,   106,   107,   108,   109,   110,   111,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   112,
       0,     0,     0,    93,    94,    95,     0,    96,    97,    98,
      99,     0,   100,   101,   102,   103,   104,     0,     0,     0,
       0,    63,     0,     0,   106,   107,   108,   109,   110,   111,
     141,    88,    89,    90,     0,     0,    91,    92,     0,   112,
       0,     0,     0,     0,   141,    88,    89,    90,     0,     0,
      91,    92,     0,     0,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,     0,     0,
       0,     0,     0,    19,    20,    21,     0,     0,     0,     0,
       0,   141,    88,    89,    90,     0,     0,    91,    92,     0,
       0,     0,     0,     0,     0,   104,     0,     0,     0,     0,
       0,     0,     0,   106,   107,   108,   109,   110,   111,   104,
     154,   238,     0,   239,   142,   395,     0,   106,   107,   108,
     109,   110,   111,   141,    88,    89,    90,    17,     0,    91,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,    88,    89,    90,     0,     0,    91,    92,     0,
       0,     0,     0,     0,     0,     0,   104,     0,     0,   155,
       0,     0,     0,     0,   106,   156,   108,   109,   110,   111,
     258,   141,    88,    89,    90,     0,     0,    91,    92,     0,
       0,     0,     0,     0,     0,     0,     0,    17,   141,    88,
      89,    90,     0,     0,    91,    92,     0,     0,   104,     0,
     238,     0,   239,   142,     0,     0,   106,   107,   108,   109,
     110,   111,     0,     0,     0,     0,   104,     0,     0,   259,
       0,     0,     0,     0,   106,   260,   108,   109,   110,   111,
       0,   141,    88,    89,    90,     0,     0,    91,    92,     0,
       0,     0,     0,     0,     0,     0,   104,     0,     0,     0,
       0,   142,     0,     0,   106,   107,   108,   109,   110,   111,
       0,     0,     0,   104,     0,     0,   323,     0,     0,     0,
       0,   106,   324,   108,   109,   110,   111,    17,   141,    88,
      89,    90,     0,     0,    91,    92,     0,     0,     0,     0,
       0,     0,   141,    88,    89,    90,     0,     0,    91,    92,
       0,     0,     0,     0,     0,     0,   104,     0,     0,     0,
       0,     0,     0,     0,   106,   107,   108,   109,   110,   111,
     141,    88,    89,    90,     0,     0,    91,    92,     0,     0,
       0,     0,     0,     0,   141,    88,    89,    90,     0,     0,
      91,    92,     0,     0,     0,     0,     0,     0,   141,    88,
      89,    90,     0,   104,    91,    92,     0,     0,   347,     0,
       0,   106,   107,   108,   109,   110,   111,   104,     0,     0,
     363,     0,     0,     0,     0,   106,   364,   108,   109,   110,
     111,   141,    88,    89,    90,     0,     0,    91,    92,     0,
       0,     0,     0,     0,     0,   104,   372,     0,     0,     0,
       0,     0,     0,   106,   107,   108,   109,   110,   111,   104,
     374,     0,     0,     0,     0,     0,     0,   106,   107,   108,
     109,   110,   111,   104,     0,     0,     0,     0,     0,     0,
       0,   106,   107,   108,   109,   110,   111,   141,    88,    89,
      90,     0,     0,    91,    92,     0,     0,     0,     0,     0,
       0,    36,     0,     0,     0,     0,   176,     0,     0,     0,
       0,     0,     0,     0,   106,   107,   108,   109,   110,   111,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       4,     5,     0,     0,     0,     0,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,     0,
       0,     0,     0,   147,    19,    20,    21,     0,     0,     0,
       0,     0,   178,     0,     0,     0,     0,     0,     0,     0,
     106,   107,   108,   109,   110,   111,   245,   320,   246,     1,
       2,     3,     4,     5,     0,    38,     0,     0,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,     0,     0,     0,     0,     0,    19,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     3,     4,     5,     0,     0,     0,   148,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,     0,     0,     0,     0,     0,    19,    20,
      21,     1,     2,     3,     4,     5,     0,     0,     0,     0,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,     0,    51,    63,     0,     0,    19,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    64,     0,     0,     0,     0,     0,     0,     0,
     282,   320,   246,     1,     2,     3,     4,     5,     0,    38,
       0,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,     1,     0,     0,     0,     0,
      19,    20,    21,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,     1,     0,     0,
       0,     0,    19,    20,    21,     0,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,     0,
       0,     0,     1,     0,    19,    20,    21,     0,     0,     0,
     161,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,     1,     2,     3,     4,     5,    19,
      20,    21,   262,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,     1,     2,     3,     4,
       5,    19,    20,    21,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,     0,     0,
       0,     0,     0,    19,    20,    21,     0,     0,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       3,     4,     5,     0,     0,     0,   361,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
       1,     2,     3,     4,     5,    19,    20,    21,   329,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,     0,     0,     0,     0,     0,    19,    20,    21
};

static const yytype_int16 yycheck[] =
{
       0,    79,    64,    64,    69,   116,    23,     3,    70,    93,
      74,    44,    48,    98,     3,    93,    73,    38,     3,    42,
      77,     3,    81,   187,    24,    25,   149,   103,   104,    29,
      30,    31,    70,    83,     3,   248,    72,    73,    74,    60,
      63,    77,     3,     3,    61,    68,   316,   104,    49,    66,
      18,    42,    81,    85,     3,   176,    85,   178,     3,    76,
      85,    79,    13,    14,     3,    85,   100,    99,   104,    69,
     283,   194,    90,    91,    92,    93,   101,    68,    87,   163,
     142,   101,    78,    92,    93,   163,    87,    79,    11,    12,
     175,    87,     3,    85,    83,   159,   158,   182,   116,    84,
     176,    83,   178,    99,   215,   216,   217,   183,   184,   185,
     169,    83,   135,   277,   278,    84,   154,    78,    78,   176,
     390,   178,    79,   159,   200,   100,    87,    87,   149,    78,
      98,    80,   149,    78,    78,    80,    80,   199,    87,    78,
     176,   101,   178,    94,    95,   163,     3,     4,     5,     6,
      85,   213,     9,    10,   238,    85,    80,   233,    82,    78,
     238,    80,     3,    79,   187,    78,   101,    80,    87,    85,
      99,   101,   234,   194,   285,    78,   100,    79,    99,    79,
     242,   242,   266,    85,   246,    85,   271,    78,   266,    79,
      78,    78,    80,   255,    78,    85,   258,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   248,    79,    79,   101,    79,
     238,    78,    85,    85,   245,    85,    84,    85,   101,    86,
      87,    88,    89,    90,    91,    86,     3,     4,     5,     6,
      79,    38,     9,    10,   101,   245,    85,   264,   266,    84,
      85,    48,   252,    96,   316,   316,   341,   342,   343,    88,
      89,   282,   327,    60,    15,    16,   328,   285,   344,   345,
     346,    84,    85,    70,   352,    72,    73,    74,    84,    85,
      77,    97,   282,   220,   221,   347,    17,   372,   350,   374,
     222,   223,   224,   225,   356,   356,   218,   219,   383,   226,
     227,   386,    79,   388,    85,    49,    81,   104,    81,    99,
      99,    78,    70,    80,   101,    82,    83,    84,    79,    86,
      87,    88,    89,    90,    91,     3,     3,   327,   390,   390,
       3,     3,    81,    81,   352,    78,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    79,     3,     4,     5,
       6,    79,    81,     9,    10,    79,    79,   154,    83,    81,
      81,   158,   159,    81,    81,     3,     4,     5,     6,    79,
      81,     9,    10,    29,    30,    31,    32,    33,    81,   176,
      68,   178,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,   101,   228,   230,   229,    61,
      56,    57,    58,   231,    72,   232,    53,   252,   264,    65,
      66,    67,    31,    69,    70,    71,    72,   100,    74,    75,
      76,    77,    78,     8,     9,    10,   243,    83,    84,   347,
      86,    87,    88,    89,    90,    91,     3,     4,     5,     6,
      78,    79,     9,    10,   135,   101,    -1,    -1,    86,    87,
      88,    89,    90,    91,    -1,    -1,    -1,    -1,   255,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,    56,
      57,    58,    -1,    78,    -1,    80,    -1,    82,    65,    66,
      67,    -1,    69,    70,    71,    72,    -1,    74,    75,    76,
      77,    78,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,
      87,    88,    89,    90,    91,     3,     4,     5,     6,    -1,
      -1,     9,    10,    -1,   101,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,    -1,     9,    10,    -1,
      -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,     3,     4,     5,     6,    -1,    -1,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      88,    89,    90,    91,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    -1,   101,    86,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,
      -1,    -1,    -1,    65,    66,    67,    -1,    69,    70,    71,
      72,    -1,    74,    75,    76,    77,    78,    -1,    -1,    -1,
      -1,    83,    -1,    -1,    86,    87,    88,    89,    90,    91,
       3,     4,     5,     6,    -1,    -1,     9,    10,    -1,   101,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,    -1,
       9,    10,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,    -1,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    91,    78,
      32,    80,    -1,    82,    83,    84,    -1,    86,    87,    88,
      89,    90,    91,     3,     4,     5,     6,    49,    -1,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,    -1,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,    91,
      32,     3,     4,     5,     6,    -1,    -1,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,     3,     4,
       5,     6,    -1,    -1,     9,    10,    -1,    -1,    78,    -1,
      80,    -1,    82,    83,    -1,    -1,    86,    87,    88,    89,
      90,    91,    -1,    -1,    -1,    -1,    78,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,    91,
      -1,     3,     4,     5,     6,    -1,    -1,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    83,    -1,    -1,    86,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    78,    -1,    -1,    81,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    90,    91,    49,     3,     4,
       5,     6,    -1,    -1,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,    -1,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,    91,
       3,     4,     5,     6,    -1,    -1,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,    -1,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,    78,     9,    10,    -1,    -1,    83,    -1,
      -1,    86,    87,    88,    89,    90,    91,    78,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,
      91,     3,     4,     5,     6,    -1,    -1,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    91,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,
      89,    90,    91,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    90,    91,     3,     4,     5,
       6,    -1,    -1,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    -1,     3,    56,    57,    58,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    88,    89,    90,    91,    78,    79,    80,    29,
      30,    31,    32,    33,    -1,    87,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,    79,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,     0,    83,    -1,    -1,    56,    57,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    29,    30,    31,    32,    33,    -1,    87,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    29,    -1,    -1,    -1,    -1,
      56,    57,    58,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    29,    -1,    -1,
      -1,    -1,    56,    57,    58,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    29,    -1,    56,    57,    58,    -1,    -1,    -1,
      84,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    29,    30,    31,    32,    33,    56,
      57,    58,    84,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    29,    30,    31,    32,
      33,    56,    57,    58,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    -1,    -1,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    79,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      29,    30,    31,    32,    33,    56,    57,    58,    59,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    -1,    -1,    56,    57,    58
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    29,    30,    31,    32,    33,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    56,
      57,    58,   124,   125,   128,   129,   130,   131,   137,   140,
     141,   167,   168,   169,     3,    83,     3,    78,    87,   101,
     126,   127,   142,   143,   144,   125,   125,     3,    83,   125,
     125,     0,   168,    83,     3,   138,   139,   142,   140,   144,
     145,    85,   101,    83,   100,   124,   125,   160,   170,    78,
      80,   143,    83,   129,   132,   133,   134,   140,   138,   100,
      84,    85,    79,   140,   144,   127,   142,     3,     4,     5,
       6,     9,    10,    65,    66,    67,    69,    70,    71,    72,
      74,    75,    76,    77,    78,    84,    86,    87,    88,    89,
      90,    91,   101,   103,   104,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     122,   124,   158,   159,   160,   161,   162,   163,   164,   165,
     166,     3,    83,   120,   153,   124,   160,     3,    79,   125,
     146,   147,   148,   149,    32,    81,    87,   120,   145,   132,
     134,    84,   133,    99,   135,   136,   142,   134,    84,    85,
     106,   119,   123,    84,   139,    99,    78,   106,    78,   106,
     106,   123,    99,    78,    78,    78,   158,    78,     3,   101,
     101,   101,   122,   122,   134,   150,     8,     9,    10,    78,
      80,    82,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,   100,   121,   108,    87,    92,    93,    88,    89,
      11,    12,    13,    14,    94,    95,    15,    16,    86,    96,
      97,    17,    18,    98,    85,   101,    84,   162,    80,    82,
     153,   154,   155,   156,   157,    78,    80,   142,   144,   151,
     152,    79,    85,    79,    85,   145,    81,    81,    32,    81,
      87,   120,    84,   123,    85,   101,    99,    84,   158,   150,
     150,    99,   158,   122,   122,   122,    70,   124,   163,   101,
     101,    79,    78,   144,   151,    79,     3,    79,   105,   120,
     122,     3,   120,   108,   108,   108,   109,   109,   110,   110,
     111,   111,   111,   111,   112,   112,   113,   114,   115,   116,
     117,   122,   120,   123,     3,    84,    85,   153,   100,   157,
      79,   146,   151,    81,    87,   120,   152,    78,    80,    59,
     148,     3,   120,   120,    81,    81,   136,   123,    79,    79,
     158,    79,    79,    79,    78,   163,   163,    83,   108,    79,
      85,    81,    99,    81,    84,   153,   155,    79,    79,    81,
      81,    79,   146,    81,    87,   120,    81,    81,   158,   158,
     158,   122,    79,   122,    79,   122,   154,   120,   119,   153,
      79,    81,    81,    68,    79,   158,    79,   158,    79,    84,
      85,   158,   101,   158,   158,    84
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
      yyerror (&yylloc, context, YY_("syntax error: cannot back up")); \
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
# define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, &yylloc, scanner)
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
		  Type, Value, Location, context); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, MetaCParser *context)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, context)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    MetaCParser *context;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (context);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, MetaCParser *context)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, context)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    MetaCParser *context;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, context);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, MetaCParser *context)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, context)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    MetaCParser *context;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , context);
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, context); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, MetaCParser *context)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, context)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    MetaCParser *context;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (context);

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
int yyparse (MetaCParser *context);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */






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
yyparse (MetaCParser *context)
#else
int
yyparse (context)
    MetaCParser *context;
#endif
#endif
{
  /* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;

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

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

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
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
      
/* Line 1267 of yacc.c.  */
#line 2176 "gen-parser.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
      yyerror (&yylloc, context, YY_("syntax error"));
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
	    yyerror (&yylloc, context, yymsg);
	  }
	else
	  {
	    yyerror (&yylloc, context, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

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
		      yytoken, &yylval, &yylloc, context);
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

  yyerror_range[0] = yylsp[1-yylen];
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp, context);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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
  yyerror (&yylloc, context, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc, context);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, context);
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


#line 528 "metac-parser.y"


