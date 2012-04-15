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

#ifndef METAC_LEXER_H_
#define METAC_LEXER_H_ 1

#include <limits.h>
#include "token.h"

/*
 * Opaque handle for the MetaC Lexer private data used to hide internal
 * state information and such.
 */
typedef struct _metac_lexer_private_t MetaCLexerPrivate;

/*
 * Main lexer "object".
 */
typedef struct {
  char fileName[PATH_MAX];
  MetaCToken tok; /* current token */
  struct {
    int offset;   /* cursor position after token */
    int lineNum;  /* number of '\n' seen so far */
    int column;   /* column on current line (starts at 0) */
  } address;
  MetaCLexerPrivate *priv;
}
MetaCLexer;

/*
 * Open a filename to read its tokens. The returned pointer must be freed
 * with `metac_lexer_close` when it is no longer needed.
 */
MetaCLexer *metac_lexer_open(const char *);

/*
 * Close the lexer and release any resources allocated in `metac_lexer_open`
 * and during the lexing process. Do not use the MetaCLexer pointer after
 * calling this function on it.
 */
void metac_lexer_close(MetaCLexer *);

/*
 * Reset the lexer to its initial state. Call this function to start over at
 * the first token in the file. This function can be called anytime after
 * `metac_lexer_open` and before `metac_lexer_close`. It is called
 * implicitely when a lexer is opened.
 */
void metac_lexer_reset(MetaCLexer *);

/*
 * Get the next `MetaCToken` from the file that the lexer is reading. This
 * function can be called anytime after `metac_lexer_open` and before
 * `metac_lexer_close`. Calling `metac_lexer_reset` causes this function
 * to return tokens starting from the beginning of the file again.
 */
const MetaCToken *metac_lexer_next_token(MetaCLexer *);

/*
 * Used internally by the scanner to update the address/position of the
 * current token. This really shouldn't be called outside of the scanning
 * function otherwise it will mess up the state of the current token.
 */
void metac_lexer_increment(MetaCLexer *lexer);

#endif /* METAC_LEXER_H_ */
