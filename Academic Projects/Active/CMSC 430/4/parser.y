/* CMSC 430 Compiler Theory and Design
   Project 4
   UMGC CITE
   Summer 2025
   Melbourne Anderson
   
   History ----->
   refactored most semantic action in project 3 parser.y 

   Project title: Project 4 Parser with type checking instead for the intepreter */

%{

#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include "listing.h"
#include "symbols.h" //introduced in Project 3
#include "types.h" // introduced in Project 4 // part of change 1.2
#include <cstring> // for strcpy, also to reduce the need to use std::string and update symbols.h

using namespace std;

int yylex();
void yyerror(const char* message);

//merge from Project 4 sample
Types find(Symbols<Types>& table, CharPtr identifier, string tableName); // merge from Project 4 sample
Symbols<Types> scalars;
Symbols<Types> lists;

%}

%define parse.error verbose

%union {

    CharPtr iden;          // for identifiers (usually char*)	
	//merge from Project 4 sample
	Types type; // for types like INTEGER, CHARACTER, REAL // part of change 1.2

}


%token <type> INT_LITERAL CHAR_LITERAL /// part of change 1.2
%token <type> REAL_LITERAL HEX_LITERAL // TODO: delayed implementation

%token RELOP ADDOP ANDOP MULOP 
%token <type> MODOP NEGOP EXPOP;

%token <iden> IDENTIFIER

%token LEFT RIGHT // for direction in FOLD - TODO: delayed implementation

%token ARROW OROP NOTOP

%token WHEN BEGIN_ END FUNCTION IS LIST OF 

%token RETURNS SWITCH CASE OTHERS ENDSWITCH IF THEN ELSE ELSIF ENDIF FOLD ENDFOLD 

%token CHARACTER REAL INTEGER

%type <type> type //part of change 1.2
%type <type> list expressions
%type <type> relation expression term function function_header body statement_ statement primary 
%type <type> condition condition_list case cases IF_descent ELSIF_descent SWITCH_descent
%type <type> parameter parameters optional_variable variable

%%

function:	
	function_header optional_variable  body {checkAssignment($1, $3, "Variable Initialization");}
	
function_header:	
	FUNCTION IDENTIFIER parameters RETURNS type ';' {$$ = $5;} |
		error {appendError(SYNTAX, "Function header error");}

parameters:
	parameters ',' parameter | 
	parameter | %empty {$$ = NONE;}

parameter:
	IDENTIFIER ':' type

optional_variable:
	optional_variable variable ';'| 
	variable';' |
	error {appendError(SYNTAX, "variable error");} |
	%empty {$$ = NONE;}

variable:	
	IDENTIFIER ':' type IS statement {checkAssignment($3, $5, "Variable Initialization"); Types tempType; scalars.find($1, tempType) ? appendError(GENERAL_SEMANTIC, "Duplicate Scalar " + string($1)) : scalars.insert($1, $3);} |
	IDENTIFIER ':' LIST OF type IS list {checkListElements($5, $7); Types tempType; lists.find($1, tempType) ? appendError(GENERAL_SEMANTIC, "Duplicate List " + string($1)): lists.insert($1, $5);}


type:
	INTEGER {$$=INT_TYPE;}| 
	CHARACTER {$$=CHAR_TYPE;} |
	REAL {$$=REAL_TYPE;} |
	error {appendError(SYNTAX, "type error");}



body:
	BEGIN_ statement_ END ';' {$$ = $2;}

statement_:
	statement_ statement ';' {$$ = $1;} | 
	statement ';' |
	error {appendError(SYNTAX, "statement_ error");} | 
	%empty {$$ = NONE;}


statement: 
	expression |
	WHEN condition_list ',' expression ':' expression {$$=checkWhen($4, $6);} | 
    WHEN error {appendError(SYNTAX, "When statement error");} | SWITCH_descent |
	IF_descent | 
	FOLD direction operator list ENDFOLD {checkFoldListType($4);}


SWITCH_descent:
	SWITCH expression IS cases OTHERS ARROW statement_ ENDSWITCH {$$ = checkSwitch($2, $4, $7);} ; 
	| error {appendError(SYNTAX, "switch error");}


IF_descent:
	IF condition_list THEN statement_ ELSIF_descent ELSE statement_ ENDIF {$$ = checkIfBranches($4, $5, $7);}

ELSIF_descent:
	ELSIF condition_list THEN statement_ ELSIF_descent {$$ = checkIfBranches($4, $5, $5);} |
	error {appendError(SYNTAX, "variable error");} |
	%empty {$$ = NONE;}

direction:
    LEFT | RIGHT

operator: 
	ADDOP | MULOP

cases:
	cases case {$$ = checkCases($1, $2);} | 
	case | %empty {$$ = NONE;}

case:
	CASE INT_LITERAL ARROW statement ';' {$$ = $4;} | 
	CASE error {appendError(SYNTAX, "case error");}


condition_list:
	condition_list ANDOP condition |
	condition_list OROP condition |
	condition

condition:
	NOTOP relation |
	relation

relation:
	'(' condition ')' {$$ = $2;} |
	expression RELOP expression {$$ = checkRelational($1, $3);} | 
	expression

list:
	'(' expressions ')' {$$ = $2;}


expressions:
	expressions ',' expression {$$ = checkListElements($1, $3);} | 
	expression

expression:
	expression ADDOP term {$$ = checkArithmetic($1, $3);} |
	term ;

term:
	term MULOP primary {$$ = checkArithmetic($1, $3);} |
	term MODOP primary {$$ = checkRemainder($1, $3);} |
	term EXPOP primary {$$ = checkExponentiation($1, $3);} |
    term RELOP primary {$$ = checkRelational($1, $3);}
    | primary


primary:
	'(' expression ')' {$$ = $2;} | 
	NEGOP term {$$ = checkNegation($2);} | 
	NOTOP term {$$ = $2;} |
	INT_LITERAL | 
	CHAR_LITERAL | 
	REAL_LITERAL | 
	HEX_LITERAL |
	IDENTIFIER '(' expression ')' {checksubscript($3); $$ = find(lists, $1, "List");} |
	IDENTIFIER {$$ = find(scalars, $1, "Scalar");}


%%

Types find(Symbols<Types>& table, CharPtr identifier, string tableName) {
	Types type;
	if (!table.find(identifier, type)) {
		appendError(UNDECLARED, tableName + " " + identifier);
		return MISMATCH;
	}
	return type;
}

void yyerror(const char* message) {
	appendError(SYNTAX, message);
}

int main(int argc, char *argv[]) {
	firstLine();
	yyparse();
	lastLine();
	return 0;
} 