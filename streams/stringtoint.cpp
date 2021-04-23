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
	// No error checking
	istringstream iss(str);
	cout << "Before read: ";
	printStateBits(iss);
	cout << iss.str() << endl;

	int value;
	iss >> value;
	if (iss.fail()) throw domain_error("stringToInteger error");

	char remain;
	iss >> remain;
	if (!iss.fail()) throw domain_error("stringToInteger error");

	// if (iss.fail() || !iss.eof())
	// 	throw domain_error("stringToInteger Error");

	cout << "After read: ";
	printStateBits(iss);
	cout << iss.str() << endl;
	return value;
}

void printStateBits(istream& s) {
	cout << "State bits: ";
	cout << (s.good() ? "G" : "-");
	cout << (s.fail() ? "F" : "-");
	cout << (s.eof() ? "E" : "-");
	cout << (s.bad() ? "B" : "-");
	cout << endl;
}
