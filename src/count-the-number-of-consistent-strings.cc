#include <string>
#include <iostream>
#include <vector>
#include <array>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        std::array<bool, 26> allowedSet;
        std::fill(allowedSet.begin(), allowedSet.end(), false);
        for (auto &ch: allowed) {
            allowedSet[ch - 'a'] = true;
        }

        int res = 0;
        for (auto &word: words) {
            bool valid = true;
            for (auto &ch: word) {
                if (!allowedSet[ch - 'a']) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                res++;
            }
        }

        return res;
    }
};

int main() {
    vector<pair<string, vector<string>>> testCases {
        {"ab", {"ad","bd","aaab","baa","badab"}},
        {"abc", {"a","b","c","ab","ac","bc","abc"}},
        {"cad", {"cc","acd","b","ba","bac","bad","ac","d"}}
    };
    for (auto &[allowed, words]: testCases) {
        cout << Solution().countConsistentStrings(allowed, words) << endl;
    }
    return 0;
}
