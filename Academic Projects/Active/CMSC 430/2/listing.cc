/* CMSC 430 Compiler Theory and Design
   Project 1
   UMGC CITE
   Summer 2025
   Melbourne Anderson 
*/


// This file contains the bodies of the functions that produces the 
// compilation listing

#include <cstdio>
#include <string>
#include <vector>

using namespace std;

#include "listing.h"

static int lineNumber;
static vector<string> errors;
static int lexicalErrors = 0, syntaxErrors = 0, semanticErrors = 0;

// Define messages for each error category
static const char* errorMessages[] = {
	"Lexical Error: ",
	"Syntax Error: ",
	"Semantic Error: "
};

static void displayErrors();

void firstLine()
{
	lineNumber = 1;
	printf("\n%4d  ",lineNumber);
}

void nextLine()
{
	displayErrors();
	lineNumber++;
	printf("%4d  ",lineNumber);
}


int lastLine()
{
	printf("\r");
	displayErrors();
	printf("     \n");
	printf("Lexical Errors %d\n", lexicalErrors);
	printf("Syntax Errors %d\n", syntaxErrors);
	printf("Semantic Errors %d\n", semanticErrors);
	return lexicalErrors + syntaxErrors + semanticErrors;
}

    
void appendError(ErrorCategories errorCategory, string message)
{
	errors.push_back(errorMessages[errorCategory] + message);
	if (errorCategory == LEXICAL) lexicalErrors++;
	else if (errorCategory == SYNTAX) syntaxErrors++;
	else semanticErrors++;

}

void displayErrors()
{
	for (string e : errors)
		printf("%s\n", e.c_str());
	errors.clear();
}
