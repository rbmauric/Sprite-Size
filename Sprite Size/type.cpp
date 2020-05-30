#include "type.h"
#include <iostream>

using namespace std;

Type::Type() {
	type = " ";
	index = 0;
}

Type::Type(string type_, uint64_t index_) {
	type = type_;
	index = index_;
}

void Type::insertCharacter(Character newchar) {
	for (int i = 0; i < chars.size(); i++) //See if character is already in the vector
		if (chars[i].name == newchar.name)
			return;

	chars.push_back(newchar);
}
void Type::printCharacterList() {
	int i = 0;

	while (i < chars.size()) { //Iterate through vector, and call printCharacter for each character
		chars[i].printCharacter();
		i++;
	}
}

int Type::getSizeType() {
	int size = 0;

	for (int i = 0; i < chars.size(); i++) //Iterate through character vector, add each size together
		size = size + chars[i].getSize();

	return size;
}