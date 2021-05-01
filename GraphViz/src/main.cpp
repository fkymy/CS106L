#include <iostream>
#include <string>
#include <fstream>
#include "SimpleGraph.h"

using std::cout;	using std::endl;
using std::cin;     using std::string;
using std::ifstream;

void Welcome();

// Main method
int main() {
    Welcome();
    // Prompt user for file name
    // - should exist
    // - if not try again
    // Prompt user for number of seconds to run the algorithm
    // - should be positive, int

    cout << "Enter filename: ";
    string filename;
    std::getline(cin, filename);
    cout << "Good job! you entered " << filename << endl;

    ifstream file(filename);


    return 0;
}

/* Prints a message to the console welcoming the user and
 * describing the program. */
void Welcome() {
    cout << "Welcome to CS106L GraphViz!" << endl;
    cout << "This program uses a force-directed graph layout algorithm" << endl;
    cout << "to render sleek, snazzy pictures of various graphs." << endl;
    cout << endl;
}

string getFilename() {
    while (true) {
        cout << "Enter filename: ";
        string filename;
        std::getline(cin, filename, '\n');
        if (!filename.empty()) {
            return filename;
        } else {
            cout << "filename is empty" << endl;
        }
    }
}

int getSeconds() {
    cout << "Enter seconds: ";
    int seconds;
    cin >> seconds;
    return seconds;
}
