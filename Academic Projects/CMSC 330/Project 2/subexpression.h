// CMSC 330 Advanced Programming Languages
// Project 2
// UMGC CITE
// fall 2024
//Melbourne Anderson


// This file contains the class definition of the SubExpression class, which is a subclass of Expression.
// Because it does not implement the abstract function evalauate, it is an abstract class. SubExpression
// objects are represented with the left and right subexpressions. The body of its constructor and the
// static (class) function parse are defined in subexpression.cpp. 

#ifndef SUBEXPRESSION_H
#define SUBEXPRESSION_H

#include "expression.h"
#include <sstream>

class SubExpression : public Expression {
public:
    SubExpression(Expression* left, Expression* right);
    static Expression* parse(std::stringstream& in);
protected:
    Expression* left;
    Expression* right;
};

#endif

//added as a reminder that this file has been updated from the original