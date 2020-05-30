#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <map>
#include <fstream>
#include <vector>

using namespace std;

class Character {
public:
	//Constructors
	Character(); //Character class contains contents for each character
	Character(string name_, string type_, int length_, int width_); //Character constructor with parameters

	//Functions
	void printCharacter(); //Print character information
	int getSize(); //Return size of character

	//Variables
	string name;
	string type;
	int length;
	int width;
};

#endif /*CHARACTER_H*/
