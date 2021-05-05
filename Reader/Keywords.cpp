#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

void OpenUserFile(ifstream& fileStream);

string GetFileContents(ifstream& file);

map<string, size_t> GenerateKeywordReport(string contents);

int main() {
    ifstream input;
    OpenUserFile(input);

    map<string, size_t> report = GenerateKeywordReport(GetFileContents(input));

    for (map<string, size_t>::iterator itr = report.begin();
         itr != report.end(); ++itr) {
        cout << "Keyword " << itr->first << " occurred "
            << itr->second << " times." << endl;
    }
}
