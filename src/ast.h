#ifndef METAC_NODES_H
#define METAC_NODES_H 1

#include <iostream>
#include <vector>
#include <string>

namespace metac
{

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