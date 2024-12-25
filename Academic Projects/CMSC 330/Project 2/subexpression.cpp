// CMSC 330 Advanced Programming Languages
// Project 2
// UMGC CITE
// fall 2024
//Melbourne Anderson


#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "multiply.h"
#include "divide.h"
#include "remainder.h"
#include "exponentiate.h"
#include "minimum.h"
#include "maximum.h"
#include "average.h"
#include "negate.h"
#include "ternary.h"
#include "quaternary.h"

#include <iostream>
using namespace std;

// Constructor definition for SubExpression
SubExpression::SubExpression(Expression* left, Expression* right) {
    this->left = left;
    this->right = right;
}

Expression* SubExpression::parse(stringstream& in) {

    Expression* left;
    Expression* right;
    char operation, paren;

    cout << "SubExpression::parse: Parsing subexpression" << endl;

    left = Operand::parse(in);


    in >> ws;

    // Consume the operation character
    in >> operation;
    cout << "SubExpression::parse: Operation character = '" << operation << "'" << endl;


    // Parse the right operand
    if(in.peek()!= ')') {
        right = Operand::parse(in);
        cout << "SubExpression::parse: Parsed right operand" << endl;
    }

    // Check if the operation is unary (like '~')
    cout << "SubExpression::parse: Checking if the operation is unary ('~')." << endl;
    if (operation == '~') {
        cout << "SubExpression::parse: Unary operation detected ('~')." << endl;
        in >> paren;
        if (paren != ')') {
            cout << "SubExpression::parse: Error - Expected closing parenthesis but found '" << paren << "'" << endl;
            throw std::string("Expected closing parenthesis");
        }
        cout << "SubExpression::parse: Unary operation parsed successfully, returning Negate expression." << endl;
        return new Negate(left);
    }

// Ternary operator
    cout << "SubExpression::parse: Checking if the operation is ternary ('?')." << endl;
    if (operation == '?') {
        cout << "SubExpression::parse: Ternary operation detected ('?'). Parsing middle and right expressions." << endl;

        // Declare middle and right as nullptr initially
        Expression* middle = nullptr;
        Expression* right = nullptr;

        // Parse the middle expression if not already set
        if (in.peek()!=')') {
            cout << "SubExpression::parse: Parsing middle expression." << endl;
            middle = Operand::parse(in);
            cout << "SubExpression::parse: Middle expression parsed." << endl;
        }

        // Parse the right expression if not already set
        if (in.peek()!=')') {
            cout << "SubExpression::parse: Parsing right expression." << endl;
            right = Operand::parse(in);
            cout << "SubExpression::parse: Right expression parsed." << endl;
        }

        // Check for the closing parenthesis after the right expression
        char paren;
        in >> ws >> paren; // Read and consume any whitespace before reading the closing parenthesis
        if (paren == ')') {
            cout << "SubExpression::parse: Closing parenthesis found. Returning Ternary expression." << endl;
            return new Ternary(left, middle, right);
        } else {
            cout << "SubExpression::parse: Error - Expected closing parenthesis but found '" << paren << "'" << endl;
            throw std::string("Expected closing parenthesis after ternary expression");
        }
    }



// Quaternary operator
    cout << "SubExpression::parse: Checking if the operation is quaternary ('#')." << endl;
    if (operation == '#') {
        cout << "SubExpression::parse: quaternary operation detected ('#'). Parsing second and third expressions." << endl;

        // Declare second and third as nullptr initially
        Expression* second = nullptr;
        Expression* third = nullptr;
        Expression* fourth = nullptr;

        // Parse the second expression if not already set
        if (in.peek()!=')') {
            cout << "SubExpression::parse: Parsing second expression." << endl;
            second = Operand::parse(in);
            cout << "SubExpression::parse: second expression parsed." << endl;
        }

        // Parse the third expression if not already set
        if (in.peek()!=')') {
            cout << "SubExpression::parse: Parsing third expression." << endl;
            third = Operand::parse(in);
            cout << "SubExpression::parse: third expression parsed." << endl;
        }


        // Parse the fourth expression if not already set
        if (in.peek()!=')') {
            cout << "SubExpression::parse: Parsing fourth expression." << endl;
            third = Operand::parse(in);
            cout << "SubExpression::parse: fourth expression parsed." << endl;
        }


        // Check for the closing parenthesis after the third expression
        char paren;
        in >> ws >> paren; // Read and consume any whitespace before reading the closing parenthesis
        if (paren == ')') {
            cout << "SubExpression::parse: Closing parenthesis found. Returning quaternary expression." << endl;
            return new Quaternary (left, second, third,fourth);
        } else {
            cout << "SubExpression::parse: Error - Expected closing parenthesis but found '" << paren << "'" << endl;
            throw std::string("Expected closing parenthesis after quaternary expression");
        }
    }

// Binary operations
    cout << "SubExpression::parse: Checking if the operation is binary." << endl;
// Match the operation with the appropriate class
    switch (operation) {
        case '+':
            cout << "SubExpression::parse: Binary operation '+' detected." << endl;
            return new Plus(left, right);
        case '-':
            cout << "SubExpression::parse: Binary operation '-' detected." << endl;
            return new Minus(left, right);
        case '*':
            cout << "SubExpression::parse: Binary operation '*' detected." << endl;
            return new Multiply(left, right);
        case '/':
            cout << "SubExpression::parse: Binary operation '/' detected." << endl;
            return new Divide(left, right);
        case '%':
            cout << "SubExpression::parse: Binary operation '%' detected." << endl;
            return new Remainder(left, right);
        case '^':
            cout << "SubExpression::parse: Binary operation '^' detected." << endl;
            return new Exponentiate(left, right);
        case '<':
            cout << "SubExpression::parse: Binary operation '<' detected." << endl;
            return new Minimum(left, right);
        case '>':
            cout << "SubExpression::parse: Binary operation '>' detected." << endl;
            return new Maximum(left, right);
        case '&':
            cout << "SubExpression::parse: Binary operation '&' detected." << endl;
            return new Average(left, right);
        default:
            cout << "SubExpression::parse: Error - Unsupported operation '" << operation << "'." << endl;
            throw std::string("Unsupported operation: " + std::string(1, operation));
    }

// If we reach here, throw an unsupported operation error
    cout << "SubExpression::parse: Unexpected error - Unsupported operation encountered." << endl;
    throw std::string("Unsupported operation: " + std::string(1, operation));

}


//added as a reminder that this file has been updated from the original