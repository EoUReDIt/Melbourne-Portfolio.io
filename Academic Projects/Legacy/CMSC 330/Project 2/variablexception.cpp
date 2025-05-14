// CMSC 330 Advanced Programming Languages
// Project 2
// UMGC CITE
// fall 2024
//Melbourne Anderson

#include "variableexception.h"

// Constructor implementation (if not inline in the header)
VariableException::VariableException(const std::string& message) : message(message) {}

// Override the what() function from std::exception to return the error message
const char* VariableException::what() const noexcept {
    return message.c_str();
}
