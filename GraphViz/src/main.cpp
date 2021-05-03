#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "SimpleGraph.h"

using std::cout;	using std::endl;
using std::cin;     using std::string;
using std::ifstream;

void Welcome();
void parseGraph(SimpleGraph &graph, string filename);
string fileToString(ifstream &file);
template <typename T>
void printVector(const std::vector<T> &v);

const int numSeconds = 5;

int main() {
    SimpleGraph graph;

    parseGraph(graph, "5grid");

    if (graph.nodes.size() == 0) {
        cout << "Failed to parse graph from file..." << endl;
        return -1;
    }

    InitGraphVisualizer(graph);
    DrawGraph(graph);
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

void parseGraph(SimpleGraph &graph, string filename) {
    ifstream file;

    file.open(filename.c_str());
    if (!file.is_open()) {
        cout << "Cannot file the file..." << endl;
        return;
    }

    // Read disk file to string
    string fileContent;
    fileContent = fileToString(file);

    // cout << "fileContent: " << fileContent << endl;
    // Get Number of nodes and edges
    std::istringstream converter(fileContent);

    size_t numNodes;
    converter >> numNodes;
    for (size_t i = 0; i < numNodes; ++i) {
        Node node;
        node.x = (double)i;
        node.y = (double)i;
        graph.nodes.push_back(node);
    }

    size_t start, end;
    while (converter >> start >> end) {
        Edge edge;
        edge.start = start;
        edge.end = end;
        graph.edges.push_back(edge);
    }
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

string fileToString(ifstream &file) {
    string ret;
    string line;
    while (std::getline(file, line)) {
        ret += line + " ";
    }
    return ret;
}

template <typename T>
void printVector(const std::vector<T> &v) {
    cout << "{";
    if (!v.empty()) {
        for (size_t i = 0; i < v.size() - 1; ++i) {
            cout << v[i] << ", ";
        }
        cout << v[v.size() - 1];
    }
    cout << "}" << endl;

}

int getSeconds() {
    cout << "Enter seconds: ";
    int seconds;
    cin >> seconds;
    return seconds;
}
