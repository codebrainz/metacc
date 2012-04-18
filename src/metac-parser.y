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

%pure-parser
%name-prefix="Parser_"
%locations
%defines
%error-verbose
%parse-param { Parser *context }
%lex-param { void* scanner }
%start translation_unit

%union
{
	char *strval;
	int token;
}

%token <strval> MCTOK_IDENTIFIER
%token <strval> MCTOK_CONSTANT
%token <strval> MCTOK_STRING_LITERAL
%token <token>  MCTOK_SIZEOF MCTOK_TYPEOF
%token <token>  MCTOK_PTR_OP MCTOK_INC_OP MCTOK_DEC_OP
%token <token>  MCTOK_LEFT_OP MCTOK_RIGHT_OP
%token <token>  MCTOK_LE_OP MCTOK_GE_OP MCTOK_EQ_OP MCTOK_NE_OP
%token <token>  MCTOK_AND_OP MCTOK_OR_OP
%token <token>  MCTOK_MUL_ASSIGN MCTOK_DIV_ASSIGN MCTOK_MOD_ASSIGN
%token <token>  MCTOK_ADD_ASSIGN MCTOK_SUB_ASSIGN
%token <token>  MCTOK_LEFT_ASSIGN MCTOK_RIGHT_ASSIGN
%token <token>  MCTOK_AND_ASSIGN MCTOK_XOR_ASSIGN MCTOK_OR_ASSIGN
%token <token>  MCTOK_TYPE_NAME
%token <token>  MCTOK_TYPEDEF MCTOK_EXTERN MCTOK_STATIC MCTOK_INLINE
%token <token>  MCTOK_LAMBDA MCTOK_VAR
%token <token>  MCTOK_PRIVATE MCTOK_PUBLIC
%token <token>  MCTOK_CHAR MCTOK_SHORT MCTOK_INT MCTOK_LONG
%token <token>  MCTOK_UCHAR MCTOK_USHORT MCTOK_UINT MCTOK_ULONG
%token <token>  MCTOK_BOOL MCTOK_FLOAT MCTOK_DOUBLE
%token <token>  MCTOK_CONST MCTOK_VOID
%token <token>  MCTOK_CATCH MCTOK_THROW MCTOK_TRY MCTOK_FINALLY
%token <token>  MCTOK_CLASS MCTOK_STRUCT MCTOK_UNION MCTOK_ENUM
%token <token>  MCTOK_ELLIPSIS
%token <token>  MCTOK_NULL MCTOK_TRUE MCTOK_FALSE
%token <token>  MCTOK_NEW MCTOK_DELETE
%token <token>  MCTOK_SWITCH MCTOK_CASE MCTOK_DEFAULT
%token <token>  MCTOK_IF MCTOK_ELSE 
%token <token>  MCTOK_WHILE MCTOK_DO MCTOK_FOR MCTOK_FOREACH
%token <token>  MCTOK_GOTO MCTOK_CONTINUE MCTOK_BREAK MCTOK_RETURN

%{

#include <iostream>
#include <sstream>
#include <string>
#include "parser.h"

int Parser_lex(YYSTYPE* lvalp, YYLTYPE* llocp, void* scanner);

void Parser_error(YYLTYPE* locp, Parser* context, const char* err)
{
	std::cout << "metac:" << locp->first_line << ": " << err << std::endl;
}

#define scanner context->scanner

%}

%%

primary_expression
	: MCTOK_IDENTIFIER
	| MCTOK_CONSTANT
	| MCTOK_STRING_LITERAL
	| '(' expression ')'
	;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' MCTOK_IDENTIFIER
	| postfix_expression MCTOK_PTR_OP MCTOK_IDENTIFIER
	| postfix_expression MCTOK_INC_OP
	| postfix_expression MCTOK_DEC_OP
	| '(' type_name ')' '{' initializer_list '}'
	| '(' type_name ')' '{' initializer_list ',' '}'
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression
	| MCTOK_INC_OP unary_expression
	| MCTOK_DEC_OP unary_expression
	| unary_operator cast_expression
	| MCTOK_SIZEOF unary_expression
	| MCTOK_SIZEOF '(' type_name ')'
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression MCTOK_LEFT_OP additive_expression
	| shift_expression MCTOK_RIGHT_OP additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression MCTOK_LE_OP shift_expression
	| relational_expression MCTOK_GE_OP shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression MCTOK_EQ_OP relational_expression
	| equality_expression MCTOK_NE_OP relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression MCTOK_AND_OP inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression MCTOK_OR_OP logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: '='
	| MCTOK_MUL_ASSIGN
	| MCTOK_DIV_ASSIGN
	| MCTOK_MOD_ASSIGN
	| MCTOK_ADD_ASSIGN
	| MCTOK_SUB_ASSIGN
	| MCTOK_LEFT_ASSIGN
	| MCTOK_RIGHT_ASSIGN
	| MCTOK_AND_ASSIGN
	| MCTOK_XOR_ASSIGN
	| MCTOK_OR_ASSIGN
	;

