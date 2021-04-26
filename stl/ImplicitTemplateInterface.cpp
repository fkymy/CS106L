#include <iostream>
#include <vector>

template <typename InputIterator, typename DataType>
int countOccurences(InputIterator begin, InputIterator end, DataType val) {
	int count = 0;
	for (auto iter = begin; iter != end; ++iter) {
		if (*iter == val) ++count;
	}
	return count;
}

template <typename Collection, typename DataType>
int countOccurences2(const Collection<DataType>& list, DataType val) {
	int count = 0;
	for (size_t i = 0; i < list.size(); ++i) {
		if (list[i] == val) ++count;
	}
	return count;
}

int main() {
	std::vector<int> v{1,2,3,4,3,2,1};
	int count;

	count = countOccurences(v.begin(), v.end(), 1);
	std::cout << count << std::endl;
	return 0;
}
