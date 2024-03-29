#ifndef _ABSTRACTSYNTAXTREE_H
#define _ABSTRACTSYNTAXTREE_H

#include <vector>
#include "llvm/IR/Value.h"

class GeneratorContext;
class Node
{
    public:
        virtual ~Node() {}
        virtual llvm::Value* generator(GeneratorContext& context) {
            return nullptr;
        }
};


class Expression : public Node {};
class Statement : public Node {};

class ExpressionStatement : public Statement
{
    public:
        Expression& expression;
        ExpressionStatement(Expression& expression) :
            expression(expression) {}
        virtual llvm::Value* generator(GeneratorContext& context);
};

class ReturnStatement : public Statement
{
    public:
        Expression& expression;
        ReturnStatement(Expression& expression) :
            expression(expression) {}

        virtual llvm::Value* generator(GeneratorContext& context);
};

class BlankReturnStatement : public Statement
{
    public:
        BlankReturnStatement() {}
        virtual llvm::Value* generator(GeneratorContext& context);
};

/*
class Range : public Statement
{
    Expression* left;
    Expression* right;

    bool inclusive;
    int step;

    public:
        Range(Expression* left, Expression* right, bool inclusive, int step)
            : left(left), right(right), inclusive(inclusive), step(step) {}

        virtual llvm::Value* generator(GeneratorContext& context);
};*/


class Identifier : public Expression
{
    public:
        std::string named;
        Identifier(const std::string& named) : named(named) {}
        virtual llvm::Value* generator(GeneratorContext& context);
};


class Integer : public Expression
{
    public:
        long long value;
        Integer(long long value) : value(value) {}
        virtual llvm::Value* generator(GeneratorContext& context);
};


class Boolean : public Expression
{
    public:
        bool value;
        Boolean(bool value) : value(value) {}
        virtual llvm::Value* generator(GeneratorContext& context);
};


class String : public Expression
{
    public:
        std::string value;
        String(std::string value) : value(value) {}
        virtual llvm::Value* generator(GeneratorContext& context);
};


class MethodCall : public Expression
{
    public:
        const Identifier& identifier;
        std::vector<Expression*> arguments;
        MethodCall(const Identifier& identifier) : identifier(identifier) {}
        MethodCall(const Identifier& identifier, std::vector<Expression*>& arguments) :
            identifier(identifier), arguments(arguments) {}
        virtual llvm::Value* generator(GeneratorContext& context);
};


class Block : public Expression
{
    public:
        std::vector<Statement*> statements;
        Block() {}
        virtual ~Block() 
        {
            for (auto it : statements) {
                delete it;
            }

            statements.clear();
        }

        virtual llvm::Value* generator(GeneratorContext& context);
};


class Comparison : public Expression
{
    public:
        Expression* left;
        Expression* right;
        int comparison_operator;

        Comparison(Expression* left, Expression* right, int comparison_operator)
            : left(left), right(right), comparison_operator(comparison_operator) {}

        virtual llvm::Value* generator(GeneratorContext& context);
};


class Binary : public Expression
{
    public:
        Expression* left;
        Expression* right;
        int binary_operator;

        Binary(Expression* left, Expression* right, int binary_operator)
            : left(left), right(right), binary_operator(binary_operator) {}

        virtual llvm::Value* generator(GeneratorContext& context);
};


class Conditional : public Statement
{
    public:
        Comparison* comparison;
        Block* then_block;
        Block* else_block;

        Conditional(Expression* comparison, Block* then_block, Block* else_block = nullptr)
            : comparison((Comparison*) comparison), then_block(then_block), else_block(else_block) {}

        virtual llvm::Value* generator(GeneratorContext& context);
};


class VariableDeclaration : public Statement
{
    public:
        Identifier& identifier;
        const Identifier& type;
        Expression* expression;
        const bool is_mutable;

        VariableDeclaration(Identifier& identifier, const Identifier& type, Expression* expression, const bool is_mutable = true) :
            identifier(identifier), type(type), expression(expression), is_mutable(is_mutable) {}

        VariableDeclaration(Identifier& identifier, const Identifier& type, const bool is_mutable = true) :
            identifier(identifier), type(type), is_mutable(is_mutable) {
            expression = nullptr;
        }

        virtual llvm::Value* generator(GeneratorContext& context);
};


class MethodDeclaration : public Statement
{
    public:
        const Identifier& identifier;
        std::vector<VariableDeclaration*> arguments;
        const Identifier& type;
        Block& method_block;

        MethodDeclaration(
            const Identifier& identifier,
            const std::vector<VariableDeclaration*> arguments,
            const Identifier& type,
            Block& block
        ) : identifier(identifier), arguments(arguments), type(type), method_block(block) {}

        MethodDeclaration(
            const Identifier& identifier,
            const std::vector<VariableDeclaration*> arguments,
            Block& block
        ) : identifier(identifier), arguments(arguments), type(*(new Identifier("void"))), method_block(block) {
            // Methods created without type identifier are set to void by default.
        }

        virtual llvm::Value* generator(GeneratorContext& context);
};


class Assignment : public Expression
{
    public:
        Identifier& left;
        Expression& right;
        Assignment(Identifier& left, Expression& right) :
            left(left), right(right) {}
        virtual llvm::Value* generator(GeneratorContext& context);
};


class For : public Statement
{
    Identifier& var;
    Expression* start;
    Expression* end;
    Expression* step;
    bool inclusive;
    Block* inner_block;


public:
    For(Identifier& var, Expression* start, Expression* end, Expression* step, bool inclusive, Block* inner_block)
        : var(var), start(start), end(end), step(step), inclusive(inclusive), inner_block(inner_block) {}
    virtual llvm::Value* generator(GeneratorContext& context);
};

#endif // !_ABSTRACTSYNTAXTREE_H
