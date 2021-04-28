#include <iostream>
#include <sstream>

using namespace std;

void messageAlertBox(string message) {
	cout << message << endl;
}

int main() {
	stringstream messageText;

	int levelNum = 2;
	messageText << "Level " << levelNum << " is out of bounds.";
	messageAlertBox(messageText.str());

	stringstream myConverter;
	int myInt;
	string myString;
	double myDouble;

	myConverter << "137 Hello 2.74";
	myconverter >> myInt >> myString >> myDouble;


	return 0;
}
