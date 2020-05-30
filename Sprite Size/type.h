#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <map>
#include <fstream>
#include <vector>

#include "character.h"

using namespace std;

class Type { //Type class contains a vector of characters, a name, and an index number
public:
	//Constructors
	Type(); //Type default constructor
	Type(string type_, uint64_t index_); //Type constructor with parameters

	//Functions
	void insertCharacter(Character newchar); //Insert a character into the type's character vector
	void printCharacterList(); //Print all characters in the vector
	int getSizeType(); //Gets the type's total size

	//Variables
	string type;
	uint64_t index;
	vector<Character> chars; //Array of characters that each type will have
};

#endif /*TYPE_H*/