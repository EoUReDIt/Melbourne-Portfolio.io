/* CMSC 430 Compiler Theory and Design
   Project 1
   UMGC CITE
   Summer 2025
   Melbourne Anderson 
*/

/* This file contains flex input file */

%{
#include <cstdio>
#include <string>

using namespace std;

#include "listing.h"
#include "tokens.h"

%}

%option noyywrap

ws		[ \t\r]+
comment		"//".*\n
line		[\n]
id		[A-Za-z]([A-Za-z0-9])*
digit		[0-9]
dec		{digit}+
punc		[\(\),:;]
real    ({digit}+\.[0-9]*([eE][+-]?{digit}+)?|\.[0-9]+([eE][+-]?{digit}+)?)
hex     \#[0-9a-fA-F]+
%%
{real}  { ECHO; return(REAL_LITERAL); }
"if" {ECHO; return IF;}
"then" {ECHO; return THEN;}
"else" {ECHO; return ELSE;}
"elsif" {ECHO; return ELSIF;}
"fold" {ECHO; return FOLD;}
"left" {ECHO; return LEFT;}
"right" {ECHO; return RIGHT;}
"endfold" {ECHO; return ENDFOLD;}
"endif" {ECHO; return ENDIF;}
"^"   { ECHO; return EXPOP; } //Logical Exponent
"|"     { ECHO; return OROP; }  // Logical OR
"!"     { ECHO; return NOTOP; } // Logical NOT
">="    { ECHO; return RELOP; }     // Greater than or equal
"%"     { ECHO; return MODOP; }     // Modulus
"~"     { ECHO; return NEGOP; }     // Bitwise or custom negation
"<>"    { ECHO; return RELOP; }     // Not equals
"/"    { ECHO; return DIVOP; }     // Division
{ws}		{ ECHO; }
{comment}	{ ECHO; nextLine(); }
{line}		{ ECHO; nextLine(); }
"+"		{ ECHO; return(ADDOP); }
"*"		{ ECHO; return(MULOP); }
"-"		{ ECHO; return(SUBOP); } // Substraction
"&"		{ ECHO; return(ANDOP); }
"<="		{ ECHO; return(ARROW); } // Less than or equal
"<"		{ ECHO; return(RELOP); } // Less than
">"     { ECHO; return RELOP; }     // Greater than
"="     { ECHO; return RELOP; }     // Equals
begin		{ ECHO; return(BEGIN_); }
case		{ ECHO; return(CASE); }
character	{ ECHO; return(CHARACTER); }
end		{ ECHO; return(END); }
endswitch	{ ECHO; return(ENDSWITCH); }
function	{ ECHO; return(FUNCTION); }
integer		{ ECHO; return(INTEGER); }
is		{ ECHO; return(IS); }
list		{ ECHO; return(LIST); }
of		{ ECHO; return(OF); }
others		{ ECHO; return(OTHERS); }
returns		{ ECHO; return(RETURNS); }
switch		{ ECHO; return(SWITCH); }
when		{ ECHO; return(WHEN); }
{id}		{ ECHO; return(IDENTIFIER);}
{dec}		{ ECHO; return(INT_LITERAL); }
{punc}		{ ECHO; return(yytext[0]); }
"'.'"             { ECHO; return(CHAR_LITERAL); } // Regular characters
"'\\n'"           { ECHO; return(CHAR_LITERAL); } // Newline escape
"'\\t'"           { ECHO; return(CHAR_LITERAL); } // Tab escape
"'\\\\'"          { ECHO; return(CHAR_LITERAL); } // Backslash
"'\\''"           { ECHO; return(CHAR_LITERAL); } // Escaped quote
%%

int main() {
	firstLine();
	
	FILE *file = fopen("lexemes.txt", "wa"); 
	int token = yylex();
	while (token) {
		fprintf(file, "%d %s\n", token, yytext);
		token = yylex();
	}
	lastLine();
	fclose(file);
	return 0;
}