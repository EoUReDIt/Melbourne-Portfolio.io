// CMSC 330 Advanced Programming Languages
// Project 2
// UMGC CITE
// fall 2024
//Melbourne Anderson

#ifndef MAXIMUM_H
#define MAXIMUM_H

#include "binary_operator.h"

class Maximum : public SubExpression {
public:
    Maximum(Expression* left, Expression* right) : SubExpression(left, right) {}
    double evaluate() override {
        return std::max(left->evaluate(), right->evaluate());
    }
};

#endif
//added as a reminder that this file did not exist in the skeleton