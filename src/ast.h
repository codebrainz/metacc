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

#ifndef METAC_NODES_H
#define METAC_NODES_H 1

#include <iostream>
#include <vector>
#include <string>

namespace metac {

class CodeGenContext;
class Statement;
class Expression;
class VariableDeclaration;

typedef std::vector<Statement*> StatementList;
typedef std::vector<Expression*> ExpressionList;
typedef std::vector<VariableDeclaration*> VariableList;

class Node {
public:
	virtual ~Node() {}
	virtual std::string codeGen(CodeGenContext& context) {}
};

class Expression : public Node {
};

class Statement : public Node {
};

class Integer : public Expression {
public:
	long long value;
	Integer(long long value) : value(value) {}
	virtual std::string codeGen(CodeGenContext& context);
};

class Double : public Expression {
public:
	double value;
	Double(double value) : value(value) {}
	virtual std::string codeGen(CodeGenContext& context);
};

class Identifier : public Expression {
public:
	std::string name;
	Identifier(const std::string name) : name(name) {}
	virtual std::string codeGen(CodeGenContext& context);
};

class MethodCall : public Expression {
public:
	const Identifier& id;
	ExpressionList arguments;
	MethodCall(const Identifier&  id, ExpressionList& arguments) :
		id(id), arguments(arguments) {}
	MethodCall(const Identifier id) : id(id) {}
	virtual std::string codeGen(CodeGenContext& context);
};

class BinaryOperator : public Expression {
public:
	int op;
	Expression lhs;
	Expression rhs;
	BinaryOperator(Expression& lhs, int op, Expression& rhs) : 
		lhs(lhs), rhs(rhs), op(op) {}
	virtual std::string codeGen(CodeGenContext& context);
};

class Assignment : public Expression {
public:
	Identifier lhs;
	Expression rhs;
	Assignment(Identifier& lhs, Expression& rhs) :
		lhs(lhs), rhs(rhs) {}
	virtual std::string codeGen(CodeGenContext& context);
};

class Block : public Expression {
public:
	StatementList statements;
	Block() {}
	virtual std::string codeGen(CodeGenContext& context);
};

class ExpressionStatement : public Statement {
public:
	Expression& expression;
	ExpressionStatement(Expression& expression) :
		expression(expression) {}
	virtual std::string codeGen(CodeGenContext& context);
};

class VariableDeclaration : public Statement {
public:
	const Identifier& type;
	Identifier& id;
	Expression *assignmentExpr;
	VariableDeclaration(const Identifier& type, Identifier& id) :
		type(type), id(id) {}
	VariableDeclaration(const Identifier& type, Identifier& id, Expression *assignmentExpr) :
		type(type), id(id), assignmentExpr(assignmentExpr) {}
	virtual std::string codeGen(CodeGenContext& context);
};

class FunctionDeclaration : public Statement {
public:
	const Identifier& type;
	const Identifier& id;
	VariableList arguments;
	Block& block;
	FunctionDeclaration(const Identifier& type, const Identifier& id,
				const VariableList& arguments, Block& block) :
		type(type), id(id), arguments(arguments), block(block) {}
	virtual std::string codeGen(CodeGenContext& context);
};

} /* namespace metac */

#endif /* METAC_NODES_H */