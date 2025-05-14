// CMSC 330 Advanced Programming Languages
// Project 2
// UMGC CITE
// fall 2024
//Melbourne Anderson

#include "plus.h"
#include <iostream>

// Constructor implementation
Plus::Plus(Expression* left, Expression* right)
        : BinaryOperator(left, right) {
    std::cout << "Plus::Plus: Plus operator created with left and right operands." << std::endl;
}

// evaluate() method implementation
double Plus::evaluate() {
    std::cout << "Plus::evaluate: Evaluating left operand." << std::endl;
    double leftValue = left->evaluate();
    std::cout << "Plus::evaluate: Left operand value = " << leftValue << std::endl;

    std::cout << "Plus::evaluate: Evaluating right operand." << std::endl;
    double rightValue = right->evaluate();
    std::cout << "Plus::evaluate: Right operand value = " << rightValue << std::endl;

    double result = leftValue + rightValue;
    std::cout << "Plus::evaluate: Result of addition = " << result << std::endl;

    return result;
}
