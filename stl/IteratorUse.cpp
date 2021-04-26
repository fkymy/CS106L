#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>

using std::string;  using std::cin;
using std::cout;    using std::endl;
using std::vector;  using std::stringstream;
using std::set;

const int elemToFind = 5;

void printVec(vector<int>& v) {
	for (size_t i = 0; i != v.size(); ++i) {
		cout << v[i];
		if (i + 1 < v.size())
			cout << " ";
		else
			cout << endl;
	}

	// for (auto elem : v) {
	// 	cout << elem << " ";
	// }
	// cout << endl;
}

int main() {
	vector<int> vec{3,1,4,1,5,9,2,6,5,3};

	cout << "Before sort" << endl;
	printVec(vec);

	std::sort(vec.begin(), vec.end());

	cout << "After sort!" << endl;
	printVec(vec);

	cout << "Finding element..." << endl;
	vector<int>::iterator it = std::find(vec.begin(), vec.end(), elemToFind);
	if (it == vec.end())
		cout << "Not found" << endl;
	else
		cout << "Found element " << elemToFind << endl;

	set<int> mySet{1, 3, 57, 137};

	set<int>::iterator iter = mySet.lower_bound(2);
	set<int>::iterator end = mySet.upper_bound(57);

	while(iter != end) {
		cout << *iter << endl;
		++iter;
	}

	// for (; iter != end; ++iter) {
	// 	cout << *iter << endl;
	// }

	return 0;
}
