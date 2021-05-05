#include <iostream>
#include <vector>
#include <set>

using namespace std;

const size_t kNumIterations = 10000;

int DieRoll() {
	return (rand() % 365) + 1;
}

size_t RunProcessVector() {
	vector<int> generated;

	while (true) {
		int nextValue = DieRoll();
		for (size_t k = 0; k < generated.size(); ++k)
			if (nextValue == generated[k])
				return generated.size() + 1;
		generated.push_back(nextValue);
	}
}

size_t RunProcessSet() {
	set<int> generated;

	while (true) {
		int nextValue = DieRoll();
		if (generated.count(nextValue))
			return generated.size() + 1;
		generated.insert(nextValue);
	}
}

int main() {
	srand(static_cast<unsigned>(time(NULL)));

	size_t total = 0;

	for (size_t k = 0; k < kNumIterations; ++k) {
		total += RunProcessSet();
	}

	cout << "Average number of steps: "
		<< double(total) / kNumIterations << endl;

	return 0;
}
