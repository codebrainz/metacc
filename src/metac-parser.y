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
%parse-param { metac::Parser *context }
%lex-param { void* scanner }
%start translation_unit

%{
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "parser.h"
#include "ast.h"
%}

%union
{
	metac::Node *node;
	metac::Block *block;
	metac::Expression *expr;
	metac::Statement *stmt;
	metac::Identifier *ident;
	metac::VariableDeclaration *var_decl;
	std::vector<metac::VariableDeclaration*> *varvec;
	std::vector<metac::Expression*> *exprvec;
	std::string *string;
	int token;
}

%token <string> TOK_IDENTIFIER
%token <string> TOK_CONSTANT
%token <string> TOK_STRING_LITERAL
%token <token>  TOK_SIZEOF TOK_TYPEOF
%token <token>  TOK_PTR_OP TOK_INC_OP TOK_DEC_OP
%token <token>  TOK_LEFT_OP TOK_RIGHT_OP
%token <token>  TOK_LE_OP TOK_GE_OP TOK_EQ_OP TOK_NE_OP
%token <token>  TOK_AND_OP TOK_OR_OP
%token <token>  TOK_MUL_ASSIGN TOK_DIV_ASSIGN TOK_MOD_ASSIGN
%token <token>  TOK_ADD_ASSIGN TOK_SUB_ASSIGN
%token <token>  TOK_LEFT_ASSIGN TOK_RIGHT_ASSIGN
%token <token>  TOK_AND_ASSIGN TOK_XOR_ASSIGN TOK_OR_ASSIGN
%token <string> TOK_TYPE_NAME
%token <token>  TOK_TYPEDEF TOK_EXTERN TOK_STATIC TOK_INLINE
%token <token>  TOK_LAMBDA TOK_VAR
%token <token>  TOK_PRIVATE TOK_PUBLIC
%token <token>  TOK_CHAR TOK_SHORT TOK_INT TOK_LONG
%token <token>  TOK_UCHAR TOK_USHORT TOK_UINT TOK_ULONG
%token <token>  TOK_BOOL TOK_FLOAT TOK_DOUBLE
%token <token>  TOK_CONST TOK_VOID
%token <token>  TOK_CATCH TOK_THROW TOK_TRY TOK_FINALLY
%token <token>  TOK_CLASS TOK_STRUCT TOK_UNION TOK_ENUM
%token <token>  TOK_ELLIPSIS
%token <token>  TOK_NULL TOK_TRUE TOK_FALSE
%token <token>  TOK_NEW TOK_DELETE
%token <token>  TOK_SWITCH TOK_CASE TOK_DEFAULT
%token <token>  TOK_IF TOK_ELSE 
%token <token>  TOK_WHILE TOK_DO TOK_FOR TOK_FOREACH
%token <token>  TOK_GOTO TOK_CONTINUE TOK_BREAK TOK_RETURN

%{

int Parser_lex(YYSTYPE* lvalp, YYLTYPE* llocp, void* scanner);

void Parser_error(YYLTYPE* locp, metac::Parser* context, const char* err)
{
	std::cout << "metac:" << locp->first_line << ": " << err << std::endl;
}

#define scanner context->scanner

%}

%%

