#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream capitals("world-capitals.txt");
	if (!capitals.is_open()) {
		cerr << "Cannot find the file world-capitals.txt" << endl;
		return -1;
	}

	string capital, country;
	while (getline(capitals, capital) && getline(capitals, country)) {
		cout << capital << " is the capital of " << country << endl;
	}

	return 0;
}
