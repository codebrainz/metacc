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

#include <stdio.h>
#include "lexer.h"
#include "token.h"
#include "scanner.h"

struct _metac_lexer_private_t {
  FILE *fp;
  size_t fileSize;
  yyscan_t scanner;
};

static size_t _metac_file_get_size(FILE *fp)
{
  size_t size = 0;

  if (fp) {
    size_t oldOffset;
    oldOffset = ftell(fp);
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, oldOffset, SEEK_SET);
  }

  return size;
}

MetaCLexer *metac_lexer_open(const char *fileName)
{
  FILE *fp;
  MetaCLexer *lexer = NULL;

  fp = fopen(fileName, "r");
  if (fp) {
    lexer = malloc(sizeof(MetaCLexer));
    lexer->priv = malloc(sizeof(MetaCLexerPrivate));
    lexer->priv->fp = fp;
    strncpy(lexer->fileName, fileName, PATH_MAX);
    lexer->priv->fileSize = _metac_file_get_size(lexer->priv->fp);
    metac_scanner_lex_init_extra(lexer, &(lexer->priv->scanner));
    metac_scanner_set_in(lexer->priv->fp, lexer->priv->scanner);
  }

  return lexer;
}

void metac_lexer_close(MetaCLexer *lexer)
{
  if (lexer) {
    if (lexer->priv->fp) {
      fclose(lexer->priv->fp);
    }
    metac_scanner_lex_destroy(lexer->priv->scanner);
    free(lexer->priv);
    free(lexer);
  }
}

void metac_lexer_reset(MetaCLexer *lexer)
{
  if (lexer) {
    if (lexer->priv->fp) {
      fseek(lexer->priv->fp, 0, SEEK_SET);
    } else if (lexer->fileName[0]) {
      lexer->priv->fp = fopen(lexer->fileName, "r");
      lexer->priv->fileSize = _metac_file_get_size(lexer->priv->fp);
    }
    metac_token_reset(&(lexer->tok));
  }
}

const MetaCToken *metac_lexer_next_token(MetaCLexer *lexer)
{
  if (lexer) {
    int t;

    t = metac_scanner_lex(lexer->priv->scanner);
    if (t > 0) {
      size_t len;
      lexer->tok.type = (MetaCTokenType) t;
      len = metac_scanner_get_leng(lexer->priv->scanner);
      strncpy(lexer->tok.text, metac_scanner_get_text(lexer->priv->scanner), len);
      lexer->tok.text[len] = '\0';
      return (const MetaCToken *) &(lexer->tok);
    }
  }

  return NULL;
}

