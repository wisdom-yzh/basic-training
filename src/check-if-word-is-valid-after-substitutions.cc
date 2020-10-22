#include <vector>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) {
            return true;
        }
        stack<char> stk;
        for (const auto &ch: s) {
            if (ch != 'c') {
                stk.push(ch);
                continue;
            }

            if (stk.empty()) {
                return false;
            }

            auto &b = stk.top();
            stk.pop();
            if (stk.empty()) {
                return false;
            }
            auto &a = stk.top();
            stk.pop();

            if (a != 'a' || b != 'b') {
                return false;
            }
        }

        return stk.empty();
    }
};

int main() {
    vector<string> testCases {
        "aabcbc",
        "abcabcababcc",
        "abccba",
        "cababc"
    };

    for (auto &testCase: testCases) {
        cout << boolalpha << Solution().isValid(testCase) << endl;
    }
    return 0;
}
