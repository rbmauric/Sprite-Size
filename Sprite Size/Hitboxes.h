#ifndef HITBOXES_H
#define HITBOXES_H

#include <string>
#include <map>
#include <fstream>
#include <vector>

#include "type.h"

using namespace std;

class Hitboxes {
public:
	//Constructor
	Hitboxes(const string& filename);  //Hitboxes constructor with parameters

	//Functions
	int insertType(string type, int n); //Add type to our hitboxes map
	void printHitboxes(); //Print all characters in the type map
	string smallestCharacter(); //Return the smallest character in the type map
	string smallestType(); //Returns the overall smallest type in the type map

private:
	//Variables
	map<uint64_t, Type> hb; //Map acts as a hash table, contains an integer key and a type at each index
};

#endif /*HITBOXES_H*/
