#include <iostream>
#include <sstream>

using namespace std;

int getInteger(const string& prompt = "Enter an integer: ",
			   const string& repromt = "Illegal numeric format. Try again.\n");

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

int getInteger(const string& prompt, const string& repromt) {
	return 0;
}
