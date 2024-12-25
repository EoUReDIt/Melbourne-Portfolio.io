// CMSC 330 Advanced Programming Languages
// Project 2
// UMGC CITE
// fall 2024
//Melbourne Anderson

#ifndef QUATERNARY_H
#define QUATERNARY_H

#include "subexpression.h"
#include "symboltable.h"
#include "variable.h"
#include <string>

extern SymbolTable symbolTable; // Access the global symbol table

class Quaternary : public SubExpression {
public:
    Quaternary(Expression* condition, Expression* second, Expression* third, Expression* fourth);
    double evaluate() override;

private:
    Expression* second;
    Expression* third;
    Expression* fourth;
};

#endif