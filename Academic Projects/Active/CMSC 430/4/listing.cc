// CMSC 430 Compiler Theory and Design
// Project 4 Skeleton
// UMGC CITE
// Summer 2023

// This file contains the bodies of the functions that produces the 
// compilation listing

//originally from skeleton
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

#include "listing.h"

//included from project 3
#include <cstring>  // for strlen
#include <cmath>    // for round

//originally from skeleton
static int lineNumber;
static int lexicalErrors;
static int syntaxErrors;
static int semanticErrors;
static vector<string> errors;

static void displayErrors();

void firstLine() {
	lexicalErrors = 0;
	syntaxErrors = 0;
	semanticErrors = 0;
	lineNumber = 1;
	printf("\n%4d  ",lineNumber);
}

void nextLine() {
	displayErrors();
	lineNumber++;
	printf("%4d  ",lineNumber);
}

int lastLine() {
	printf("\r");
	displayErrors();
	printf("     \n");
	int totalErrors = lexicalErrors + syntaxErrors + semanticErrors;
	if (totalErrors > 0)
	{
		printf("Lexical Errors %d\n", lexicalErrors);
		printf("Syntax Errors %d\n", syntaxErrors);
		printf("Semantic Errors %d\n", semanticErrors);

	}
	else
		printf("Compiled Successfully\n\n");
	return totalErrors;
}
    
void appendError(ErrorCategories errorCategory, string message) {
	string messages[] = { "Lexical Error, Invalid Character ", 
	"Syntax Error, U", "Semantic Error, ",
	"Semantic Error, Duplicate ", 
	"Semantic Error, Undeclared " };

	switch (errorCategory) {
		case LEXICAL:
			lexicalErrors++;
			break;
		case SYNTAX:
			//updated message length with if statement for greater than 15
			if (message.length() > 15)
        		message = message.substr(15);
			syntaxErrors++;
			break;
		case GENERAL_SEMANTIC:
		case DUPLICATE_IDENTIFIER:
		case UNDECLARED:
			semanticErrors++;
			break;
    }
	errors.push_back(messages[errorCategory] + message);
}

void displayErrors() {
	for (int i = 0; i < errors.size(); i++)
		printf("%s\n", errors[i].c_str());
	errors.clear();
}


// Existing listing.cc content > above

int doubleToInt(double d) {
    return round(d); // swap in round(), floor() or static_cast<int>(d) etc. if needed
}

int parse_char_literal(const char* text){
    size_t len = strlen(text);
    if (len < 3 || text[0] != '\'' || text[len - 1] != '\'')
        return 0;

    if (text[1] != '\\') {
        return text[1];
    } else {
        switch (text[2]) {
            case 'n': return '\n';
            case 't': return '\t';
            case 'r': return '\r';
            case 'f': return '\f';
            case 'b': return '\b';
            case 'v': return '\v';
            case '\\': return '\\';
            case '\'': return '\'';
            case '"':  return '\"';
            default: return 0;
        }
    }
}