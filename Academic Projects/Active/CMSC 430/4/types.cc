// CMSC 430 Compiler Theory and Design
// Project 4 Skeleton
// UMGC CITE
// Summer 2023

// This file contains the bodies of the type checking functions

#include <string>
#include <vector>

using namespace std;

#include "types.h"
#include "listing.h"

void checkAssignment(Types lValue, Types rValue, string message) {
	if (lValue != MISMATCH && rValue != MISMATCH && lValue != rValue) {
		// Allow type coercion from INT to REAL and from HEX to INT
		if ((lValue == REAL_TYPE && rValue == INT_TYPE) || 
		   (lValue == INT_TYPE && rValue == HEX_TYPE)) { 
		
			return;
		}
 		appendError(GENERAL_SEMANTIC, "Type Mismatch on " + message);
	}
}

Types checkWhen(Types true_, Types false_) {
	if (true_ == MISMATCH || false_ == MISMATCH)
		return MISMATCH;
	if (true_ != false_)
		appendError(GENERAL_SEMANTIC, "When Types Mismatch ");
	return true_;
}

Types checkSwitch(Types case_, Types when, Types other) {
	if (case_ != INT_TYPE)
		appendError(GENERAL_SEMANTIC, "Switch Expression Not Integer");
	return checkCases(when, other);
}

Types checkCases(Types left, Types right) {
	if (left == MISMATCH || right == MISMATCH)
		return MISMATCH;
	if (left == NONE || left == right)
		return right;
	appendError(GENERAL_SEMANTIC, "Case Types Mismatch");
	return MISMATCH;
}

Types checkArithmetic(Types left, Types right) {
	if (left == MISMATCH || right == MISMATCH)
		return MISMATCH;
	if (left == INT_TYPE && right == INT_TYPE)
		return INT_TYPE;
	if (left == REAL_TYPE || right == REAL_TYPE)
		return REAL_TYPE;
	if (left == HEX_TYPE || right == HEX_TYPE)
		return INT_TYPE; // Allow HEX_TYPE to be treated as INT_TYPE in arithmetic
	appendError(GENERAL_SEMANTIC, "Correct Numeric Type Required");
	return MISMATCH;
}

// TODO: see if the fuction return can be simplified
Types checkListElements(Types left, Types right) {
    if (left == MISMATCH || right == MISMATCH)
        return MISMATCH;
    
	if ((left == INT_TYPE && right == INT_TYPE) ||
		(left == REAL_TYPE && right == REAL_TYPE) ||
		(left == CHAR_TYPE && right == CHAR_TYPE) ||
		(left == HEX_TYPE && right == HEX_TYPE)){
        return left; // Both are the same type
    }
    appendError(GENERAL_SEMANTIC, "Element Types Mismatch");
    return MISMATCH;
}

Types checksubscript(Types sindex) {
    if (sindex == MISMATCH) {
        return MISMATCH;
	}
    if (sindex == INT_TYPE) {
        return INT_TYPE;
	}
	appendError(GENERAL_SEMANTIC, "Index Types Mismatch");
    return MISMATCH;
}


Types checkCharLiteral(Types left, Types right) {
    if (left == MISMATCH || right == MISMATCH)
        return MISMATCH;
    
	if ((left == CHAR_TYPE) && (right == CHAR_TYPE))
        return CHAR_TYPE; // Both are the same type

	// Both numeric: OK (return common type)
    if ((left == INT_TYPE || left == REAL_TYPE || left == HEX_TYPE) &&
        (right == INT_TYPE || right == REAL_TYPE || right == HEX_TYPE))
        return left == REAL_TYPE || right == REAL_TYPE ? REAL_TYPE : INT_TYPE;

	// Otherwise, mismatch
    appendError(GENERAL_SEMANTIC, "Operand Type Mismatch");
    return MISMATCH;
}

Types checkRelational(Types left, Types right) {
	if (left == MISMATCH || right == MISMATCH)
		return MISMATCH;
	if (left == INT_TYPE && right == INT_TYPE)
		return INT_TYPE;
	if (left == REAL_TYPE || right == REAL_TYPE)
		return REAL_TYPE;
	if (left == HEX_TYPE || right == HEX_TYPE)
		return INT_TYPE; // Allow HEX_TYPE to be treated as INT_TYPE in relational expressions
	if (left == CHAR_TYPE || right == CHAR_TYPE)
		return INT_TYPE; // Allow CHAR_TYPE to be treated as valid in relational expressions
	appendError(GENERAL_SEMANTIC, "Correct Numeric Type Required");
	return MISMATCH;
}

// Exponentiation operator (^) - both operands must be numeric
Types checkExponentiation(Types left, Types right) {
    if (left == MISMATCH || right == MISMATCH)
        return MISMATCH;
    if ((left == INT_TYPE || left == REAL_TYPE) &&
        (right == INT_TYPE || right == REAL_TYPE))
        return (left == REAL_TYPE || right == REAL_TYPE) ? REAL_TYPE : INT_TYPE;
    appendError(GENERAL_SEMANTIC, "Exponentiation Operator Requires Numeric Types");
    return MISMATCH;
}

// Negation operator (~) - operand must be numeric
Types checkNegation(Types operand) {
    if (operand == MISMATCH)
        return MISMATCH;
    if (operand == INT_TYPE || operand == REAL_TYPE)
        return operand;
    appendError(GENERAL_SEMANTIC, "Negation Operator Requires Numeric Types");
    return MISMATCH;
}

// Remainder operator (%) - both operands must be integer
Types checkRemainder(Types left, Types right) {
    if (left == MISMATCH || right == MISMATCH)
        return MISMATCH;
    if (left == INT_TYPE && right == INT_TYPE)
        return INT_TYPE;
    appendError(GENERAL_SEMANTIC, "Remainder Operator Requires Integer Operands");
    return MISMATCH;
}

Types checkIfBranches(Types thenType, Types elsifType, Types elseType) {
    if (thenType == MISMATCH || elsifType == MISMATCH || elseType == MISMATCH)
        return MISMATCH;
    // If there is no elsif (elsifType is NONE), only compare then/else
    if (elsifType == NONE) {
        if (thenType == elseType)
            return thenType;
        appendError(GENERAL_SEMANTIC, "If-Else Type Mismatch");
        return MISMATCH;
    }
    // All match
    if (thenType == elsifType && thenType == elseType)
        return thenType;
    appendError(GENERAL_SEMANTIC, "If-Elsif-Else Type Mismatch");
    return MISMATCH;
}


void checkFoldListType(Types listType) {
    if (listType != INT_TYPE && listType != REAL_TYPE && listType != HEX_TYPE) {
        appendError(GENERAL_SEMANTIC, "Fold Requires A Numeric List");
    }
}
