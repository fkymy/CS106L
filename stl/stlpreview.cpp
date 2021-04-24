#include <vector>
#include <cstdlib>   // for rand
#include <iostream>  // for cout
#include <algorithm> // for generate, sort, copy
#include <iterator>  // for ostream_iterator

using std::vector;
using std::cout;
using std::endl;

const int kNumInts = 20;

void doBubbleSort(vector<int>& v) {
	for (size_t i = 0; i < v.size() - 1; ++i) {
		for (size_t j = 0; j < v.size() - i - 1; ++j) {
			if (v[j] > v[j+1]) {
				int tmp = v[j];
				v[j] = v[j+1];
				v[j+1] = tmp;
			}
		}
	}
}

// int main() {
// 	vector<int> vec(kNumInts);
//
// 	for (size_t i = 0; i < vec.size(); ++i) {
// 		vec[i] = rand();
// 	}
//
// 	doBubbleSort(vec);
//
// 	for (size_t i = 0; i < vec.size(); ++i) {
// 		cout << vec[i] << endl;
// 	}
//
// 	return 0;
// }

int main() {
	vector<int> vec(kNumInts);
	std::generate(vec.begin(), vec.end(), rand);
	std::sort(vec.begin(), vec.end());
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, "\n"));
	return 0;
}
