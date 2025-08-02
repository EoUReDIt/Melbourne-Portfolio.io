/* CMSC 430 Compiler Theory and Design
   Project 3
   UMGC CITE
   Summer 2025
   Melbourne Anderson
   
   History ----->
   1.This is a file copy from Project 1
   2.Main method was removed - project 2 does not require a main method
   
   updated 7-21-2025
   3.this file was updated from Project 2 to Project 3
   4.updated to use the new values.h, listing.h, and symbols.h files
   5.Updated to use the new symbols class which is now a template class
   6. optional INT_LITERAL { $$ = static_cast<double>($1); }
   7. updated INT_LITERAL, CHAR_LITERAL, and HEX_LITERAL to use static_cast<double> for consistency
```````CHAR_LITERAL { $$ = static_cast<double>($1); }
	8. updated WHEN, condition and statement with semantic actions
	9. updated NEGOP term to use semantic action
	
	file breakdown ----->
	values.h - contains the enumeration for Operators and the CharPtr type as well as the declaration of evaluateArithmetic and evaluateRelational functions
	valus.cc - contains the implementation of evaluateArithmetic and evaluateRelational functions
	scanners.l - contains the scanner rules for the lexer
	parser.y - contains the parser rules, semantic actions, and error handling for the parser
   
   workflow ----->
   1. declare the necessary headers and namespaces, custom functions, and global variables in the %{ %} section
   2. define the union for semantic values using %union
   3. define the tokens using %token and specify their types
   4. define the grammar rules using %type and the rules themselves
   5. implement the grammar rules in the %% section, including semantic actions for each rule
   6. %type is used to specify the type of non-terminal symbols
   10. REMEMBER bison is a LR(i) parser generator, so it uses a bottom-up parsing approach
   11. Base case is on the right side of the rule, and the semantic action is executed when the rule is reduced
   12. all non-terminal symbols in the recursive path are related to the first LR(i) item in the grammar
   13. variables need to be inserted into the symbols table before they can be used in expressions
   14. statments require a semicolon at the end but these should be add at the expression level and not at the statement
   15. %empty {$$ = -1;} means no condition was found, so the value is set to -1
   #TODO
   1. recheck requirement #4
   Project title: Project 3 Parser with semantic actions for the intepreter */

%{

#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <vector>

#include <vector>
#include "values.h"
using namespace std;
#include "listing.h"
#include "symbols.h"

#include <cstring> // for strcpy, also to reduce the need to use std::string and update symbols.h

int yylex();
void yyerror(const char* message);
double extract_element(CharPtr list_name, double subscript);
double parameter_parser(const char* text); // function to parse parameters from the function header

Symbols<double> scalars; //from symbols.h
Symbols<double> paramSymbols;  // holds param1, param2, ...
Symbols<vector<double>*> lists;
double result;

%}

%define parse.error verbose

%union {
    int value;             // for integer and char literals
	double dbl;        // for real literals
    CharPtr iden;          // for identifiers (usually char*)
    Operators oper;        // for enums like ADD, MULTIPLY
    vector<double>* list;  // for list attributes

}


%token <value> INT_LITERAL REAL_LITERAL HEX_LITERAL CHAR_LITERAL

%token <oper> RELOP ADDOP ANDOP MULOP MODOP NEGOP EXPOP;

%token <iden> IDENTIFIER

%token <value> LEFT RIGHT

%token ARROW OROP NOTOP

%token WHEN BEGIN_ END FUNCTION IS LIST OF 

%token RETURNS SWITCH CASE OTHERS ENDSWITCH IF THEN ELSE ELSIF ENDIF FOLD ENDFOLD 

%token CHARACTER REAL INTEGER

%type <list> list expressions
%type <dbl> relation expression term function body statement_ statement primary
%type <dbl> condition condition_list case cases IF_descent ELSIF_descent SWITCH_descent
%type <oper> operator // for ADDOP, MULOP, etc.
%type <value> direction // for LEFT and RIGHT

%%

function:	
	function_header optional_variable  body {result = $3;}
	
function_header:	
	FUNCTION IDENTIFIER parameters RETURNS type ';' |
		error {appendError(SYNTAX, "Function header error");}

parameters:
	parameters ',' parameter | 
	parameter | %empty

parameter:
	IDENTIFIER ':' type {parameter_parser($1);}

optional_variable:
	optional_variable variable ';'| 
	variable';' |
		error ';' |
	%empty 

variable:	
	IDENTIFIER ':' type IS statement {scalars.insert($1, $5); } |
	IDENTIFIER ':' LIST OF type IS list {lists.insert($1, $7);}

type:
	INTEGER| 
	CHARACTER|
	REAL

body:
	BEGIN_ statement_ END ';' {$$ = $2;}

statement_:
	statement_ statement ';' {$$ = $1;} | 
	statement ';' |
	error {$$ = NAN;} | %empty {$$ = 0;} 

statement: 
	expression |
	WHEN condition_list ',' expression ':' expression {$$ = $2 ? $4 : $6;} | 
    WHEN error {$$=0;} | SWITCH_descent |
	IF_descent | 
	FOLD direction operator list ENDFOLD {$$ = evaluateFold($2, $3, $4);}


