// CMSC 330 Advanced Programming Languages
// Project 2
// UMGC CITE
// fall 2024
//Melbourne Anderson

#ifndef NEGATE_H
#define NEGATE_H

#include "unary_operator.h"

class Negate : public UnaryOperator {
public:
    Negate(Expression* operand) : UnaryOperator(operand) {}

    double evaluate() override {
        return -left->evaluate();
    }
};

#endif


//added as a reminder that this file did not exist in the skeleton