#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

void drawTriangle1(int h, char c) {
	// when h is 1, w is 1, pad is 9 / 2 = 4
	// when h is 2, w is 3, p = (w - x) / 2
	// when h is 3, w is 5
	// when h is 4, w is 7
	// when h is 5, w is 9 9 - 9

	int w = h * 2 - 1;
	for (int i = 0; i < h; ++i) {
		int fill = (i + 1) * 2 - 1;
		cout << setw((w - fill) / 2) << "";
		for (int j = 0; j < fill; ++j) {
			cout << c;
		}
		cout << endl;
	}
}

void drawTriangle2(int height, char c) {
	int width = height * 2 - 1;
	for (int i = 1; i <= height; ++i) {
		int fill = i * 2 - 1;
		cout << setfill(' ') << setw((width - fill) / 2) << "";
		cout << setfill(c) << setw(i * 2 - 1) << "" << endl;
	}
}

int main() {
	cout << "Enter height: ";

	int height;
	cin >> height;

	drawTriangle1(height, '#');
	cout << endl;
	drawTriangle2(height, '@');

	return 0;
}
