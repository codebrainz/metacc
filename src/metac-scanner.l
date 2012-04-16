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

D     [0-9]
L     [a-zA-Z_]
H     [a-fA-F0-9]
B     [01]
E     ([Ee][+-]?{D}+)
P     ([Pp][+-]?{D}+)
FS    (f|F|l|L)
IS    ((u|U)|(u|U)?(l|L|ll|LL)|(l|L|ll|LL)(u|U))

%option noyywrap
%option yylineno
%option reentrant
%option nounput
%option bison-bridge
%option bison-locations
%option prefix="metac_"

%{

#include "parser.h"

#define YY_EXTRA_TYPE MetaCParser*
#define YY_USER_ACTION yylloc->first_line = yylineno;

static void comment(yyscan_t yyscanner);
static long hex_to_long(const char *);

#define MCINC {}
%}

%%

"//"[^\n]* { MCINC; /* consume C++-style comments */ }
"/*"       { MCINC; comment(yyscanner); }

"bool"     { MCINC; return MCTOK_BOOL; }
"break"    { MCINC; return MCTOK_BREAK; }
"case"     { MCINC; return MCTOK_CASE; }
"catch"    { MCINC; return MCTOK_CATCH; }
"char"     { MCINC; return MCTOK_CHAR; }
"class"    { MCINC; return MCTOK_CLASS; }
"const"    { MCINC; return MCTOK_CONST; }
"continue" { MCINC; return MCTOK_CONTINUE; }
"default"  { MCINC; return MCTOK_DEFAULT; }
"delete"   { MCINC; return MCTOK_DELETE; }
"do"       { MCINC; return MCTOK_DO; }
"double"   { MCINC; return MCTOK_DOUBLE; }
"else"     { MCINC; return MCTOK_ELSE; }
"enum"     { MCINC; return MCTOK_ENUM; }
"extern"   { MCINC; return MCTOK_EXTERN; }
"false"    { MCINC; return MCTOK_FALSE; }
"finally"  { MCINC; return MCTOK_FINALLY; }
"float"    { MCINC; return MCTOK_FLOAT; }
"for"      { MCINC; return MCTOK_FOR; }
"foreach"  { MCINC; return MCTOK_FOREACH; }
"goto"     { MCINC; return MCTOK_GOTO; }
"if"       { MCINC; return MCTOK_IF; }
"inline"   { MCINC; return MCTOK_INLINE; }
"int"      { MCINC; return MCTOK_INT; }
"lambda"   { MCINC; return MCTOK_LAMBDA; }
"long"     { MCINC; return MCTOK_LONG; }
"new"      { MCINC; return MCTOK_NEW; }
"null"     { MCINC; return MCTOK_NULL; }
"return"   { MCINC; return MCTOK_RETURN; }
"private"  { MCINC; return MCTOK_PRIVATE; }
"public"   { MCINC; return MCTOK_PUBLIC; }
"short"    { MCINC; return MCTOK_SHORT; }
"sizeof"   { MCINC; return MCTOK_SIZEOF; }
"static"   { MCINC; return MCTOK_STATIC; }
"struct"   { MCINC; return MCTOK_STRUCT; }
"switch"   { MCINC; return MCTOK_SWITCH; }
"throw"    { MCINC; return MCTOK_THROW; }
"true"     { MCINC; return MCTOK_TRUE; }
"try"      { MCINC; return MCTOK_TRY; }
"typedef"  { MCINC; return MCTOK_TYPEDEF; }
"typeof"   { MCINC; return MCTOK_TYPEOF; }
"uchar"    { MCINC; return MCTOK_UCHAR; }
"uint"     { MCINC; return MCTOK_UINT; }
"ulong"    { MCINC; return MCTOK_ULONG; }
"ushort"   { MCINC; return MCTOK_USHORT; }
"union"    { MCINC; return MCTOK_UNION; }
"var"      { MCINC; return MCTOK_VAR; }
"void"     { MCINC; return MCTOK_VOID; }
"while"    { MCINC; return MCTOK_WHILE; }

{L}({L}|{D})* { MCINC;
                strncpy(yylval->mc_string, yytext, yyleng);
                return MCTOK_IDENTIFIER; }

0[xX]{H}+{IS}?             { MCINC; 
                             yylval->mc_long = hex_to_long(yytext);
                             return(MCTOK_CONSTANT); }
