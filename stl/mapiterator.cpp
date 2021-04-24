#include <iostream>
#include <map>

using namespace std;

int main() {
	map<int, int> m;
	map<int, int>::iterator i = m.begin();
	map<int, int>::iterator end = m.end();
	while (i != end) {
		cout << (*i).first << (*i).second << endl;
		// cout << i->first << i->second << endl;
		++i;
	}
	return 0;
}
