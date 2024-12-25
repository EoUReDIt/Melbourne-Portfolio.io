//
// Created by Michael on 10/8/2024.
//
#include "ternary.h"
#include <iostream>

// Constructor implementation
Ternary::Ternary(Expression* condition, Expression* trueExpr, Expression* falseExpr)
        : SubExpression(condition, trueExpr), falseExpr(falseExpr) {}
// CMSC 330 Advanced Programming Languages
// Project 2
// UMGC CITE
// fall 2024
//Melbourne Anderson

// evaluate() implementation
double Ternary::evaluate() {
    double conditionValue;

    // Check if the left operand (condition) is a variable and look it up in the symbol table
    Variable* variable = dynamic_cast<Variable*>(left);
    if (variable != nullptr) {
        conditionValue = symbolTable.lookUp(variable->getName());
        std::cout << "Ternary::evaluate: Variable '" << variable->getName() << "' has value: " << conditionValue << std::endl;
    } else {
        conditionValue = left->evaluate();
        std::cout << "Ternary::evaluate: Condition evaluated to " << conditionValue << std::endl;
    }

    if (conditionValue != 0) {
        double result = right->evaluate();
        std::cout << "Ternary::evaluate: Condition is true. Evaluating true expression. Result = " << result << std::endl;
        return result;
    } else {
        double result = falseExpr->evaluate();
        std::cout << "Ternary::evaluate: Condition is false. Evaluating false expression. Result = " << result << std::endl;
        return result;
    }
}
