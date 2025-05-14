// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the class definition of the Plus class, which is a subclass of SubExpression,
// which in turn is a subclass of the Expression.

#ifndef PLUS_H
#define PLUS_H

#include "binary_operator.h"

class Plus : public BinaryOperator {
public:
    Plus(Expression* left, Expression* right);
    double evaluate() override;
};

#endif
