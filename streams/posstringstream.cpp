#include <sstream>  // for stringstream
#include <iostream> // for cout

using namespace std;

int main() {
	ostringstream oss("Ito En Green Tea ");

	oss << 16.9;
	fpos pos = oss.tellp() + streamoff(3);
	oss.seekp(pos);
	oss << "Black";

	oss.seekp(0);
	oss << 3;
	cout << oss.str() << endl;

	return 0;
}
