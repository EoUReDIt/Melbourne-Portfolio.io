// CMSC 430 Compiler Theory and Design
//Project 3
//UMGC CITE
//Summer 2025
//Melbourne Anderson

// This file contains type definitions and the function
// definitions for the evaluation functions

//History ----->
/*1. added new enum Operators: SUBTRACT and DIVIDE
2. added new enum Operators: GREATER, GREATERWEQUAL, and LESSEQUAL
3. added additional operators: REMAINDER and POWER
4. added additional cases for NOTEQUAL


*/

//changes made to the original file:
// System Dependencies
#include <vector>    // STL vector container
using std::vector;   // Standard namespace import

// Cross-file Dependencies:
// - Used by scanner.l for operator enums
// - Used by parser.y for evaluation functions
// - Implementation in values.cc

typedef char* CharPtr;

enum Operators {ADD, SUBTRACT, DIVIDE, MULTIPLY, POWER, REMAINDER, LESS, GREATER, GREATERWEQUAL, 
    NOTEQUAL, LESSWEQUAL, AND, OR, NOT};

double evaluateArithmetic(double left, Operators operator_, double right);
double evaluateRelational(double left, Operators operator_, double right);
double evaluateFold(int direction, Operators op, vector<double>* list);

