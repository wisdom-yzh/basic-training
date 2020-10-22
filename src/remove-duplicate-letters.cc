#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        std::map<char, int> lastIndex;
        std::set<char> charSet;

        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i]] = i;
        }

        string stk;
        for (int i = 0; i < s.size(); i++) {
            auto ch = s[i];
            if (charSet.find(ch) != charSet.end()) {
                continue;
            }

            while (!stk.empty() && stk.back() > ch && lastIndex[stk.back()] > i) {
                charSet.erase(stk.back());
                stk.pop_back();
            }

            stk.push_back(ch);
            charSet.emplace(ch);
        }

        return stk;
    }
};

int main() {
    vector<string> testCases {
        "bcabc",
        "cbacdcbc",
    };
    for (auto &s: testCases) {
        cout << Solution().removeDuplicateLetters(s) << endl;
    }
    return 0;
}
