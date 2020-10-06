#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> longestChain;
        unordered_map<int, unordered_set<string>> wordsGroupByLen;

        int res = 1;
        size_t maxSize = 0;
        for (const auto &word: words) {
            maxSize = std::max(word.size(), maxSize);
            wordsGroupByLen[word.size()].insert(word);
            longestChain[word] = 1;
        }

        for (int i = 2; i <= maxSize; i++) {
            auto iter = wordsGroupByLen.find(i);
            if (iter == wordsGroupByLen.end()) {
                continue;
            }

            auto prevIter = wordsGroupByLen.find(i - 1);
            if (prevIter == wordsGroupByLen.end()) {
                continue;
            }

            for (const auto &word: iter->second) {
                for (int k = 0; k < word.size(); k++) {
                    auto removed = word.substr(0, k) + word.substr(k + 1);
                    auto prevWordIter = prevIter->second.find(removed);
                    if (prevWordIter != prevIter->second.end()) {
                        longestChain[word] = std::max(longestChain[word], longestChain[*prevWordIter] + 1);
                        res = std::max(res, longestChain[word]);
                    }
                }
            }
        }

        return res;
    }
};

int main() {
    vector<vector<string>> testCases {
        {"a","b","ba","bca","bda","bdca"}
    };
    for (auto &testCase: testCases) {
        cout << Solution().longestStrChain(testCase) << endl;
    }
    return 0;
}
