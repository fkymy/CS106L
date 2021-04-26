#include <iostream>
#include <string>
#include <map>
#include <sstream>

using std::string; using std::cin;
using std::cout; using std::endl;

string getString() {
	string res;
	getline(cin, res);
	return res;
}

int main() {
	std::map<string, int> frequencyMap;

	cout << "Enter words." << endl;
	while (true) {
		cout << "> ";
		string res = getString();
		if (res.empty()) break;
		std::istringstream stream(res);
		string word;
		while (stream >> word) {
			++frequencyMap[word];
		}
	}

	cout << "Enter words to look up." << endl;
	while (true) {
		cout << "> ";
		string res = getString();
		if (res.empty()) break;
		if (frequencyMap.count(res)) {
			cout << frequencyMap[res] << " entries found." << endl;
		} else {
			cout << "None." << endl;
		}
	}

	return 0;
}
