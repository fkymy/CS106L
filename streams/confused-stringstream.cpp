#include <sstream>  // for stringstream
#include <iostream> // for cout

using namespace std;

int main() {
	ostringstream oss("Ito En Green Tea ");
	cout << oss.str() << endl;

	oss << 16.9 << " Ounce ";
	cout << oss.str() << endl;

	oss << "(Pack of " << 12 << ")";
	cout << oss.str() << endl;
	return 0;
}
