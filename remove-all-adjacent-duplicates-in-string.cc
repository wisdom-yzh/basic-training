#include <string>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        std::deque<char> stk;
        for (int i = 0; i < S.size(); i++) {
            if (stk.empty() || stk.back() != S[i]) {
                stk.push_back(S[i]);
            } else {
                stk.pop_back();
            }
        }

        return std::string(stk.begin(), stk.end());
    }
};

int main() {
    vector<string> testCases {
        "abbaca"
    };

    for (auto &testCase: testCases) {
        cout << Solution().removeDuplicates(testCase) << endl;
    }
    return 0;
}
