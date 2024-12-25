// CMSC 330 Advanced Programming Languages
// Project 2
// UMGC CITE
// fall 2024
//Melbourne Anderson


// This file contains the body of the functions contained in The SymbolTable class. The insert function 
// inserts a new variable symbol and its value into the symbol table and the lookUp function returns
// that value of the supplied variable symbol name.

#include "symboltable.h"
#include "variableexception.h"
#include <iostream>

void SymbolTable::insert(const std::string& variable, double value) {
    // Check if the variable is already in the table
    if (table.find(variable) != table.end()) {
        throw VariableException("Variable '" + variable + "' initialized more than once.");
    }
    table[variable] = value;
}

double SymbolTable::lookUp(const std::string& variable) const {
    auto it = table.find(variable);
    if (it == table.end()) {
        throw VariableException("Uninitialized variable: '" + variable + "'");
    }
    return it->second;
}

void SymbolTable::reset() {
    table.clear();
}


//added as a reminder that this file has been updated from the original

//The value type in the Symbol structure and the insert function parameter is changed from int to double.
//The lookUp function now returns a double value, which matches the type stored in the symbol table.
//elements.clear();: This line clears all the entries in the elements vector, which effectively resets the symbol table to an empty state.