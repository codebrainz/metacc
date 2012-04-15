/*
 * Copyright (c) 2012 Matthew Brush <mbrush@codebrainz.ca>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef METAC_TOKEN_H
#define METAC_TOKEN_H

#define MCTOK_MAXLEN 4096

/* todo: these will be moved to Bison parser */
typedef enum {
  MCTOK_EOF=0,

  MCTOK_IDENTIFIER,
  MCTOK_STRING_LITERAL,
  MCTOK_CONSTANT,

  /* Keywords */
  MCTOK_BOOL,
  MCTOK_BREAK,
  MCTOK_CASE,
  MCTOK_CATCH,
  MCTOK_CHAR,
  MCTOK_CLASS,
  MCTOK_CONST,
  MCTOK_CONTINUE,
  MCTOK_DEFAULT,
  MCTOK_DO,
  MCTOK_DOUBLE,
  MCTOK_ELSE,
  MCTOK_ENUM,
  MCTOK_EXTERN,
  MCTOK_FINALLY,
  MCTOK_FLOAT,
  MCTOK_FOR,
  MCTOK_FOREACH,
  MCTOK_GOTO,
  MCTOK_IF,
  MCTOK_INLINE,
  MCTOK_INT,
  MCTOK_LAMBDA,
  MCTOK_LONG,
  MCTOK_PRIVATE,
  MCTOK_PUBLIC,
  MCTOK_RETURN,
  MCTOK_SHORT,
  MCTOK_SIGNED,
  MCTOK_SIZEOF,
  MCTOK_STATIC,
  MCTOK_STRUCT,
  MCTOK_SWITCH,
  MCTOK_THROW,
  MCTOK_TRY,
  MCTOK_TYPEDEF,
  MCTOK_UNION,
  MCTOK_UNSIGNED,
  MCTOK_VAR,
  MCTOK_VOID,
  MCTOK_WHILE,

  /* Operators */
  MCTOK_ELLIPSIS,
  MCTOK_RIGHT_ASSIGN,
  MCTOK_LEFT_ASSIGN,
  MCTOK_ADD_ASSIGN,
  MCTOK_SUB_ASSIGN,
  MCTOK_MUL_ASSIGN,
  MCTOK_DIV_ASSIGN,
  MCTOK_MOD_ASSIGN,
  MCTOK_AND_ASSIGN,
  MCTOK_XOR_ASSIGN,
  MCTOK_OR_ASSIGN,
  MCTOK_RIGHT_OP,
  MCTOK_LEFT_OP,
  MCTOK_INC_OP,
  MCTOK_DEC_OP,
  MCTOK_PTR_OP,
  MCTOK_AND_OP,
  MCTOK_OR_OP,
  MCTOK_LE_OP,
  MCTOK_GE_OP,
  MCTOK_EQ_OP,
  MCTOK_NE_OP,

  /* Add token types above this line. */
  MCTOK_LAST
} MetaCTokenType;

typedef struct {
  MetaCTokenType type;
  char text[MCTOK_MAXLEN];
#if 0
  struct {
    int offset;
    int lineNum;
    int column;
  } address;
#endif
} MetaCToken;

/*
 * Resets a token to its initial default state.
 */
void metac_token_reset(MetaCToken *tok);

#endif /* METAC_TOKEN_H */
