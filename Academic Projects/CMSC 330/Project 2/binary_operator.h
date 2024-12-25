//
// Created by Michael on 10/8/2024.
//

#ifndef BINARY_OPERATOR_H
#define BINARY_OPERATOR_H

#include "subexpression.h"

// The BinaryOperator class inherits from SubExpression and is used as a base class for all binary operations
class BinaryOperator : public SubExpression {
public:
    // Constructor initializes the left and right expressions
    BinaryOperator(Expression* left, Expression* right) : SubExpression(left, right) {}

    // The evaluate method is pure virtual, forcing derived classes to implement their own behavior
    double evaluate() override = 0;
};

#endif
