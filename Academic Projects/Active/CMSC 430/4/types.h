// CMSC 430 Compiler Theory and Design
// Project 4 Skeleton
// UMGC CITE
// Summer 2023

// This file contains type definitions and the function
// prototypes for the type checking functions

//added due to compile error and order.
#include <string>
using std::string;


//originally from Project 4 skeleton
typedef char* CharPtr;


//added REAL_TYPE to enum Types
enum Types {MISMATCH, INT_TYPE, CHAR_TYPE, REAL_TYPE, HEX_TYPE, NONE};

void checkAssignment(Types lValue, Types rValue, string message);
Types checkWhen(Types true_, Types false_);
Types checkSwitch(Types case_, Types when, Types other);
Types checkCases(Types left, Types right);
Types checkArithmetic(Types left, Types right);
Types checkListElements(Types left, Types right); // added for project 4
Types checksubscript(Types sindex); // manage type checking for subscript
Types checkCharLiteral(Types left, Types right);  // manage type checking for char literals
Types checkRelational(Types left, Types right); // manage type checking for relational expressions
Types checkExponentiation(Types left, Types right); // manage type checking for exponentiation
Types checkNegation(Types operand); // manage type checking for negation
Types checkRemainder(Types left, Types right); // manage type checking for remainder
Types checkIfBranches(Types thenType, Types elsifType, Types elseType); // manage type checking for if-else statements
void checkFoldListType(Types listType); // manage type checking for fold lists