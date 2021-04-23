#include <sstream>  // for stringstream
#include <iostream> // for cout

using namespace std;

int main() {
	ostringstream oss("Ito En Green Tea ");
	oss << 16.9 << " Ounce ";
	oss << "(Pack of " << 12 << ")";

	istringstream iss(oss.str());
	double amount;
	string unit;
	iss >> amount >> unit;
	// cout << iss.str() << endl;

	cout << "amount: " << amount/2 << endl;
	cout << "unit: " << unit << endl;

	return 0;
}