expression
	: assignment_expression
	| expression ',' assignment_expression
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';'
	;

declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier
	| type_specifier declaration_specifiers
	| type_qualifier
	| type_qualifier declaration_specifiers
	| function_specifier
	| function_specifier declaration_specifiers
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator
	| declarator '=' initializer
	;

storage_class_specifier
	: MCTOK_TYPEDEF
	| MCTOK_EXTERN
	| MCTOK_STATIC
	;

type_specifier
	: MCTOK_VOID
	| MCTOK_CHAR
	| MCTOK_UCHAR
	| MCTOK_SHORT
	| MCTOK_USHORT
	| MCTOK_INT
	| MCTOK_UINT
	| MCTOK_LONG
	| MCTOK_ULONG
	| MCTOK_FLOAT
	| MCTOK_DOUBLE
	| MCTOK_BOOL
	| struct_or_union_specifier
	| enum_specifier
	| MCTOK_TYPE_NAME
	;

struct_or_union_specifier
	: struct_or_union MCTOK_IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union MCTOK_IDENTIFIER
	;

struct_or_union
	: MCTOK_STRUCT
	| MCTOK_UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator
	| ':' constant_expression
	| declarator ':' constant_expression
	;

enum_specifier
	: MCTOK_ENUM '{' enumerator_list '}'
	| MCTOK_ENUM MCTOK_IDENTIFIER '{' enumerator_list '}'
	| MCTOK_ENUM '{' enumerator_list ',' '}'
	| MCTOK_ENUM MCTOK_IDENTIFIER '{' enumerator_list ',' '}'
	| MCTOK_ENUM MCTOK_IDENTIFIER
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator
	: MCTOK_IDENTIFIER
	| MCTOK_IDENTIFIER '=' constant_expression
	;

type_qualifier
	: MCTOK_CONST
	;

function_specifier
	: MCTOK_INLINE
	;

declarator
	: pointer direct_declarator
	| direct_declarator
	;


direct_declarator
	: MCTOK_IDENTIFIER
	| '(' declarator ')'
	| direct_declarator '[' type_qualifier_list assignment_expression ']'
	| direct_declarator '[' type_qualifier_list ']'
	| direct_declarator '[' assignment_expression ']'
	| direct_declarator '[' MCTOK_STATIC type_qualifier_list assignment_expression ']'
	| direct_declarator '[' type_qualifier_list MCTOK_STATIC assignment_expression ']'
	| direct_declarator '[' type_qualifier_list '*' ']'
	| direct_declarator '[' '*' ']'
	| direct_declarator '[' ']'
	| direct_declarator '(' parameter_type_list ')'
	| direct_declarator '(' identifier_list ')'
	| direct_declarator '(' ')'
	;

pointer
	: '*'
	| '*' type_qualifier_list
	| '*' pointer
	| '*' type_qualifier_list pointer
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list
	| parameter_list ',' MCTOK_ELLIPSIS
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: MCTOK_IDENTIFIER
	| identifier_list ',' MCTOK_IDENTIFIER
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' assignment_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' assignment_expression ']'
	| '[' '*' ']'
	| direct_abstract_declarator '[' '*' ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

initializer
	: assignment_expression
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;

initializer_list
	: initializer
	| designation initializer
	| initializer_list ',' initializer
	| initializer_list ',' designation initializer
	;

designation
	: designator_list '='
	;

designator_list
	: designator
	| designator_list designator
	;

designator
	: '[' constant_expression ']'
	| '.' MCTOK_IDENTIFIER
	;

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: MCTOK_IDENTIFIER ':' statement
	| MCTOK_CASE constant_expression ':' statement
	| MCTOK_DEFAULT ':' statement
	;

compound_statement
	: '{' '}'
	| '{' block_item_list '}'
	;

block_item_list
	: block_item
	| block_item_list block_item
	;

block_item
	: declaration
	| statement
	;

expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: MCTOK_IF '(' expression ')' statement
	| MCTOK_IF '(' expression ')' statement MCTOK_ELSE statement
	| MCTOK_SWITCH '(' expression ')' statement
	;

iteration_statement
	: MCTOK_WHILE '(' expression ')' statement
	| MCTOK_DO statement MCTOK_WHILE '(' expression ')' ';'
	| MCTOK_FOR '(' expression_statement expression_statement ')' statement
	| MCTOK_FOR '(' expression_statement expression_statement expression ')' statement
	| MCTOK_FOR '(' declaration expression_statement ')' statement
	| MCTOK_FOR '(' declaration expression_statement expression ')' statement
	;

jump_statement
	: MCTOK_GOTO MCTOK_IDENTIFIER ';'
	| MCTOK_CONTINUE ';'
	| MCTOK_BREAK ';'
	| MCTOK_RETURN ';'
	| MCTOK_RETURN expression ';'
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	;

declaration_list
	: declaration
	| declaration_list declaration
	;


%%
