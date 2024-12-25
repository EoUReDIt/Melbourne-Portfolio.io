// CMSC 330 Advanced Programming Languages
// Project 2
// UMGC CITE
// fall 2024
//Melbourne Anderson

#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "binary_operator.h"

class Multiply : public BinaryOperator {
public:
    Multiply(Expression* left, Expression* right) : BinaryOperator(left, right) {}
    double evaluate() override {
        return left->evaluate() * right->evaluate();
    }
};

#endif
//added as a reminder that this file did not exist in the skeleton