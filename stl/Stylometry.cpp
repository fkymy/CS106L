#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>
#include <cmath>

using std::cout;    using std::cin;
using std::endl;    using std::string;
using std::vector;  using std::ifstream;

vector<string> createFeatureVec() {
    return {"a", "about", "above", "after", "again", "against", "all",
            "am", "an", "and", "any", "are", "aren't", "as", "at", "be",
            "because", "been", "before", "being", "below", "between", "both",
            "but", "by", "can't", "cannot", "could", "couldn't", "did", "didn't",
            "do", "does", "doesn't", "doing", "don't", "down", "during", "each",
            "few", "for", "from", "further", "had", "hadn't", "has", "hasn't",
            "have", "haven't", "having", "he", "he'd", "he'll", "he's", "her",
            "here", "here's", "hers", "herself", "him", "himself", "his", "how",
            "how's", "i", "i'd", "i'll", "i'm", "i've", "if", "in", "into", "is",
            "isn't", "it", "it's", "its", "itself", "let's", "me", "more", "most",
            "mustn't", "my", "myself", "no", "nor", "not", "of", "off", "on", "once",
            "only", "or", "other", "ought", "our", "ours", "ourselves", "out", "over",
            "own", "same", "shan't", "she", "she'd", "she'll", "she's", "should", "shouldn't",
            "so", "some", "such", "than", "that", "that's", "the", "their", "theirs", "them",
            "themselves", "then", "there", "there's", "these", "they", "they'd", "they'll", "they're",
            "they've", "this", "those", "through", "to", "too", "under", "until", "up", "very", "was",
            "wasn't", "we", "we'd", "we'll", "we're", "we've", "were", "weren't", "what", "what's", "when",
            "when's", "where", "where's", "which", "while", "who", "who's", "whom", "why", "why's", "with",
            "won't", "would", "wouldn't", "you", "you'd", "you'll", "you're", "you've", "your", "yours",
            "yourself", "yourselves", "!", "\"", "#", "$", "%", "&", "'", "(", ")", "*", "+", ",", "-", ".",
            "/", ":", ";", "<", "=", ">", "?", "@", "[", "\\", "]", "^", "_", "`", "{", "|", "}", "~"};
}

template <typename T>
void printVector(const vector<T>& v);

string fileToString(ifstream& inp);
double mag(const vector<int>& v);
int dotProduct(const vector<int>& v1, const vector<int>& v2);
int countOccurences(const string& text, const string& inpFeature);
double getSimilarity(const string& text, const string& text2, const vector<string>& featureVec);
vector<string> createFeatureVec();
vector<int> createDocVec(const string& text, const vector<string>& featureVec);

int main() {
	// create vector of function words
	vector<string> featureVec = createFeatureVec();

	// get text of the files and store in string,
	ifstream file1("madison.txt");
	ifstream file2("jj.txt");
	ifstream file3("hamilton.txt");
	ifstream file4("unknown.txt");

	string f_mad = fileToString(file1);
	string f_jj = fileToString(file2);
	string f_ham = fileToString(file3);
	string f_unk = fileToString(file4);

	// compute similarity and output result
	cout << "Similarity - madison <-> unknown:  " << getSimilarity(f_mad, f_unk, featureVec) << endl;
	cout << "Similarity - jj <-> unknown:       " << getSimilarity(f_jj, f_unk, featureVec) << endl;
	cout << "Similarity - hamilton <-> unknown: " << getSimilarity(f_ham, f_unk, featureVec) << endl;

	return 0;
}

template <typename T>
void printVector(const vector<T>& v) {
	cout << "{";
	if (!v.empty()) {
		for (size_t i = 0; i < v.size() - 1; ++i) {
			cout << v[i] << ", ";
		}
		cout << v[v.size() - 1];
	}
	cout << "}" << endl;
}

string fileToString(ifstream& inp) {
	string ret;
	string line;
	while (std::getline(inp, line)) {
		std::transform(line.begin(), line.end(), line.begin(), ::tolower);
		ret += line + " ";
	}
	return ret;
}

double getSimilarity(const string& text1, const string& text2, const vector<string>& featureVec) {
	// create doc vector for text 1
	vector<int> docVec1 = createDocVec(text1, featureVec);

	// create doc vector for text 2
	vector<int> docVec2 = createDocVec(text2, featureVec);

	// calculate dot product
	int dotProd = dotProduct(docVec1, docVec2);

	// return similarity
	return (dotProd == 0) ? 0 : dotProd/(mag(docVec1)*mag(docVec2));
}

int dotProduct(const vector<int>& v1, const vector<int>& v2) {
	if (v1.size() != v2.size()) {
		cout << "Size mismatch" << endl;
		return -1;
	}
	return std::inner_product(v1.begin(), v1.end(), v2.begin(), 0);
}

double mag(const vector<int>& v) {
	return std::sqrt(dotProduct(v, v));
}

vector<int> createDocVec(const string& text, const vector<string>& featureVec) {
	vector<int> result;
	for (const auto& feature : featureVec) {
		result.push_back(countOccurences(text, feature));
	}
	return result;
}

int countOccurences(const string& text, const string& inpFeature) {
	string feature = " " + inpFeature + " ";
	auto curr = text.begin();
	auto end = text.end();

	int counter = 0;
	while (curr != end) {
		// find occurence of feature in the range [start, end)
		auto found = std::search(curr, end, feature.begin(), feature.end());
		if (found == end) break;

		++counter;
		curr = found + 1;
	}
	return counter;
}
