#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include "SimpleGraph.h"

using std::cout;	using std::endl;
using std::cin;     using std::string;
using std::ifstream; using std::cerr;

void Welcome();
void parse(SimpleGraph &graph, string filename);
void iterativelyDraw(SimpleGraph &graph, double numSeconds);
void computeForce(SimpleGraph &graph);

string fileToString(ifstream &file);
template <typename T>
void printVector(const std::vector<T> &v);

const double kPi = 3.14159265358979323;
const double numSeconds = 15;
const double kRepel = 0.001;
const double kAttract = 0.001;

int main() {
    SimpleGraph graph;

    parse(graph, "5grid");

    if (graph.nodes.size() == 0) {
        cout << "Failed to parse graph from file..." << endl;
        return -1;
    }

    InitGraphVisualizer(graph);
    iterativelyDraw(graph, numSeconds);

    return 0;
}

void Welcome() {
    cout << "Welcome to CS106L GraphViz!" << endl;
    cout << "This program uses a force-directed graph layout algorithm" << endl;
    cout << "to render sleek, snazzy pictures of various graphs." << endl;
    cout << endl;
}

void parse(SimpleGraph &graph, string filename) {
    ifstream file;

    file.open(filename.c_str());
    if (!file.is_open()) {
        cerr << "Cannot file the file..." << endl;
        return ;
    }

    size_t numNodes;
    file >> numNodes;
    for (size_t i = 0; i < numNodes; ++i) {
        Node node;
        // Evenly space out on unit circle
        node.x = cos((2 * kPi * i) / numNodes);
        node.y = sin((2 * kPi * i) / numNodes);
        graph.nodes.push_back(node);
    }

    while (true) {
        size_t start, end;
        file >> start >> end;
        if (file.fail()) break;

        Edge edge;
        edge.start = start;
        edge.end = end;
        graph.edges.push_back(edge);
    }
}

void iterativelyDraw(SimpleGraph &graph, double numSeconds) {
    time_t startTime;
    double elapsedTime;

    startTime = time(NULL);
    elapsedTime = difftime(time(NULL), startTime);
    while (elapsedTime < numSeconds) {
        computeForce(graph);
        DrawGraph(graph);
        elapsedTime = difftime(time(NULL), startTime);
    }
    cout << "DONE!" << endl;
}

void computeForce(SimpleGraph &graph) {
    std::vector<double> deltaX(graph.nodes.size());
    std::vector<double> deltaY(graph.nodes.size());

    for (size_t i = 0; i < graph.nodes.size() - 1; ++i) {
        for (size_t j = i + 1; j < graph.nodes.size(); ++j) {
            double xDiff = graph.nodes[j].x - graph.nodes[i].x;
            double yDiff = graph.nodes[j].y - graph.nodes[i].y;
            double fRepel = kRepel / sqrt(yDiff * yDiff + xDiff * xDiff);
            double theta = atan2(yDiff, xDiff);
            deltaX[i] -= fRepel * cos(theta);
            deltaY[i] -= fRepel * sin(theta);
            deltaX[j] += fRepel * cos(theta);
            deltaY[j] += fRepel * sin(theta);
        }
    }
    for (size_t i = 0; i < graph.edges.size(); ++i) {
        size_t startIndex = graph.edges[i].start;
        size_t endIndex = graph.edges[i].end;
        Node start = graph.nodes[startIndex];
        Node end = graph.nodes[endIndex];
        double xDiff = end.x - start.x;
        double yDiff = end.y - start.y;
        double fAttract = kAttract * (yDiff * yDiff + xDiff * xDiff);
        double theta = atan2(yDiff, xDiff);
        deltaX[startIndex] += fAttract * cos(theta);
        deltaY[startIndex] += fAttract * sin(theta);
        deltaX[endIndex] -= fAttract * cos(theta);
        deltaY[endIndex] -= fAttract * sin(theta);
    }
    for (size_t i = 0; i < graph.nodes.size(); ++i) {
        graph.nodes[i].x += deltaX[i];
        graph.nodes[i].y += deltaY[i];
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
