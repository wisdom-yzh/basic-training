#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        std::vector<int> m(26, 0);

        for (const auto &strB: B) {
            vector<int> mB(26, 0);
            for (const auto &ch: strB) {
                mB[ch - 'a']++;
                if (mB[ch - 'a'] > m[ch - 'a']) {
                    m[ch - 'a'] = mB[ch - 'a'];
                }
            }
        }

        vector<string> result;
        for (const auto &strA: A) {
            vector<int> mA(26, 0);
            for (const auto &ch: strA) {
                mA[ch - 'a']++;
            }
            bool contains = true;
            for (int i = 0; i < 26; i++) {
                if (m[i] > mA[i]) {
                    contains = false;
                    break;
                }
            }
            if (contains) {
                result.push_back(strA);
            }
        }

        return result;
    }
};

int main() {
    vector<vector<vector<string>>> testCases {
        { { "amazon","apple","facebook","google","leetcode" }, { "e","o" } },
        { { "amazon","apple","facebook","google","leetcode" }, { "l","e" } },
        { { "amazon","apple","facebook","google","leetcode" }, { "e","oo" } },
        { { "amazon","apple","facebook","google","leetcode" }, { "ec","oc","ceo" } },
    };
    for (auto &testCase: testCases) {
        for (const auto &str: Solution().wordSubsets(testCase[0], testCase[1])) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}
