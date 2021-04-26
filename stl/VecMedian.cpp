#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;    using std::endl;
using std::cin;    using std::string;
using std::vector;

using vecsz_t = std::vector<int>::size_type;
// or you can use size_t

int getInteger() {
	while(true) {
		string line;
		std::getline(cin, line);

		std::istringstream converter(line);

		int result; char remain;
		if (converter >> result && !(converter >> remain)) {
			return result;
		} else {
			cout << "Not a valid integer. Try again." << endl;
		}
	}
}

void printVector(const vector<int>& data) {
	for (vecsz_t i = 0; i < data.size(); ++i) {
		cout << data[i];
		if (i + 1 < data.size())
			cout << " ";
		else
			cout << endl;
	}
	// for(auto elem : data) {
	// 	cout << elem << " ";
	// }
	// cout << endl
}

int main() {
	const int kNumValues = 5;
	vector<int> data;
	for (size_t i = 0; i < kNumValues; ++i) {
		cout << "Enter value (" << kNumValues - i << " left): ";
		int curr = getInteger();
		data.push_back(curr);
	}

	vecsz_t size = data.size();
	if(size == 0) {
		cout << "No data entered" << endl;
		return 1;
	}

	std::sort(data.begin(), data.end());

	// Find median:
	// - if vec size is odd, return middle element
	// - if vec size is even, return average of middle two elements
	vecsz_t mid = size/2;
	double median;
	if(size % 2 == 0) {
		median = (data[mid - 1] + data[mid])/2.0;
	} else {
		median = data[mid];
	}
	printVector(data);
	cout << "The median of the data is: " << median << endl;
}
