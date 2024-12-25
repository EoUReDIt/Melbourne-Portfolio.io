// CMSC 330 Advanced Programming Languages
// Project 2
// UMGC CITE
// fall 2024
//Melbourne Anderson

#ifndef TERNARY_H
#define TERNARY_H

#include "subexpression.h"
#include "symboltable.h"
#include "variable.h"
#include <string>

extern SymbolTable symbolTable; // Access the global symbol table

class Ternary : public SubExpression {
public:
    Ternary(Expression* condition, Expression* trueExpr, Expression* falseExpr);
    double evaluate() override;

private:
    Expression* falseExpr; // The third operand for the ternary expression (evaluated if the condition is false)
};

#endif
