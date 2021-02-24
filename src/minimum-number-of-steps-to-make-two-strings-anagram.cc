#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        map<char, int> freq;
        for (auto &ch: s) {
            freq[ch]++;
        }

        int res = 0;
        for (auto &ch: t) {
            if (freq[ch] > 0) {
                freq[ch]--;
            } else {
                res++;
            }
        }

        return res;
    }
};

int main() {
    vector<pair<string, string>> testCases {
        { "bab", "aba" },
        { "leetcode", "practice" },
        { "anagram", "mangaar" },
        { "xxyyzz", "xxyyzz" },
        { "friend", "family" }
    };
    for (auto &testCase: testCases) {
        cout << Solution().minSteps(testCase.first, testCase.second) << endl;
    }
    return 0;
}
