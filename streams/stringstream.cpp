#include <sstream>  // for stringstream
#include <iostream> // for cout

using namespace std;

int main() {
	ostringstream oss("Ito En Green Tea ", ostringstream::ate);
	cout << oss.str() << endl;

	oss << 16.9 << " Ounce "; // this is c string
	// oss << 16.9 << string(" Ounce ");
	cout << oss.str() << endl;

	oss << "(Pack of " << 12 << ")";
	cout << oss.str() << endl;
	return 0;
}