0[0-7]*{IS}?               { MCINC; return(MCTOK_CONSTANT); }
[1-9]{D}*{IS}?             { MCINC; return(MCTOK_CONSTANT); }
L?'(\\.|[^\\'\n])+'        { MCINC; return(MCTOK_CONSTANT); }

{D}+{E}{FS}?               { MCINC; return(MCTOK_CONSTANT); }
{D}*"."{D}+{E}?{FS}?       { MCINC; return(MCTOK_CONSTANT); }
{D}+"."{D}*{E}?{FS}?       { MCINC; return(MCTOK_CONSTANT); }
0[xX]{H}+{P}{FS}?          { MCINC; return(MCTOK_CONSTANT); }
0[xX]{H}*"."{H}+{P}?{FS}?  { MCINC; return(MCTOK_CONSTANT); }
0[xX]{H}+"."{H}*{P}?{FS}?  { MCINC; return(MCTOK_CONSTANT); }
0[bB]{B}+{P}{FS}?          { MCINC; return(MCTOK_CONSTANT); }
0[bB]{B}*"."{B}+{P}?{FS}?  { MCINC; return(MCTOK_CONSTANT); }
0[bB]{B}+"."{B}*{P}?{FS}?  { MCINC; return(MCTOK_CONSTANT); }

L?\"(\\.|[^\\"\n])*\" { MCINC; return(MCTOK_STRING_LITERAL); }

"..."      { MCINC; return MCTOK_ELLIPSIS; }
">>="      { MCINC; return MCTOK_RIGHT_ASSIGN; }
"<<="      { MCINC; return MCTOK_LEFT_ASSIGN; }
"+="       { MCINC; return MCTOK_ADD_ASSIGN; }
"-="       { MCINC; return MCTOK_SUB_ASSIGN; }
"*="       { MCINC; return MCTOK_MUL_ASSIGN; }
"/="       { MCINC; return MCTOK_DIV_ASSIGN; }
"%="       { MCINC; return MCTOK_MOD_ASSIGN; }
"&="       { MCINC; return MCTOK_AND_ASSIGN; }
"^="       { MCINC; return MCTOK_XOR_ASSIGN; }
"|="       { MCINC; return MCTOK_OR_ASSIGN; }
">>"       { MCINC; return MCTOK_RIGHT_OP; }
"<<"       { MCINC; return MCTOK_LEFT_OP; }
"++"       { MCINC; return MCTOK_INC_OP; }
"--"       { MCINC; return MCTOK_DEC_OP; }
"->"       { MCINC; return MCTOK_PTR_OP; }
"&&"       { MCINC; return MCTOK_AND_OP; }
"||"       { MCINC; return MCTOK_OR_OP; }
"<="       { MCINC; return MCTOK_LE_OP; }
">="       { MCINC; return MCTOK_GE_OP; }
"=="       { MCINC; return MCTOK_EQ_OP; }
"!="       { MCINC; return MCTOK_NE_OP; }
";"        { MCINC; return(';'); }
("{"|"<%") { MCINC; return('{'); }
("}"|"%>") { MCINC; return('}'); }
","        { MCINC; return(','); }
":"        { MCINC; return(':'); }
"="        { MCINC; return('='); }
"("        { MCINC; return('('); }
")"        { MCINC; return(')'); }
("["|"<:") { MCINC; return('['); }
("]"|":>") { MCINC; return(']'); }
"."        { MCINC; return('.'); }
"&"        { MCINC; return('&'); }
"!"        { MCINC; return('!'); }
"~"        { MCINC; return('~'); }
"-"        { MCINC; return('-'); }
"+"        { MCINC; return('+'); }
"*"        { MCINC; return('*'); }
"/"        { MCINC; return('/'); }
"%"        { MCINC; return('%'); }
"<"        { MCINC; return('<'); }
">"        { MCINC; return('>'); }
"^"        { MCINC; return('^'); }
"|"        { MCINC; return('|'); }
"?"        { MCINC; return('?'); }

[ \t\v\n\f]   { MCINC; }
.             { /* todo: add code to complain about unmatched characters */ }

%%

static long hex_to_long(const char *s)
{
  long l;
  errno = 0;
  l = strtol(s, NULL, 16);
  if (errno == 0) {
    return l;
  }
  metac_error("failed to convert hex to long\n");
}

static void comment(yyscan_t yyscanner)
{
  int c, prev = 0;

  while ((c = input(yyscanner)) != 0) {

    if (prev == '*' && c == '/') {
      return;
    }

    prev = c;
  }
  metac_error("unterminated comment");
}
