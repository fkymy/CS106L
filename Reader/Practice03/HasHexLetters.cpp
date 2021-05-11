#include <iostream>
#include <sstream>

using namespace std;

bool hasHexLetters(int value) {
	stringstream converter;
	converter << hex << value;

	int dummy;
	converter >> dec >> dummy;

	if (converter.fail()) return true;

	char leftover;
	converter >> leftover;

	return !converter.fail();
}
