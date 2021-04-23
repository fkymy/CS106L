#include <iostream>
#include <sstream>

using namespace std;

int stringToInteger(const string& str);
void printStateBits(istream& s);

int main(int argc, char *argv[])
{
	if (argc != 2) {
		cout << "usage: arg1" << endl;
		return 1;
	}

	int val = stringToInteger(argv[1]);
	cout << "You entered: " << val << endl;
	cout << "Half of that is: " << val/2 << endl;
	return 0;
}

int stringToInteger(const string& str) {
	// How would you write this?
}

void printStateBits(istream& s) {
	cout << "State bits: ";
	cout << (s.good() ? "G" : "-");
	cout << (s.fail() ? "F" : "-");
	cout << (s.eof() ? "E" : "-");
	cout << (s.bad() ? "B" : "-");
	cout << endl;
}
