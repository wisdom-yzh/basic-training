#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution {
private:
    static const vector<string> DIGIT_BUTTONS;

public:
    void recursionEnumLetters(vector<string> &letters, string &letter, string &digits,
        string::iterator index) {
        if (index == digits.end()) {
            letters.push_back(letter);
            return;
        }
        const int number = *index - '0';
        const string alphabets = Solution::DIGIT_BUTTONS[number];

        for (auto i = alphabets.begin(); i != alphabets.end(); i++) {
            string next = letter.c_str();
            next.push_back(*i);
            recursionEnumLetters(letters, next, digits, (index + 1));
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            return vector<string>{};
        }
        vector<string> letters;
        string letter = "";
        this->recursionEnumLetters(letters, letter, digits, digits.begin());
        return letters;
    }
};

const vector<string> Solution::DIGIT_BUTTONS {
    "", "",
    "abc", "def", "ghi",
    "jkl", "mno", "pqrs",
    "tuv", "wxyz"
};


int main () {
    vector<string> tests = {
        "",
        "23",
        "2345",
        "357"
    };
    for_each(tests.begin(), tests.end(), [](string &s) {
        vector<string> letters = Solution().letterCombinations(s);
        std::cout << "[";
        for_each(letters.begin(), letters.end(), [](string &letter) {
            std::cout << letter << ',';
        });
        std::cout << "]\n";
    });
    return 0;
}
