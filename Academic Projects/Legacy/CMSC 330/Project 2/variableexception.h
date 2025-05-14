// CMSC 330 Advanced Programming Languages
// Project 2
// UMGC CITE
// fall 2024
//Melbourne Anderson

#ifndef VARIABLEEXCEPTION_H
#define VARIABLEEXCEPTION_H

#include <exception>
#include <string>

// Custom exception class for handling variable-related errors
class VariableException : public std::exception {
public:
    // Constructor that takes an error message as input
    VariableException(const std::string& message);

    // Override the what() function from std::exception to return the error message
    const char* what() const noexcept override;

private:
    std::string message;  // Error message for the exception
};

#endif


//added as a reminder that this file did not exist in the skeleton

//variableexception.h: Defines the VariableException class, including the constructor and what() method.
//variableexception.cpp: Implements the methods