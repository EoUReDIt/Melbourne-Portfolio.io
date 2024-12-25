// CMSC 330 Advanced Programming Languages
// Project 2
// UMGC CITE
// fall 2024
//Melbourne Anderson

// This file contains the class definition of the SymbolTable class. The symbol table is represented
// with a vector (list) of type Symbol which is a pair consisting of a variable and its associated value.
// The body of its functions are defined in symboltable.cpp.

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <string>
#include <unordered_map>

class SymbolTable {
public:
    void insert(const std::string& variable, double value);
    double lookUp(const std::string& variable) const;
    void reset();

private:
    std::unordered_map<std::string, double> table;
};

#endif


//added as a reminder that this file as been updated from the original

//The value type in the Symbol structure and the insert function parameter is changed from int to double.
//The lookUp function now returns a double value, which matches the type stored in the symbol table.
//reset(): This method will clear the elements vector, effectively removing all stored symbols