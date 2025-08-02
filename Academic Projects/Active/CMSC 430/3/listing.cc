#ifndef LISTING_H
#define LISTING_H
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
#include <cstring>  // for strlen
#include <cmath>    // for round

using namespace std;

#include "listing.h"

static int lineNumber;
static string error = "";
static int totalErrors = 0;

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
	return totalErrors;
}

    
void appendError(ErrorCategories errorCategory, const char* message)
{
	string messages[] = { "Lexical Error, Invalid Character ", "",
		"Semantic Error, ", "Semantic Error, Duplicate ",
		"Semantic Error, Undeclared " };

	error = messages[errorCategory] + message;
	totalErrors++;
}

void displayErrors()
{
	if (error != "")
		printf("%s\n", error.c_str());
	error = "";
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
#endif // LISTING_H