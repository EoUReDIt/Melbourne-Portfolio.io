#ifndef DIVIDE_H
#define DIVIDE_H

#include "binary_operator.h"

class Divide : public BinaryOperator {
public:
    Divide(Expression* left, Expression* right) : BinaryOperator(left, right) {}
    double evaluate() override {
        double rightValue = right->evaluate();
        if (rightValue == 0) {
            throw std::string("Division by zero error");
        }
        return left->evaluate() / rightValue;
    }
};

#endif
//added as a reminder that this file did not exist in the skeleton