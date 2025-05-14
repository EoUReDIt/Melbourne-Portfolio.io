// CMSC 330 Advanced Programming Languages
// Project 2
// UMGC CITE
// fall 2024
//Melbourne Anderson


// This file contains the main function for the project 2 skeleton. It reads an input file named input.txt
// that contains one statement that includes an expression following by a sequence of variable assignments.
// It parses each statement and then evaluates it.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <filesystem>  // Include this to access the current path
using namespace std;

#include "expression.h" //Likely defines an abstract base class Expression
#include "subexpression.h" //Defines SubExpression, which could be a derived class of Expression
#include "symboltable.h" //Handles variable storage (symbol table).
#include "parse.h" //Contains functions that help with parsing input, such as parseName.
#include "variableexception.h"  // Include the custom exception


SymbolTable symbolTable; //A global SymbolTable object is used to store variable values. It likely maps variable names to their corresponding values.

void parseAssignments(stringstream& in);

int main() {
    const int SIZE = 256;
    Expression* expression;
    char paren, comma, line[SIZE];
 
    ifstream fin;
     // Print the current working directory
    cout << "Current Working Directory: " << std::filesystem::current_path() << endl;//debugging statement

    fin = ifstream("input.txt");
    if (!(fin.is_open())) {
        cout << "File did not open" << endl;
        system("pause");
        return 1;
    }

    while (true) {
        fin.getline(line, SIZE);
        if (!fin)
            break;
        stringstream in(line, ios_base::in); 
        in >> paren;
        cout << line << " ";

        // Reset the symbol table before processing each statement
        symbolTable.reset();

        try {
                symbolTable.reset();//This ensures the symbol table is cleared before evaluating each new statement.

            // Code that might throw a VariableException
				expression = SubExpression::parse(in);

				parseAssignments(in);
				double result = expression->evaluate();
				cout << "Value = " << result << endl;
			}
			catch (const VariableException& e) {
				cout << "Error: " << e.what() << endl;
			}
			catch (const std::exception& e) {
				cout << "General Error: " << e.what() << endl;
			}

    }

    system("pause");
    return 0;
}

//added as a reminder that this file has been updated from the original

//Add a reset method to the SymbolTable class that clears its contents using elements.clear().
//Call reset in the main function before parsing each new statement to ensure that the symbol table starts fresh for each evaluation.

//The first catch block specifically handles VariableException instances, providing a customized message.
//The second catch block catches any other standard exceptions that might occur.

void parseAssignments(stringstream& in) {
    char assignop, delimiter;
    string variable;
    double value;

    // First, check and consume the comma that separates the expression from assignments
    if (in.peek() == ',') {
        in.get(); // Consume the comma
        cout << "parseAssignments: Comma consumed after expression" << endl;
    } else {
        throw std::string("Expected ',' after expression before assignments");
    }

    do {
        cout << "parseAssignments: Parsing variable name." << endl;
        variable = parseName(in);
        cout << "parseAssignments: Parsed variable name = " << variable << endl;

        in >> ws >> assignop;
        cout << "parseAssignments: Parsed assignment operator = '" << assignop << "'" << endl;

        in >> value;
        cout << "parseAssignments: Parsed value = " << value << endl;

        in >> delimiter;
        cout << "parseAssignments: Parsed delimiter = '" << delimiter << "'" << endl;

        symbolTable.insert(variable, value);
        cout << "parseAssignments: Inserted variable '" << variable << "' with value = " << value << " into symbol table." << endl;

        // If the delimiter is a semicolon, break out of the loop and return to project2.cpp
        if (delimiter == ';') {
            cout << "parseAssignments: Semicolon found. Returning to project2.cpp" << endl;
            return; // Return control back to the caller function in project2.cpp
        }
    } while (delimiter == ',');

// If the code reaches here, it means an unexpected character was found
    cout << "parseAssignments: Error - Expected ';' or ',' but found '" << (char)in.peek() << "'" << endl;
    throw std::string("Expected ';' or ',' in assignments");
}

   
