#include <iostream>
#include <fstream>

using namespace std;

const int NUM_LINES = 4;
const int NUM_COLUMNS = 3;
const int COLUMN_WIDTH = 20;

void printTableHeader() {
	for(int column = 0; column < NUM_COLUMNS; ++column) {
		cout << setfill('-') << setw(COLUMN_WIDTH) << "" << "-+-";
	}
	cout << setw(COLUMN_WIDTH) << "" << setfill(' ') << endl;
}

void printTableBody() {
	ifstream input("table-data.txt");
	if (!input.is_open()) {
		cerr << "Cannot find the file table-data.txt" << endl;
		return ;
	}

	int rowNumber = 0;
	while(true) {
		int intValue;
		double doubleValue;
		input >> intValue >> doubleValue;

		if(input.fail()) break;

		cout << setw(COLUMN_WIDTH) << (rowNumber + 1) << " | ";
		cout << setw(COLUMN_WIDTH) << intValue << " | ";
		cout << setw(COLUMN_WIDTH) << doubleValue << endl;
		rowNumber++;
	}
}

int main() {
	printTableHeader();
	printTableBody();

	return 0;
}
