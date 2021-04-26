#include <iostream>
#include <vector>

/* This function is not yours */
template <typename InputIterator, typename UnaryPredicate>
int countOccurences(InputIterator begin, InputIterator end, UnaryPredicate predicate) {
	int count = 0;
	for (auto iter = begin; iter != end; ++iter) {
		if (predicate(*iter)) ++count;
	}
	return count;
}

// template <typename DataType>
// inline bool greaterThan(DataType val, DataType limit) {
// 	return val >= limit;
// }

class GreaterThan {
	public:
		GreaterThan(int limit) : limit(limit) {}
		bool operator() (int val) {return val >= limit;}
	private:
		int limit;
};

int main() {
	std::vector<int> vec{1, 3, 5, 7, 9};
	int count;

	int limit = 3;
	GreaterThan func(limit);
	count = countOccurences(vec.begin(), vec.end(), func);
	std::cout << count << std::endl;

	return 0;
}
