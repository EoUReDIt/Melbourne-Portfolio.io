// CMSC 330 Advanced Programming Languages
// Project 2
// UMGC CITE
// fall 2024
//Melbourne Anderson


// This file contains the definition of the Operand class, which is a subclass of Expression. It is an
// abstract class because it does not implement the evaluate function. It contains one static (class)
// function parse that parses an operand as either a literal or variable.

#ifndef OPERAND_H
#define OPERAND_H

#include "expression.h"
#include <sstream>

class Operand : public Expression {
public:
    static Expression* parse(std::stringstream& in);
};

#endif
