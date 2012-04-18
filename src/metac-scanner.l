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
%option prefix="Parser_"

%{

#include <string>
#include "parser.h"
#include "ast.h"
#include "gen-parser.hh"

#define YY_EXTRA_TYPE Parser*
#define YY_USER_ACTION yylloc->first_line = yylineno;

#define YY_INPUT(buf, result, max_size) \
{ \
  if (yyextra->inStream->eof()) { \
    result = YY_NULL; \
  } else { \
    yyextra->inStream->get(buf, max_size, '\0'); \
    result = yyextra->inStream->gcount(); \
  } \
}

static void comment(yyscan_t yyscanner);

#define MCSETSTR yylval->string = new std::string(yytext)

%}

%%

"//"[^\n]* { /* consume C++-style comments */ }
"/*"       { comment(yyscanner); }
^"#"[^\n]+ { /* consume directives */ }

"bool"     { return TOK_BOOL; }
"break"    { return TOK_BREAK; }
"case"     { return TOK_CASE; }
"catch"    { return TOK_CATCH; }
"char"     { return TOK_CHAR; }
"class"    { return TOK_CLASS; }
"const"    { return TOK_CONST; }
"continue" { return TOK_CONTINUE; }
"default"  { return TOK_DEFAULT; }
"delete"   { return TOK_DELETE; }
"do"       { return TOK_DO; }
"double"   { return TOK_DOUBLE; }
"else"     { return TOK_ELSE; }
"enum"     { return TOK_ENUM; }
"extern"   { return TOK_EXTERN; }
"false"    { return TOK_FALSE; }
"finally"  { return TOK_FINALLY; }
"float"    { return TOK_FLOAT; }
"for"      { return TOK_FOR; }
"foreach"  { return TOK_FOREACH; }
"goto"     { return TOK_GOTO; }
"if"       { return TOK_IF; }
"inline"   { return TOK_INLINE; }
"int"      { return TOK_INT; }
"lambda"   { return TOK_LAMBDA; }
"long"     { return TOK_LONG; }
"new"      { return TOK_NEW; }
"null"     { return TOK_NULL; }
"return"   { return TOK_RETURN; }
"private"  { return TOK_PRIVATE; }
"public"   { return TOK_PUBLIC; }
"short"    { return TOK_SHORT; }
"sizeof"   { return TOK_SIZEOF; }
"static"   { return TOK_STATIC; }
"struct"   { return TOK_STRUCT; }
"switch"   { return TOK_SWITCH; }
"throw"    { return TOK_THROW; }
"true"     { return TOK_TRUE; }
"try"      { return TOK_TRY; }
"typedef"  { return TOK_TYPEDEF; }
"typeof"   { return TOK_TYPEOF; }
"uchar"    { return TOK_UCHAR; }
"uint"     { return TOK_UINT; }
"ulong"    { return TOK_ULONG; }
"ushort"   { return TOK_USHORT; }
"union"    { return TOK_UNION; }
"var"      { return TOK_VAR; }
"void"     { return TOK_VOID; }
"while"    { return TOK_WHILE; }

{L}({L}|{D})* { MCSETSTR; return TOK_IDENTIFIER; }

0[xX]{H}+{IS}?             { MCSETSTR; return(TOK_CONSTANT); }
0[0-7]*{IS}?               { MCSETSTR; return(TOK_CONSTANT); }
[1-9]{D}*{IS}?             { MCSETSTR; return(TOK_CONSTANT); }
L?'(\\.|[^\\'\n])+'        { MCSETSTR; return(TOK_CONSTANT); }

{D}+{E}{FS}?               { MCSETSTR; return(TOK_CONSTANT); }
{D}*"."{D}+{E}?{FS}?       { MCSETSTR; return(TOK_CONSTANT); }
{D}+"."{D}*{E}?{FS}?       { MCSETSTR; return(TOK_CONSTANT); }
0[xX]{H}+{P}{FS}?          { MCSETSTR; return(TOK_CONSTANT); }
0[xX]{H}*"."{H}+{P}?{FS}?  { MCSETSTR; return(TOK_CONSTANT); }
0[xX]{H}+"."{H}*{P}?{FS}?  { MCSETSTR; return(TOK_CONSTANT); }
0[bB]{B}+{P}{FS}?          { MCSETSTR; return(TOK_CONSTANT); }
0[bB]{B}*"."{B}+{P}?{FS}?  { MCSETSTR; return(TOK_CONSTANT); }
0[bB]{B}+"."{B}*{P}?{FS}?  { MCSETSTR; return(TOK_CONSTANT); }

L?\"(\\.|[^\\"\n])*\" { MCSETSTR; return(TOK_STRING_LITERAL); }

"..."      { return TOK_ELLIPSIS; }
">>="      { return TOK_RIGHT_ASSIGN; }
"<<="      { return TOK_LEFT_ASSIGN; }
"+="       { return TOK_ADD_ASSIGN; }
"-="       { return TOK_SUB_ASSIGN; }
"*="       { return TOK_MUL_ASSIGN; }
"/="       { return TOK_DIV_ASSIGN; }
"%="       { return TOK_MOD_ASSIGN; }
"&="       { return TOK_AND_ASSIGN; }
"^="       { return TOK_XOR_ASSIGN; }
"|="       { return TOK_OR_ASSIGN; }
">>"       { return TOK_RIGHT_OP; }
"<<"       { return TOK_LEFT_OP; }
"++"       { return TOK_INC_OP; }
"--"       { return TOK_DEC_OP; }
"->"       { return TOK_PTR_OP; }
"&&"       { return TOK_AND_OP; }
"||"       { return TOK_OR_OP; }
"<="       { return TOK_LE_OP; }
">="       { return TOK_GE_OP; }
"=="       { return TOK_EQ_OP; }
"!="       { return TOK_NE_OP; }
";"        { return(';'); }
("{"|"<%") { return('{'); }
("}"|"%>") { return('}'); }
","        { return(','); }
":"        { return(':'); }
"="        { return('='); }
"("        { return('('); }
")"        { return(')'); }
("["|"<:") { return('['); }
("]"|":>") { return(']'); }
"."        { return('.'); }
"&"        { return('&'); }
"!"        { return('!'); }
"~"        { return('~'); }
"-"        { return('-'); }
"+"        { return('+'); }
"*"        { return('*'); }
"/"        { return('/'); }
"%"        { return('%'); }
"<"        { return('<'); }
">"        { return('>'); }
"^"        { return('^'); }
"|"        { return('|'); }
"?"        { return('?'); }

[ \t\v\n\f]   { }
.             { /* todo: add code to complain about unmatched characters */ }

%%

static void comment(yyscan_t yyscanner)
{
  char c, prev = 0;

  while ((c = yyinput(yyscanner)) != 0) {
    if (prev == '*' && c == '/') {
      return;
    }

    prev = c;
  }
  /* fixme: Parser_error("unterminated comment"); */
}

void Parser::init_scanner()
{
  yylex_init_extra(this, &scanner);
}

void Parser::destroy_scanner()
{
  yylex_destroy(scanner);
}