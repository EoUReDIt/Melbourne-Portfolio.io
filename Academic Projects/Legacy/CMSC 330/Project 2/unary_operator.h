// CMSC 330 Advanced Programming Languages
// Project 2
// UMGC CITE
// fall 2024
//Melbourne Anderson

#ifndef UNARY_OPERATOR_H
#define UNARY_OPERATOR_H

#include "subexpression.h"

// The UnaryOperator class inherits from SubExpression and is used as a base class for all unary operations
class UnaryOperator : public SubExpression {
public:
    // Constructor initializes the single operand (left)
    UnaryOperator(Expression* operand) : SubExpression(operand, nullptr) {}

    // The evaluate method is pure virtual, forcing derived classes to implement their own behavior
    virtual double evaluate() override = 0;
};

#endif
