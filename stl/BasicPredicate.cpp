#include <iostream>
#include <vector>

bool isEqualTo3(int val) {
	return val == 3;
}

bool isLessThan5(int val) {
	return val < 5;
}

bool isDivisibleBy(int divident, int divisor) {
	return divident % divisor == 0;
}

template <typename InputIterator, typename UnaryPredicate>
int countOccurences(InputIterator begin, InputIterator end, UnaryPredicate predicate) {
	int count = 0;
	for (auto iter = begin; iter != end; ++iter) {
		if (predicate(*iter)) ++count;
	}
	return count;
}

template <typename DataType>
inline bool greaterThan(DataType val, DataType limit) {
	return val >= limit;
}

int main() {
	std::vector<int> vec{1, 3, 5, 7, 9};
	int count;

	count = countOccurences(vec.begin(), vec.end(), isLessThan5);
	std::cout << count << std::endl;

	int limit = 3;
	count = countOccurences(vec.begin(), vec.end(), greaterThan);
	std::cout << count << std::endl;

	return 0;
}
