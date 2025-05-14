// CMSC 330 Advanced Programming Languages
// Project 2
// UMGC CITE
// fall 2024
//Melbourne Anderson

// This file contains the definition of the Expression class, which is an abstract class that contains one
// abstract (pure virtual) function named evaluate, which must be implemented by all its subclasses.

// expression.h
#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression {
public: 
    virtual double evaluate() = 0;
};

#endif