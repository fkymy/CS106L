#include <iostream>
#include <string>
#include <set>

using std::cout; using std::endl;
using std::string; using std::set;

int main() {
	set<string> groceryList;
	groceryList.insert("milk");
	groceryList.insert("eggs");
	groceryList.insert("PROTEIN!");
	groceryList.insert("PROTEIN!");

	if (groceryList.count("milk")) {
		cout << "We are getting milk!" << endl;
	} else {
		cout << "Well, no use crying..." << endl;
	}

	if (groceryList.count("butter")) {
		cout << "We are getting butter!" << endl;
	} else {
		cout << "You had butter not..." << endl;
	}

	groceryList.erase("eggs");
	if (groceryList.count("eggs")) {
		cout << "We are getting eggs" << endl;
	} else {
		cout << "Rotten choice..." << endl;
	}

	return 0;
}
