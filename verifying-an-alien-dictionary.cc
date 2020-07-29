#include <vector>
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        std::map<int, int> orderMap;
        for (int i = 0; i < order.size(); i++) {
            orderMap[static_cast<int>(order[i])] = i;
        }

        for (int i = 0; i < words.size() - 1; i++) {
            if (!this->order(words[i], words[i + 1], orderMap)) {
                return false;
            }
        }
        return true;
    }

    bool order(string &word1, string &word2, std::map<int, int> &orderMap) {
        int i = 0;
        while (true) {
            if (i == word1.size()) {
                return true;
            } else if (i == word2.size()) {
                return false;
            }

            if (word1[i] == word2[i]) {
                i++;
            } else {
                return orderMap[word1[i]] < orderMap[word2[i]];
            }
        }
    }
};

int main() {
    vector<pair<vector<string>, string>> testCases {
        {{"hello","leetcode"}, "hlabcdefgijkmnopqrstuvwxyz"},
        {{"word","world","row"}, "worldabcefghijkmnpqstuvxyz"},
        {{"apple","app"}, "abcdefghijklmnopqrstuvwxyz"},
        {{"app", "apple"}, "abcdefghijklmnopqrstuvwxyz"},
    };
    for (auto &testCase: testCases) {
        cout << boolalpha << Solution().isAlienSorted(testCase.first, testCase.second) << endl;
    }
    return 0;
}
