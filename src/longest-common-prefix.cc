#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) {
            return string("");
        }
        if (strs.size() == 1) {
            return strs[0];
        }
        ostringstream ss;
        unsigned int pos = 0;
        const string firstString = strs[0];

        for (;;pos++) {
            bool matched = true;
            for (auto iter = strs.begin() + 1;
                iter != strs.end() && matched;
                iter++) {
                const string str = *iter;
                if (str.length() <= pos ||
                    str[pos] != firstString[pos]) {
                    matched = false;
                }
            }
            if (matched) {
                ss << firstString[pos];
            } else {
                break;
            }
        }

        return ss.str();
    }
};

int main() {
    Solution s;

    vector<string> test1 {
        "dog",
        "racecat",
        "car"
    };
    std::cout << s.longestCommonPrefix(test1);

    vector<string> test2 {
        "dog",
        "door",
        "domain"
    };
    std::cout << s.longestCommonPrefix(test2);

    vector<string> test3 {
        ""
    };
    std::cout << s.longestCommonPrefix(test3);

    vector<string> test4;
    std::cout << s.longestCommonPrefix(test4);

    return 0;
}
