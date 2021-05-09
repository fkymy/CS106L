#include <iostream>     // for cout, cin
#include <fstream>      // for ifstream
#include <sstream>      // for stringstream
#include <unordered_set>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
#include "wikiscraper.h"

using std::cout;            using std::endl;
using std::ifstream;        using std::stringstream;
using std::string;          using std::vector;
using std::priority_queue;  using std::unordered_map;
using std::unordered_set;   using std::cin;

/*
 * This is the function you will be implementing. It takes
 * two string representing the names of a start_page and
 * end_page and is supposed to return a ladder, represented
 * as a vector<string>, of links that can be followed from
 * start_page to get to the end_page.
 *
 * For the purposes of this algorithm, the "name" of a Wikipedia
 * page is what shows at the end of the URL when you visit that page
 * in your web browser. For ex. the name of the Stanford University
 * Wikipedia page is "Stanford_University" since the URL that shows
 * in your browser when you visit this page is:
 *
 *       https://en.wikipedia.org/wiki/Stanford_University
 */
vector<string> findWikiLadder(const string& start_page, const string& end_page) {
    WikiScraper scraper;
    std::unordered_set<string> target_set;

    target_set = scraper.getLinkSet(end_page);

    // Comparison function for priority queue
    auto cmpFn = [&scraper, &target_set](const vector<string>& ladder1, const vector<string>& ladder2) {
        string page1 = ladder1.back();
        string page2 = ladder2.back();

        std::unordered_set<string> set1 = scraper.getLinkSet(page1);
        std::unordered_set<string> set2 = scraper.getLinkSet(page2);

//        int num1 = 0;
//        int num2 = 0;
//        for (std::unordered_set<string>::iterator itr = set1.begin(); itr != set1.end(); ++itr) {
//            if (target_set.count(*itr))
//                ++num1;
//        }
//        for (std::unordered_set<string>::iterator itr = set2.begin(); itr != set2.end(); ++itr) {
//            if (target_set.count(*itr))
//                ++num2;
//        }
        vector<string> intersect1, intersect2;
        std::set_intersection(set1.begin(), set1.end(), target_set.begin(), target_set.end(),
                              std::back_inserter(intersect1));
        std::set_intersection(set2.begin(), set2.end(), target_set.begin(), target_set.end(),
                              std::back_inserter(intersect2));
        return intersect1.size() < intersect2.size();
    };

    std::priority_queue<vector<string>, vector<vector<string>>,
            decltype(cmpFn)> ladderQueue(cmpFn);

    vector<string> startLadder{ start_page };
    std::set<string> visited;
    ladderQueue.push(startLadder);

    int count = 0;
    while (!ladderQueue.empty()) {
        cout << count << " -------------------------" << endl;
        vector<string> currLadder = ladderQueue.top();
        ladderQueue.pop();
        cout << "Visiting Partial Ladder: ";
        std::copy(currLadder.begin(), currLadder.end(), std::ostream_iterator<string>(cout, " "));
        cout << endl;

        string currPage = currLadder.back();

        std::unordered_set<string> currSet = scraper.getLinkSet(currPage);
        if (currSet.count(end_page)) {
            cout << "Found end_page!" << endl;
            currLadder.push_back(end_page);
            return currLadder;
        }

        for (std::unordered_set<string>::iterator itr = currSet.begin(); itr != currSet.end(); ++itr) {
            if (!visited.count(*itr)) {
                vector<string> newLadder = currLadder;
                newLadder.push_back(*itr);
                ladderQueue.push(newLadder);
                visited.insert(*itr);

                cout << "Added Partial Ladder: ";
                std::copy(newLadder.begin(), newLadder.end(), std::ostream_iterator<string>(cout, " "));
                cout << endl;
            }
        }
        ++count;
    }

    return {};
}

int main() {
    /* Container to store the found ladders in */
    vector<vector<string>> outputLadders;

    cout << "Enter a file name: ";
    string filename;
    getline(cin, filename);

    // TODO: Create a filestream from the filename.
    //       For each pair {start_page, end_page} in the input file,
    //       retrieve the result of findWikiLadder(start_page, end_page)
    //       and append that vector to outputLadders.

    // Write code here
    std::ifstream input(filename);
    int numPairs;

    input >> numPairs;

    string start, end;
    while (true) {
        input >> start >> end;
        if (input.fail()) break;

        vector<string> ladder;
        ladder = findWikiLadder(start, end);
        outputLadders.push_back(ladder);
    }

    /*
     * Print out all ladders in outputLadders.
     * We've already implemented this for you!
     */
    for (auto& ladder : outputLadders) {
        if(ladder.empty()) {
            cout << "No ladder found!" << endl;
        } else {
            cout << "Ladder found:" << endl;
            cout << "\t" << "{";

            std::copy(ladder.begin(), ladder.end() - 1,
                      std::ostream_iterator<string>(cout, ", "));
            /*
             * The above is an alternate way to print to cout using the
             * STL algorithms library and iterators. This is equivalent to:
             *    for (size_t i = 0; i < ladder.size() - 1; ++i) {
             *        cout << ladder[i] << ", ";
             *    }
             */
            cout << ladder.back() << "}" << endl;
        }
    }
    return 0;
}




