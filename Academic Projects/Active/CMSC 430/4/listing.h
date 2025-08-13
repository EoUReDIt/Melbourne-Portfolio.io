// CMSC 430 Compiler Theory and Design
// Project 4 Skeleton
// UMGC CITE
// Summer 2023

// This file contains the function prototypes for the functions that produce the 
// compilation listing

//added due to compiler warnings and errors
#include <string>
using namespace std;

//original snippet from skeleton
enum ErrorCategories {LEXICAL, SYNTAX, GENERAL_SEMANTIC, DUPLICATE_IDENTIFIER,
	UNDECLARED};

void firstLine();
void nextLine();
int lastLine();
void appendError(ErrorCategories errorCategory, string message);

// included from project 3
int doubleToInt(double d);
int parse_char_literal(const char* text);