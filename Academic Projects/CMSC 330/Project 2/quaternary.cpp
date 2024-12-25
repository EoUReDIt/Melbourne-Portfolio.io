// CMSC 330 Advanced Programming Languages
// Project 2
// UMGC CITE
// fall 2024
//Melbourne Anderson

#include "quaternary.h"
#include <iostream>

// Constructor implementation
Quaternary::Quaternary(Expression* condition, Expression* second, Expression* third, Expression* fourth)
    : SubExpression(condition, second), second(second), third(third), fourth(fourth) {}

// evaluate() implementation
double Quaternary::evaluate() {
    double conditionValue;

    // Check if the left operand (condition) is a variable and look it up in the symbol table
    Variable* variable = dynamic_cast<Variable*>(left);
    if (variable != nullptr) {
        conditionValue = symbolTable.lookUp(variable->getName());
        std::cout << "Quaternary::evaluate: Variable '" << variable->getName() << "' has value: " << conditionValue << std::endl;
    } else {
        conditionValue = left->evaluate();
        std::cout << "Quaternary::evaluate: Condition evaluated to " << conditionValue << std::endl;
    }

    if (conditionValue <= 0) {
        std::cout << "Quaternary::evaluate: Condition is less than zero. Evaluating second expression." << std::endl;
        double result = second->evaluate();
        return result;
    } 
    if (conditionValue == 0) {
        std::cout << "Quaternary::evaluate: Condition is zero. Evaluating third expression." << std::endl;
        double result = third->evaluate();
        return result;
    } 
    if (conditionValue >= 0){
        std::cout << "Quaternary::evaluate: Condition is greater than zero. Evaluating fourth expression." << std::endl;
        double result = fourth->evaluate();
        return result;
    } 
}
