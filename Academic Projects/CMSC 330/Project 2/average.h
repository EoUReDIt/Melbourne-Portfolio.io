// CMSC 330 Advanced Programming Languages
// Project 2
// UMGC CITE
// fall 2024
//Melbourne Anderson

#ifndef AVERAGE_H
#define AVERAGE_H

#include "subexpression.h"

class Average : public SubExpression {
public:
    Average(Expression* left, Expression* right) : SubExpression(left, right) {}
    double evaluate() override {
        return (left->evaluate() + right->evaluate()) / 2;
    }
};

#endif
//added as a reminder that this file did not exist in the skeleton