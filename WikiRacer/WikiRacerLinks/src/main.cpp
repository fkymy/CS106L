#include <iostream>
#include <fstream>
#include <unordered_set>
#include <iterator>

using std::cout;            using std::endl;
using std::string;          using std::unordered_set;

/*
 * Note that you have to pass in the file as a single string
 * into the findWikiLinks function!
 * So we have to turn the passed-in file into a single string...
 * does that sound familiar at all?
 */
unordered_set<string> findWikiLinks(const string& page_html) {
    // TODO: delete this return statement and implement the
    //       function!
    unordered_set<string> links;

    string wikiPath = "<a href=\"/wiki/";

    string::const_iterator curr = page_html.begin();
    string::const_iterator end = page_html.end();

    while (curr != end) {
        // find occurance of wikiPath in the range [start, end)
        string::const_iterator found = std::search(curr, end, wikiPath.begin(), wikiPath.end());
        if (found == end) break;

        string::const_iterator until = std::find(found + wikiPath.size(), end, '"');
        if (until == end) break;

        if (std::all_of(found + wikiPath.size(), until, [](char c) { return c != '#' && c != ':'; })) {
            string wikiName(found + wikiPath.size(), until);
            links.insert(wikiName);
        }
        curr = found + 1;
    }

    return links;
}

int main() {
    /* Note if your file reading isn't working, please go to the
     * projects tab on the panel on the left, and in the run section,
     * uncheck the "Run in terminal" box and re-check it. This
     * should fix things.
     */

    cout << "Enter a file name: ";
    string filename;
    getline(std::cin, filename);
    string page_html;

    // TODO: Create a filestream from the filename, and convert it into
    //       a single string of data called page_html (declared above)

    // Write code here
    std::ifstream input(filename);
    if (!input.is_open()) {
        std::cerr << "File could not be open" << endl;
        return 1;
    }

    string line;
    while (input >> line) {
        page_html += line + " ";
    }

    cout << "page_html: " << endl;
    cout << page_html << endl;

    unordered_set<string> validLinks = findWikiLinks(page_html);

    // TODO: Print out the validLinks set above.
    //       You can print it out in any format; this is just for you
    //       to be able to compare your results with the [output] results
    //       under the /res folder.

    // Write code here
    std::copy(validLinks.begin(), validLinks.end(), std::ostream_iterator<string>(cout, "\n"));
    return 0;
}
