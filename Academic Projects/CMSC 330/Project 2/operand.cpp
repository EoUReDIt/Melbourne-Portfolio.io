// CMSC 330 Advanced Programming Languages
// Project 2
// UMGC CITE
// fall 2024
//Melbourne Anderson


// This file contains the body of the function parseName contained in the Operand class. That function
// parses the next token. When the next non-whitespace character is a digit, it assumes a literal is next. 
// When the next character is a left parenthesis, a recursive call is made to parse the subexpression.
// Otherwise the next token is assumed to a variable. No checks are made to ensure correct syntax.

#include <cctype>
#include <iostream>
#include <sstream>
#include <list>
#include <string>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "variable.h"
#include "literal.h"
#include "parse.h"

Expression* Operand::parse(stringstream& in) {
    char paren;
    double value;//Use double to support floating-point numbers

    cout << "Operand::parse: Stream before parsing: '" << in.str().substr(in.tellg()) << "'" << endl;//debugging statement

    in >> ws; // Skip any whitespace

    cout << "Operand::parse: Peek character = '" << (char)in.peek() << "'" << endl;//debugging statement

    // Check if the next character is a digit or a decimal point
    if (isdigit(in.peek()) || in.peek() == '.') {
        in >> value;  // Read a double value
        cout << "Operand::parse: Parsed literal value = " << value << endl; // Debugging statement
        Expression* literal = new Literal(value);
        return literal;
    }
    if (in.peek() == '(') {
        in >> paren;
        cout << "Operand::parse: Detected subexpression" << endl; // Debugging statement
        return SubExpression::parse(in);
    }
    else {
        string name = parseName(in);
        cout << "Operand::parse: Parsed variable name = " << name << endl; // Debugging statement
        return new Variable(name);
    }
    // Return nullptr if none of the conditions match (safety measure)
    cout << "Operand::parse: Returning nullptr (unexpected)" << endl; // Debugging statement
    return nullptr;
}


//added as a reminder that this file as been updated from the original