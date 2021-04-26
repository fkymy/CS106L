#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <algorithm>

using std::cout;    using std::endl;
using std::cin;     using std::string;
using std::vector;

int numOccurences(vector<int>::iterator begin, vector<int>::iterator end, int elemToCount) {
	int counter = 0;
	vector<int>::iterator iter;
	for(iter = begin; iter != end; ++iter) {
		if (*iter == elemToCount)
			++counter;
	}
	return counter;
}

template <typename InputIter, typename DataType>
int numOccurencesGen(InputIter begin, InputIter end, DataType elemToCount) {
	int counter = 0;
	InputIter iter;
	for(iter = begin; iter != end; ++iter) {
		if (*iter == elemToCount)
			++counter;
	}
	return counter;

	// ========================

	/* Alternative version */
	//    int counter = 0;
	//    while(start != end) {
	//        if(*start == elemToCount) {
	//            ++counter;
	//        }
	//        ++start;
	//    }
	//    return counter;

	// ========================

	/* Second alternative version */
	//    int counter = 0;
	//    for(; start != end; ++start) {
	//        if(*start == elemToCount)
	//            ++counter;
	//    }
	//    return counter;
}


int main() {

	std::vector<int> v {3, 1, 4, 1, 5, 9, 3};
	std::list<int> l {2, 7 , 1, 8, 2, 8 , 2};

	cout << "vec count: " << numOccurencesGen(v.begin(), v.end(), 1) << endl;
	cout << "lib vec count: " << std::count(v.begin(), v.end(), 1)   << endl;

    cout << "list count : "     << numOccurencesGen(l.begin() , l.end(), 1) << endl;
    cout << "lib list count: "  << std::count(l.begin(), l.end(), 1)        << endl;

	return 0;
}
