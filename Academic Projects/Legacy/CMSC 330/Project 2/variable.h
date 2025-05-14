// CMSC 330 Advanced Programming Languages
// Project 2
// UMGC CITE
// fall 2024
//Melbourne Anderson


// This file contains the class definition of the Variable class. The variable is represented by its
// name, which the construcor initializes. Because this class is a subclass of Operand which in turn is 
// a subclass of Expression, it must implement the function evaluate, whose body is defined in variable.cpp.
//#include "operand.h"

#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "operand.h"

class Variable : public Operand {
public:
    explicit Variable(const std::string& name) : name(name) {}

    // Method to get the name of the variable
    [[nodiscard]] const std::string& getName() const {
        return name;
    }

    double evaluate() override;

private:
    std::string name;
};

#endif // VARIABLE_H
