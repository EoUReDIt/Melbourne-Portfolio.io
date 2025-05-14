// CMSC 330 Advanced Programming Languages
// Project 2
// UMGC CITE
// fall 2024
//Melbourne Anderson

// This file contains the body of the function parseName. That function consumes all alphanumeric 
// characters until the next whitespace and returns the name that those characters form.

#include <cctype>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

#include "parse.h"

string parseName(std::stringstream& in) {
    char alnum;
    string name;

    in >> ws; // Skip whitespace
     cout << "parseName: Skipping whitespace. Stream position after skipping whitespace: " << in.tellg() << endl;

    if (isalpha(in.peek())) { // Ensure the first character is alphabetic
        while (isalnum(in.peek()) || in.peek() == '_') {
            in >> alnum;
            name += alnum;
            cout << "parseName: Adding character '" << alnum << "' to name. Current name: '" << name << "'" << endl;
        }
    } else {
        cout << "parseName: Error - Invalid variable name. First character is '" << in.peek() << "'" << endl;
        throw std::string("Invalid variable name: must start with a letter");
    }

    return name;
}


//added as a reminder that this file as been updated from the original

//The function ensures that the first character of the variable name is alphabetic (isalpha).
//Subsequent characters can be alphabetic, numeric, or underscores (isalnum or '_').
//If the first character is invalid, it throws an exception.

