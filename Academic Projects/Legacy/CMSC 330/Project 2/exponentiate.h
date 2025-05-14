// CMSC 330 Advanced Programming Languages
// Project 2
// UMGC CITE
// fall 2024
//Melbourne Anderson

#ifndef EXPONENTIATE_H
#define EXPONENTIATE_H

#include "binary_operator.h"
#include <cmath>

class Exponentiate : public BinaryOperator {
public:
    Exponentiate(Expression* left, Expression* right) : BinaryOperator(left, right) {}
    double evaluate() override {
        return pow(left->evaluate(), right->evaluate());
    }
};

#endif
//added as a reminder that this file did not exist in the skeleton