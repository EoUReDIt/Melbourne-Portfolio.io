// CMSC 330 Advanced Programming Languages
// Project 2
// UMGC CITE
// fall 2024
//Melbourne Anderson


// This file contains the class definition of the Minus class, which is a subclass of SubExpression,
// which in turn is a subclass of the Expression. Because both of its functions are one line functions, 
// they are implemented as inline functions. Its constructor initializes the left and right subexpressions
// it inherits from SubExpression by calling the constructor of the SubExpression class. Because
// it is an indirect subclass of Expression it must implement the evaluate function, which it does
// by returning the difference of the values of the two subexpressions.

#include "binary_operator.h"

class Minus: public BinaryOperator {
public:
    Minus(Expression* left, Expression* right): BinaryOperator(left, right) {
    }
    double evaluate() {
       return left->evaluate() - right->evaluate();
    }
};