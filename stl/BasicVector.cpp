#include <vector>
#include <string>
#include <iostream>

using std::vector;  using std::string;
using std::cout;    using std::endl;

void printVec(const vector<string>& v) {
	cout << "{";
	for(auto elem : v) {
		cout << elem << " ";
	}
	cout << "}" << endl;
}

int main() {
	vector<string> names;
	names.push_back("Anna");
	names.push_back("Avery");
	printVec(names);

	// out of bounds
	// cout << names.at(3) << endl;
	cout << names[3] << endl;
	cout << "Hello! I've reached this point" << endl;
	// names.at(0) = "Karel";
	// printVec(names);

	return 0;
}
