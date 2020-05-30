#include <iostream>
#include <string>
#include "Hitboxes.h"

using namespace std;

int main()
{	// Test with first text file
	{
		Hitboxes hb(string("apex.txt"));

		cout << "TESTING FIRST FILE: apex.txt" << endl;
		hb.printHitboxes();

		if (hb.smallestCharacter() == "Wraith")
			cout << "smallestCharacter: Wraith" << endl;
		else
			cout << "smallestCharacter: Result did not match expected answer: Wraith" << endl;
		if (hb.smallestType() == "Scout")
			cout << "smallestType: Scout" << endl;
		else
			cout << "smallestType: Result did not match expected answer: Scout" << endl;

		cout << "\n\n";
	}

	// Test with second text file 
	{
		Hitboxes hb(string("mario.txt"));

		cout << "TESTING SECOND FILE: mario.txt" << endl;
		hb.printHitboxes();

		if (hb.smallestCharacter() == "Toad")
			cout << "smallestCharacter: Toad" << endl;
		else
			cout << "smallestCharacter: Result did not match expected answer: Toad" << endl;
		if (hb.smallestType() == "Monster")
			cout << "smallestType: Monster" << endl;
		else
			cout << "smallestType: Result did not match expected answer: Monster" << endl;

		cout << "\n\n";
	}

	return 0;
}