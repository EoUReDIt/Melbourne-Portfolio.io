// CMSC 330 Advanced Programming Languages
// Project 2
// UMGC CITE
// fall 2024
//Melbourne Anderson

#ifndef REMAINDER_H
#define REMAINDER_H

#include "binary_operator.h"
#include <cmath>

class Remainder : public SubExpression {
public:
    Remainder(Expression* left, Expression* right) : SubExpression(left, right) {}
    double evaluate() override {
        double leftValue = left->evaluate();
        double rightValue = right->evaluate();
        if (rightValue == 0) {
            throw std::string("Division by zero error");
        }
        return std::fmod(leftValue, rightValue);
    }
};

#endif

//added as a reminder that this file did not exist in the skeleton
//std::fmod performs the floating-point remainder operation, so it works correctly with floating-point inputs without truncation.