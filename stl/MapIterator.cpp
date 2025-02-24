#include <iostream>
#include <sstream>
#include <string>
#include <map>

using std::string;  using std::cin;
using std::cout;    using std::endl;
using std::map;     using std::stringstream;

map<string, int> readUserWords();
string GetLine();

int main() {
	/* Write a program to:
	 * - read words from users and keep track of frequency
	 * - print elements of vector
	 */

	map<string, int> freqMap;
	freqMap = readUserWords();

	map<string, int>::iterator iter = freqMap.begin();
	map<string, int>::iterator end = freqMap.end();

	while(iter != end) {
		std::pair<string, int> p = *iter;
		cout << p.first << ", " << p.second << endl;
		// cout << (*iter).first << (*iter).second << endl;
		++iter;
	}

	return 0;
}

string GetLine() {
	string line;
	std::getline(cin, line);
	return line;
}

map<string, int> readUserWords() {
	cout << "Enter words: " << endl;
	map<string, int> m;
	while(true) {
		string res = GetLine();
		if (res.empty()) {
			return m;
		}

		stringstream stream(res);
		string word;
		while(stream >> word) {
			m[word]++;
		}
	}
}
