#include <algorithm>
#include <cctype>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

bool IsPalindromeMechanical(std::string input) {
    for (int k = 0; k < input.size() / 2; ++k) {
        if (input[k] != input[input.size() - 1 - k]) return false;
    }
    return true;
}

bool IsPalindromeReverseCopy(std::string input) {
    std::string reversed = input;
    reverse(input.begin(), input.end());
    return reversed == input;
}

bool IsNotAlpha(char ch) { return !isalpha(ch); }

bool IsPalindrome(std::string input) {
    input.erase(std::remove_if(input.begin(), input.end(), IsNotAlpha),
                input.end());
    std::transform(input.begin(), input.end(), input.begin(), ::toupper);
    return std::equal(input.begin(), input.begin() + input.size() / 2,
                      input.rbegin());
}

bool IsNotAlphaOrSpace(char ch) { return !isalpha(ch) && !isspace(ch); }

bool IsWordPalindrome(std::string input) {
    input.erase(std::remove_if(input.begin(), input.end(), IsNotAlphaOrSpace),
                input.end());
    std::transform(input.begin(), input.end(), input.begin(), ::toupper);

    std::stringstream tokenizer(input);
    std::vector<std::string> tokens;

    tokens.insert(tokens.begin(), std::istream_iterator<std::string>(tokenizer),
                  std::istream_iterator<std::string>());
    return std::equal(tokens.begin(), tokens.begin() + tokens.size() / 2,
                      tokens.rbegin());
}
