#include <iostream>
#include <string>

using namespace std;

bool isVowel(char ch) {
	switch (ch) {
		case 'A': case 'E': case 'I': case 'O': case 'U':
		case 'a': case 'e': case 'i': case 'o': case 'u':
			return true;
		default:
			return false;
	}
}

enum Direction {
	NORTH,
	EAST,
	SOUTH,
	WEST
};

string directionToString(Direction dir) {
	switch (dir) {
		case NORTH: return "North";
		case EAST: return "East";
		case SOUTH: return "SOUTH";
		case WEST: return "West";
		default: return "???";
	}
}
