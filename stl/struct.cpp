#include <iostream>
#include <vector>

using namespace std;

struct PriceRange {
	int min;
	int max;
};

struct Time {
	int hour;
	int minute;
};

struct Course {
	string code;
	Time startTime; Time endTime;

	vector<string> instructors;
};

int main() {
	vector<int> vec {3, 1, 4, 1, 5, 9};
	Course now {"CS106L", {15, 30}, {16, 30}, {"Wang", "Zeng"}};

	vector<int> vec1{3}; // vector = {3}
	vector<int> vec2(3); // vector = {0, 0, 0}

	return 0;
}
