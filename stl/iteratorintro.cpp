#include <vector>

using std::vector;

int numOccurences(vector<int>& cont, int elemToCount) {
	int counter = 0;
	vector<int>::iterator iter;
	for(iter = cont.begin(); iter != cont.end(); ++iter) {
		if(*iter == elemToCount)
			++counter;
	}
	return counter;
}
