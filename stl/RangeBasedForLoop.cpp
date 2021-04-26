#include <map>

using namespace std;

int main() {
	map<string, int> myMap;
	for(auto thing : myMap) {
		doSomething(thing.first, thing.second);
	}

	for (auto iter = myMap.begin(); iter != myMap.end(); ++iter) {
		auto thing = *iter;
		doSomething(thing.first, thing.second);
	}
}
