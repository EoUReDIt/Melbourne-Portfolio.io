// CMSC 430 Compiler Theory and Design
// Project 3 Skeleton
// UMGC CITE
// Summer 2023

// This file contains the bodies of the evaluation functions

/*

History ----->
1. Added implementation for SUBTRACT and DIVIDE operations in evaluateArithmetic
2. added implementation for GREATER, GREATERWEQUAL, and LESSEQUAL in evaluateRelational
3. added additional operators: REMAINDER and POWER
4. added additional cases for NOTEQUAL and AND in evaluateRelational
5. Implemented evaluateFold function to handle left and right folds with arithmetic operations
*/

#include <string>
#include <cmath>
//#include <iostream> //for debugging output
using namespace std;

#include "values.h"
#include "listing.h"


double evaluateArithmetic(double left, Operators operator_, double right) {
	double result;

	//debugging output
	//std::cout << "Evaluating: " << left << " " << operator_ << " " << right << std::endl;

	// Perform the arithmetic operation based on the operator
	switch (operator_) {
		case ADD:
			result = left + right;
			break;
		case MULTIPLY:
			result = left * right;
			break;
		case SUBTRACT:
			result = left - right;
			break;
		case DIVIDE:
			result = left / right;
			break;
		case POWER:
			result = pow(left, right);
			break;
		case REMAINDER:
			result = fmod(left, right);
			break;
	}
	return result;
}

double evaluateRelational(double left, Operators operator_, double right) {
	double result;

	//debugging output
	//std::cout << "Evaluating: " << left << " " << operator_ << " " << right << std::endl;

	// Perform the relational operation based on the operator
	switch (operator_) {
		case LESS:
			result = left < right;
			break;
		case GREATER:
			result = left > right;
			break;
		case GREATERWEQUAL:
			result = left >= right;
			break;
		case LESSWEQUAL:
			result = left <= right;
			break;
		case NOTEQUAL:
			result = left != right;
			break;
		case AND:
			result = left && right;
			break;
	}
	return result;
}

double evaluateFold(int direction, Operators op, vector<double>* list) {
    if (list == nullptr || list->empty()) return 0.0;

	//debugging output
	//std::cout << "Evaluating fold with direction: " << direction << " and operator: " << op << std::endl;
    
	double result;
    if (direction == 1) { // LEFT fold
        result = list->at(0);
        for (size_t i = 1; i < list->size(); ++i) {
            result = evaluateArithmetic(result, op, list->at(i));
        }
    } else { // RIGHT fold
        result = list->at(list->size() - 1);
        for (int i = list->size() - 2; i >= 0; --i) {
            result = evaluateArithmetic(list->at(i), op, result);
        }
    }
    return result;
}
