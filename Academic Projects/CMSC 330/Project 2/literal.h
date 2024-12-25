// CMSC 330 Advanced Programming Languages
// Project 2
// UMGC CITE
// fall 2024
//Melbourne Anderson


// This file contains the definition of the Literal class, whose representation consists of the value
// of the literal. Because both of its functions are one line functions, they are implemented as inline 
// functions. The constructor saves the value of the literal. Because this class is a subclass of Operand
// which in turn is a subclass of Expression, it must implement the function evaluate, which returns the
// value that corresponds to the literal.

#ifndef LITERAL_H
#define LITERAL_H

#include "operand.h"

class Literal : public Operand {
public:
    Literal(double value) {
        this->value = value;
        cout << "Literal::Literal: Created literal with value = " << value << endl; // Debugging statement
    }

    double evaluate() override {
        cout << "Literal::evaluate: Evaluating literal value = " << value << endl; // Debugging statement
        return value;
    }

private:
    double value;  // Change from int to double
};

#endif

//this file was updated from the original

//The function now reads a double value instead of an int.
//It uses std::istream’s ability to automatically convert strings to double values, whether the input is an integer (e.g., 5) or a floating-point number (e.g., 3.14).
//This modification allows both integers and floating-point numbers as literals.