primary_expression
	: TOK_IDENTIFIER
	| TOK_CONSTANT
	| TOK_STRING_LITERAL
	| '(' expression ')'
	;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' TOK_IDENTIFIER
	| postfix_expression TOK_PTR_OP TOK_IDENTIFIER
	| postfix_expression TOK_INC_OP
	| postfix_expression TOK_DEC_OP
	| '(' type_name ')' '{' initializer_list '}'
	| '(' type_name ')' '{' initializer_list ',' '}'
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression
	| TOK_INC_OP unary_expression
	| TOK_DEC_OP unary_expression
	| unary_operator cast_expression
	| TOK_SIZEOF unary_expression
	| TOK_SIZEOF '(' type_name ')'
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
	| shift_expression TOK_LEFT_OP additive_expression
	| shift_expression TOK_RIGHT_OP additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression TOK_LE_OP shift_expression
	| relational_expression TOK_GE_OP shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression TOK_EQ_OP relational_expression
	| equality_expression TOK_NE_OP relational_expression
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
	| logical_and_expression TOK_AND_OP inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression TOK_OR_OP logical_and_expression
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
	| TOK_MUL_ASSIGN
	| TOK_DIV_ASSIGN
	| TOK_MOD_ASSIGN
	| TOK_ADD_ASSIGN
	| TOK_SUB_ASSIGN
	| TOK_LEFT_ASSIGN
	| TOK_RIGHT_ASSIGN
	| TOK_AND_ASSIGN
	| TOK_XOR_ASSIGN
	| TOK_OR_ASSIGN
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
	: TOK_TYPEDEF
	| TOK_EXTERN
	| TOK_STATIC
	;

type_specifier
	: TOK_VOID
	| TOK_CHAR
	| TOK_UCHAR
	| TOK_SHORT
	| TOK_USHORT
	| TOK_INT
	| TOK_UINT
	| TOK_LONG
	| TOK_ULONG
	| TOK_FLOAT
	| TOK_DOUBLE
	| TOK_BOOL
	| struct_or_union_specifier
	| enum_specifier
	| TOK_TYPE_NAME
	;

struct_or_union_specifier
	: struct_or_union TOK_IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union TOK_IDENTIFIER
	;

struct_or_union
	: TOK_STRUCT
	| TOK_UNION
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
	: TOK_ENUM '{' enumerator_list '}'
	| TOK_ENUM TOK_IDENTIFIER '{' enumerator_list '}'
	| TOK_ENUM '{' enumerator_list ',' '}'
	| TOK_ENUM TOK_IDENTIFIER '{' enumerator_list ',' '}'
	| TOK_ENUM TOK_IDENTIFIER
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator
	: TOK_IDENTIFIER
	| TOK_IDENTIFIER '=' constant_expression
	;

type_qualifier
	: TOK_CONST
	;

function_specifier
	: TOK_INLINE
	;

declarator
	: pointer direct_declarator
	| direct_declarator
	;


direct_declarator
	: TOK_IDENTIFIER
	| '(' declarator ')'
	| direct_declarator '[' type_qualifier_list assignment_expression ']'
	| direct_declarator '[' type_qualifier_list ']'
	| direct_declarator '[' assignment_expression ']'
	| direct_declarator '[' TOK_STATIC type_qualifier_list assignment_expression ']'
	| direct_declarator '[' type_qualifier_list TOK_STATIC assignment_expression ']'
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
	| parameter_list ',' TOK_ELLIPSIS
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
	: TOK_IDENTIFIER
	| identifier_list ',' TOK_IDENTIFIER
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
	| '.' TOK_IDENTIFIER
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
	: TOK_IDENTIFIER ':' statement
	| TOK_CASE constant_expression ':' statement
	| TOK_DEFAULT ':' statement
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
	: TOK_IF '(' expression ')' statement
	| TOK_IF '(' expression ')' statement TOK_ELSE statement
	| TOK_SWITCH '(' expression ')' statement
	;

iteration_statement
	: TOK_WHILE '(' expression ')' statement
	| TOK_DO statement TOK_WHILE '(' expression ')' ';'
	| TOK_FOR '(' expression_statement expression_statement ')' statement
	| TOK_FOR '(' expression_statement expression_statement expression ')' statement
	| TOK_FOR '(' declaration expression_statement ')' statement
	| TOK_FOR '(' declaration expression_statement expression ')' statement
	;

jump_statement
	: TOK_GOTO TOK_IDENTIFIER ';'
	| TOK_CONTINUE ';'
	| TOK_BREAK ';'
	| TOK_RETURN ';'
	| TOK_RETURN expression ';'
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
