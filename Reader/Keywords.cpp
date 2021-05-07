#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
using namespace std;

string GetLine();
void OpenUserFile(ifstream& fileStream);

string GetFileContents(ifstream& file);

map<string, size_t> GenerateKeywordReport(string contents);

int main() {
    ifstream input;
    OpenUserFile(input);

    map<string, size_t> report = GenerateKeywordReport(GetFileContents(input));

    for (map<string, size_t>::iterator itr = report.begin();
         itr != report.end(); ++itr) {
        cout << "Keyword " << itr->first << " occurred " << itr->second
             << " times." << endl;
    }
}

string GetLine() {
    string line;
    getline(cin, line);
    return line;
}

void OpenUserFile(ifstream& input) {
    while (true) {
        cout << "Enter filename: ";
        string filename = GetLine();

        input.open(filename.c_str());
        if (input.is_open()) return;

        cout << "Sorry, I can't find the file " << filename << endl;
        input.clear();
    }
}

string GetFileContents(ifstream& file) {
    string result;
    string line;

    while (file >> line) {
        result += line + "\n";
    }

    return result;
}

set<string> LoadKeywords() {
    ifstream input("keywords.txt");
    set<string> result;

    string keyword;
    while (input >> keyword) {
        result.insert(keyword);
    }

    return result;
}

void PreprocessString(string& text) {
    for (size_t k = 0; k < text.size(); ++k)
        if (ispunct(text[k]) && text[k] != '_') text[k] = ' ';
}

map<string, size_t> GenerateKeywordReport(string contents) {
    set<string> keywords = LoadKeywords();

    PreprocessString(contents);

    stringstream tokenizer;
    tokenizer << contents;

    map<string, size_t> result;

    string word;
    while (tokenizer >> word) {
        if (keywords.count(word)) ++result[word];
    }

    return result;
}