SWITCH_descent:
	SWITCH expression IS cases OTHERS ARROW statement_ ENDSWITCH {$$ = !isnan($4) ? $4 : $7;} ; 
	| error {$$ = NAN;}


IF_descent:
	IF condition_list THEN statement_ ELSIF_descent ELSE statement_ ENDIF { $$ = $2 ? $4 : ($5 != -1 ? $5 : $7); }

ELSIF_descent:
	ELSIF condition_list THEN statement_ ELSIF_descent {$$ = $2 ? $4 : $5;} |
	ELSIF error ELSIF_descent { $$ = $3; } |
	%empty {$$ = -1;}

direction:
    LEFT { $$ = 1; } | RIGHT { $$ = 0; }

operator: 
	ADDOP | MULOP

cases:
	cases case | case

case:
	CASE INT_LITERAL ARROW statement ';' {$$ = $<value>-2 == $2 ? $4 : NAN;} ;  | 
	CASE error ';' {$$=0;}


condition_list:
	condition_list ANDOP condition {$$ = $1 && $3;} |
	condition_list OROP condition {$$ = $1 || $3;}|
	condition

condition:
	NOTOP relation {$$ = !$2;} |
	relation

relation:
	'(' condition ')' {$$ = $2;} |
	expression RELOP expression {$$ = evaluateRelational($1, $2, $3);} ; | 
	expression

list:
	'(' expressions ')' {$$ = $2;} | 
	IDENTIFIER {vector<double>* ptr = nullptr; if (lists.find($1, ptr)) $$ = ptr; else { appendError(UNDECLARED, $1); $$ = nullptr; }}

expressions:
	expressions ',' expression  {$1->push_back($3); $$ = $1;} | 
	expression {$$ = new vector<double>(); $$->push_back($1);}

expression:
	expression ADDOP term {$$ = evaluateArithmetic($1, $2, $3);} |
	term ;

term:
	term MULOP primary {$$ = evaluateArithmetic($1, $2, $3);} |
	term MODOP primary {$$ = evaluateArithmetic($1, $2, $3);} |
	term EXPOP primary {$$ = evaluateArithmetic($1, $2, $3);} |
    term RELOP primary {$$ = evaluateRelational($1, $2, $3);}
    | primary


primary:
	'(' expression ')' {$$ = $2;} | 
	NEGOP term {$$ = -$2;} | 
	NOTOP term {$$ = !$2;} |
	INT_LITERAL { $$ = static_cast<double>($1); } | 
	CHAR_LITERAL { $$ = static_cast<double>($1); } | 
	REAL_LITERAL { $$ = static_cast<double>($1); } | 
	HEX_LITERAL { $$ = static_cast<double>($1); } |
	IDENTIFIER '(' expression ')' {$$ = extract_element($1, $3); } |
	IDENTIFIER {if (!scalars.find($1, $$)) appendError(UNDECLARED, $1);} ;


%%

void yyerror(const char* message) {
	appendError(SYNTAX, message);
}

double extract_element(CharPtr list_name, double subscript) {
	vector<double>* list; 
	if (lists.find(list_name, list))
		return (*list)[subscript];
	appendError(UNDECLARED, list_name);
	return NAN;
}

//helper for parameter parsing
double parameter_parser(const char* declaredName) {
	// This function is used to parse parameters from the function header
	// It creates a unique parameter name (param1, param2, ...) and links it
	static int paramIndex = 1;
	double value = 0;

	std::string paramKey = "param" + std::to_string(paramIndex++);
	
	// Debugging output
	//std::cout << "Parameterkey " << paramKey <<std::endl;

	char* paramKeyC = strdup(paramKey.c_str());
	char* declaredC = strdup(declaredName);

		if (paramSymbols.find(paramKeyC, value)) {
			scalars.insert(declaredC, value);  // link to true name
			//std::cout << "Parameter inserted: " << declaredC << " value: " << value << std::endl;
		//debugging output
		} //should skip if no parameter is found
		else {
			appendError(UNDECLARED, declaredC);
			value = NAN; // set value to NaN if parameter is not found
		}
	
	// Debugging output
	//std::cout << "parameter value linked to variable: " << value << std::endl;

		free(paramKeyC);
		free(declaredC);
		return value;
}



int main(int argc, char *argv[]) {



	//added script to handle command line arguments for parameters
	if (argc > 1) {
		double* params = new double[argc - 1];

		for (int i = 1; i < argc; i++) {
			double value = atof(argv[i]);
			std::string name = "param" + std::to_string(i);
			char* buffer = new char[name.length() + 1];
			strcpy(buffer, name.c_str());
			paramSymbols.insert(buffer, value);
			//debugging output
			//std::cout << "Parameter inserted: " << buffer << " value: " << value << std::endl;
			delete[] buffer;
		}

		delete[] params;
	}

	
	firstLine();
	yyparse();
	if (lastLine() == 0)
		cout << "Result = " << result << endl;
	return 0;
} 
