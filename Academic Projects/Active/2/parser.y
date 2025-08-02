/* CMSC 430 Compiler Theory and Design
   Project 2 Skeleton
   UMGC CITE
   Summer 2023 

   Project 2 Parser */

%{

#include <string>

using namespace std;

#include "listing.h"

int yylex();
void yyerror(const char* message);

%}

%define parse.error verbose

%token IDENTIFIER INT_LITERAL CHAR_LITERAL REAL_LITERAL REAL

%token ADDOP MULOP ANDOP RELOP ARROW EXPOP OROP NOTOP MODOP NEGOP SUBOP

%token BEGIN_ CASE CHARACTER ELSE END ENDSWITCH FUNCTION INTEGER IS LIST OF OTHERS
	RETURNS SWITCH WHEN IF THEN ELSIF FOLD ENDFOLD LEFT RIGHT ENDIF

%%

function:	
	function_header variable_declarations body ; | 
		error ';' 


function_header:	
	FUNCTION IDENTIFIER parameters RETURNS type ';' |
		error ';' 

parameters:
	parameter |
	parameter ',' parameters | 
	%empty

parameter:
	IDENTIFIER ':' type

variable_declarations:
	variable variable_declarations | 
		error ';' |
	%empty 

type:
	INTEGER | 
	CHARACTER |
	REAL
    
variable:	
	IDENTIFIER ':' type IS statement ';' |
	IDENTIFIER ':' LIST OF type IS list ';' 

list:
	'(' expressions ')' ;

expressions:
	expressions ',' expression| 
	expression 

body:
	BEGIN_ statement_ END ';'

statement_:
	statement ';' |
	error ';' 
    
statement:
	expression |
	WHEN condition ',' expression ':' expression | 
	WHEN error ';' |
	SWITCH expression IS case OTHERS ARROW statement ';' ENDSWITCH | 
	SWITCH expression IS error ENDSWITCH |
	IF condition THEN statement ';' ELSIF_declaration ELSE statement ';' ENDIF |
	FOLD direction operator list_choice ENDFOLD ; 

ELSIF_declaration:
	ELSIF condition THEN statement ';' ELSIF_declaration |
	%empty 

direction: 
	LEFT | RIGHT

operator: 
	ADDOP | MULOP | SUBOP;

list_choice: 
	list | IDENTIFIER;
	
case:
	CASE INT_LITERAL ARROW statement ';' | 
	%empty | 
	CASE error ';' 

condition:
      condition OROP and_condition
    | and_condition


and_condition:
      and_condition ANDOP not_condition
    | not_condition


not_condition:
      NOTOP not_condition
    | relation


relation:
	'(' condition ')' |
	expression RELOP expression


expression:
    expression ADDOP term
    | expression SUBOP term
    | term ;

term:
    term MULOP power
    | term DIVOP power
    | term MODOP power
    | power ;

power:
    power EXPOP unary    // Right-associative
    | unary ;

unary:
    SUBOP unary         // Unary minus (highest precedence)
    | primary ;

primary:
	NEGOP primary |
	INT_LITERAL |
	CHAR_LITERAL |
	REAL_LITERAL |
	IDENTIFIER '(' expression ')' |
	IDENTIFIER |
	'(' expressions ')' 

%%

void yyerror(const char* message) {
	appendError(SYNTAX, message);

}

int main(int argc, char *argv[]) {
	firstLine();
	yyparse();
	lastLine();
	
	return 0;
} 
