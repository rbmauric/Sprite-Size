#include "Hitboxes.h"
#include <iostream>

using namespace std;

Hitboxes::Hitboxes(const string& filename) {
	ifstream myfile(filename); //Open file stream

	string name;
	string type;
	int length;
	int width;

	map<uint64_t, Type>::iterator it; //Iterator to point to type map

	while (!myfile.eof()) { //Read through the file
		myfile >> name >> type >> length >> width;
		Character newChar(name, type, length, width); //Create a new character based on file

		it = hb.find(insertType(type, 0)); //Call insertType, point the iterator to the index it returns
		it->second.insertCharacter(newChar); //Call insertCharacter to add character to correct type vector
	}

	myfile.close(); //Close the file
}


int Hitboxes::insertType(string type, int n) {
	if (n == hb.size()) { //Reached end of type map, add the new type
		Type newType(type, n);
		hb.insert(std::pair<uint64_t, Type>(n, newType));
		return n;
	}

	if (hb.at(n).type == type)  //Check if type is already in the type map
		return n; //Return index where type is
	else //Move to next type in type map
		return insertType(type, n + 1); //Recursively call insertType to reach final index
}

void Hitboxes::printHitboxes() {
	map<uint64_t, Type>::iterator it = hb.begin(); //Point iterator to the beginning of the type map

	if (hb.empty()) //Check if the type map is empty
		cout << "No characters have been added yet! \n";

	while (it != hb.end()) { //Iterate through type map
		cout << "TYPE: " << it->second.type << endl;
		it->second.printCharacterList(); //Print each character for each type
		cout << "Size: " << it->second.getSizeType() << endl;
		cout << endl;
		it++; //Increment iterator to next type
	}
}

string Hitboxes::smallestCharacter() {
	int smallest = hb.at(0).chars[0].getSize(); //Set smallest character to the first character
	string smallestchar = hb.at(0).chars[0].name;

	for (int i = 0; i < hb.size(); i++) //Iterate through type map
		for (int j = 0; j < hb.at(i).chars.size(); j++) //Subsequently iterate through type's character vector
			if (hb.at(i).chars[j].getSize() < smallest) { //If the current character is smaller, make them the new smallest
				smallest = hb.at(i).chars[j].getSize();
				smallestchar = hb.at(i).chars[j].name;
			}

	return smallestchar;
}

string Hitboxes::smallestType() {
	int smallestsize = hb.at(0).getSizeType(); //Set smallest type to the first type
	string smallesttype = hb.at(0).type;

	for (int i = 0; i < hb.size(); i++) //Iterate through type map
		if (hb.at(i).getSizeType() < smallestsize) { //If the current type's overall size is smaller, make them the new smallest
			smallestsize = hb.at(i).getSizeType();
			smallesttype = hb.at(i).type;
		}

	return smallesttype;
}