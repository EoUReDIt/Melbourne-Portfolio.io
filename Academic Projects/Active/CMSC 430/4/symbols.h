// CMSC 430 Compiler Theory and Design
// Project 3 Complete
// UMGC CITE
// Summer 2023

// System Dependencies
#include <string>
#include <map>
using std::string;
using std::map;

// Cross-file Dependencies:
// - Used by parser.y for symbol table management
// - Used by semantic.h for type checking
// - Used in conjunction with values.h for variable storage

// This template class implements a symbol table for compiler symbol management
// Template parameter T allows different types of symbols (functions, variables, etc)
template <typename T>
class Symbols
{
public:
	void insert(char* lexeme, T entry);
	bool find(char* lexeme, T& entry);
private:
	map<string, T> symbols;
};

// Implementation notes:
// insert() - Stores symbol entries with string keys
// find() - Retrieves symbol entries using map iterator
// symbols - Uses STL map for O(log n) lookup performance

template <typename T>
void Symbols<T>::insert(char* lexeme, T entry)
{
	string name(lexeme);
	symbols[name] = entry;
}

template <typename T>
bool Symbols<T>::find(char* lexeme, T& entry)
{
	string name(lexeme);
	typedef typename map<string, T>::iterator Iterator;
	Iterator iterator = symbols.find(name);
	bool found = iterator != symbols.end();
	if (found)
		entry = iterator->second;
	return found;
}