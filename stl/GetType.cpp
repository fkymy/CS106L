#include <iostream>
#include <sstream>
#include <vector>


using std::cout;    using std::endl;
using std::cin;     using std::string;
using std::vector;


int getInteger() {
	while(true) {
		// get a liine of input from the user
		string line;
		std::getline(cin, line);

		// use istringstream to pull data out of the stream once we put the string's content in it
		std::istringstream converter(line);

		// Try getting an int from the stream.
		int result;
		if (converter >> result) {
			// See if we can extract a char from the stream
			// If so, the user had junk after a valid int in their input
			char remaining;
			if (converter >> remaining) {
				cout << "Unexpected character. Try again." << endl;
			} else {
				return result;
			}
		} else {
			cout << "Not a valid integer. Try again." << endl;
		}
	}
}

template <typename DataType>
DataType getType() {
	while(true) {
		string line;
		getline(cin, line);

		std::istringstream converter(line);
		DataType result; char remaining;
		if (converter >> result && !(converter >> remaining)) {
			return result;
		} else {
			cout << "Not a valid input. Try again." << endl;
		}
	}
}

int main() {
	/*
	 * The type in the angle brackets specifies how the
	 * template will get instantiated.
	 */
	cout << "Enter integer: ";
	int a = getType<int>();
	cout << "Enter double: ";
	double b = getType<double>();

	cout << "Int: " << a << endl;
	cout << "Double: " << b << endl;

	return 0;
}
