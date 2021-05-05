#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <deque>
#include <algorithm>
#include <iterator>

struct Course {
	std::string name;
	double rating;
};

// This function allows you to print a Course struct to any stream
// Usage: std::cout << c << std::endl;
// We'll cover how to overload operators in about a week.
std::ostream& operator<<(std::ostream& os, const Course & c) {
	os << std::setw(15) << std::setfill(' ') << c.name << "    " << c.rating;
	return os;
}

template <typename InputIt, typename UnaryPred>
int countOccurences(InputIt begin, InputIt end, UnaryPred pred) {
	int count = 0;
	for (auto iter = begin; iter != end; ++iter) {
		if (pred(*iter)) ++count;
	}
	return count;
}

bool isLessThan5(int val) {
	return val < 5;
}

bool isLessThanLimit(int val, int limit) {
	return val < limit;
}

std::vector<Course> readCourses() {
	std::vector<Course> v = {
		{"CS106A", 4.337},
		{"CS106B", 4.4025},
		{"CS107", 4.6912},
		{"Math 51", 3.6119}
	};
	// Deprecated, use c++11
	std::random_shuffle(v.begin(), v.end());
	return v;
}

std::vector<double> readNumbers() {
	std::vector<double> numbers;
	std::generate_n(std::back_inserter(numbers), 500, std::rand);
	return numbers;
}

int main() {
	std::vector<int> phoneNumber{5, 5, 5, 8, 2, 6, 5, 5, 3, 5};

	int times1 = countOccurences(phoneNumber.begin() + phoneNumber.size()/2,
								 phoneNumber.end(), isLessThan5);
	std::cout << "the second half of phone number contains " << times1
			  << " elements of 5" << std::endl;

	int limit = 5;
	auto isLessThanLimit = [limit](int val) -> bool {
		return val < limit;
	};

	int times2 = countOccurences(phoneNumber.begin() + phoneNumber.size()/2,
								 phoneNumber.end(), isLessThanLimit);
	std::cout << "the second half of phone number contains " << times2
			  << " elements that are less than 5" << std::endl;

	auto courses = readCourses();
	auto numbers = readNumbers();

	// Algorithms we will explore:
	// - std::sort
	// - std::nth_element
	// - std::stable_partition
	// - std::copy_if
	// - std::remove_if

	auto compareRating = [](const Course& c1, const Course& c2) {
		return c1.rating < c2.rating;
	};

	// O(N log N) sort
	std::sort(numbers.begin(), numbers.end());
	std::sort(courses.begin(), courses.end(), compareRating);

	// O(N) sorts so nth_element is in correct position
	// all elements smaller to left, larger to right
	// Course median = *std::nth_element(courses.begin(), courses.end(), courses.size()/2, compareRating);

	auto median2 = courses[courses.size()/2];

	std::copy(courses.begin(), courses.end(), std::ostream_iterator<Course>(std::cout, "\n"));


	std::string dep = "CS";
	auto isDep = [dep](const Course& course) {
		return course.name.size() >= dep.size() &&
				course.name.substr(0, dep.size()) == dep;
	};

	std::stable_partition(courses.begin(), courses.end(), isDep);

	std::vector<Course> csCourses;
	std::copy_if(csCourses.begin(), csCourses.end(),
				 back_inserter(csCourses), isDep);
}

