/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 37 "metac-parser.y"
{
	int mc_int;
	long mc_long;
	double mc_double;
	char mc_string[4096];
}
/* Line 1529 of yacc.c.  */
#line 210 "gen-parser.h"
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


