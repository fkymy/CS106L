#include <iostream>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <cctype>
#include <vector>
#include <set>
using namespace std;

int main() {
    ostream_iterator<int> itr(cout, "a");

    *itr = 137;
    ++itr;

    *itr = 42;
    ++itr;

    vector<int> v(10);
    std::iota(v.begin(), v.end(), 0);
    std::copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << std::endl;

    back_insert_iterator<vector<int>> itr2(v);

    for (int i = 0; i < 10; ++i) {
        *itr2 = i;
        ++itr;
    }

    std::copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << std::endl;

    vector<int> original = v;
    vector<int> destination;

    // reverse_copy(original.begin(), original.end(),
    //              back_insert_iterator<vector<int>>(destination));
    reverse_copy(original.begin(), original.end(),
            back_inserter(destination));

    std::copy(destination.begin(), destination.end(),
              ostream_iterator<int>(cout, " "));
    cout << std::endl;

    set<int> setOne;
    set<int> setTwo;
    set<int> result;

    set_union(setOne.begin(), setOne.end(), setTwo.begin(), setTwo.end(),
              inserter(result, result.begin()));

    return 0;
}

string ConvertToLowerCase(string text) {
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    return text;
}
