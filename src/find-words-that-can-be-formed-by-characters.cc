#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> alphabet(26, 0);
        for (auto &ch: chars) {
            alphabet[ch - 'a']++;
        }

        int count = 0;
        for (auto &word: words) {
            std::unordered_map<char, int> dict;
            for (auto &ch: word) {
                dict[ch]++;
            }

            bool matched = true;
            for (auto &pair: dict) {
                if (alphabet[pair.first - 'a'] < pair.second) {
                    matched = false;
                    break;
                }
            }

            if (matched) {
                count += word.size();
            }
        }

        return count;
    }
};

int main() {
    vector<pair<vector<string>, string>> testCases {
        { { "cat","bt","hat","tree" }, "atach" },
        { { "hello","world","leetcode" }, "welldonehoneyr" }
    };
    for (auto &testCase: testCases) {
        cout << Solution().countCharacters(testCase.first, testCase.second) << endl;
    }
    return 0;
}
