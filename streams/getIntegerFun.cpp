#include <iostream>
#include <sstream>

using namespace std;

int getInteger(const string& prompt = "Enter an integer: ",
			   const string& reprompt = "Illegal numeric format. Try again.\n");

int main() {
	cout << "What is your name? ";
	string name;
	// getline(cin, name);
	cin >> name; // You extract a whitespace token

	cout << "What is your age? ";
	int age;
	cin >> age;

	cout << "Where are you from? ";
	string home;
	cin >> home;

	// Streams go wrong! Try entering your full name
	cout << "Hello " << name << "(age " << age << " from " << home << ")" << endl;
	return 0;
}

int getInteger(const string& prompt, const string& reprompt) {

	while (true) {
		cout << prompt;
		string line;
		if (!getline(cin, line))
			throw domain_error("...");

		istringstream iss(line);
		int val; char remain;
		if (iss >> val && !(iss >> remain))
			return val;
		// No need to do this (google way) because we are creating new iss every loop
		// iss.clear();
		// iss.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << reprompt << endl;
	}
	return 0;
}
