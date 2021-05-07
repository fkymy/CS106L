#include <fstream>
#include <iostream>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    ifstream input("data.txt");
    multiset<int> values;

    int currValue;
    while (input >> currValue) {
        values.insert(currValue);
    }

    cout << "Average is: " << accumulate(values.begin(), values.end(), 0.0) / values.size() << endl;

    return 0;
}

template <typename InputIterator, typename Type> inline
Type myAccumulate(InputIterator start, InputIterator stop, Type initial) {
    while (start != stop) {
        initial += *start;
        ++start;
    }
    return initial;
}
