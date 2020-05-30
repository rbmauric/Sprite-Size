#include "character.h"
#include <iostream>

Character::Character() {
	name = " ";
	type = " ";
	length = 0;
	width = 0;
}

Character::Character(string name_, string type_, int length_, int width_) {
	name = name_;
	type = type_;
	length = length_;
	width = width_;
}

void Character::printCharacter() {
	cout << "   " << name << " " << " " << length << " " << width << "  " << getSize() << endl;
}

int Character::getSize() {
	return length * width;
}