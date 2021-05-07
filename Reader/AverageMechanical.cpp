#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int main() {
    ifstream input("data.txt");
    multiset<int> values;

    int currValue;
    while (input >> currValue) {
        values.insert(currValue);
    }

    double total = 0.0;
    for (multiset<int>::iterator itr = values.begin();
            itr != values.end(); ++itr) {
        total += *itr;
    }
    cout << "Average is: " << total / values.size() << endl;
    return 0;
}
