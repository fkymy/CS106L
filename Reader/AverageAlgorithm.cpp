#include <fstream>
#include <iostream>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    ifstream input("data.txt");
    multiset<int> values;

    copy(istream_iterator<int>(input), istream_iterator<int>(),
         inserter(values, values.begin()));

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
