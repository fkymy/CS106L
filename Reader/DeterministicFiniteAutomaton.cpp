#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <cctype>

using namespace std;

struct DFA {
    map<pair<int, char>, int> transitions;
    set<int> acceptingState;
    int startState;
};

bool SimulateDFA(DFA& d, string input) {
    int currState = d.startState;
    for (string::iterator itr = input.begin(); itr != input.end(); ++itr) {
        currState = d.transitions[make_pair(currState, *itr)];
    }

    return d.acceptingState.find(currState) != d.acceptingState.end();
}

DFA LoadEmailDFA() {
    DFA ret;
    // implement
    return ret;
}

bool IsEmailAddress(string input) {
    DFA emailChecker = LoadEmailDFA();

    for (string::iterator itr = input.begin(); itr != input.end(); ++itr) {
        if (isalnum(*itr))
            *itr = 'a';
        else if (*itr != '.' && *itr != '@')
            return false;
    }
    return SimulateDFA(emailChecker, input);
}
