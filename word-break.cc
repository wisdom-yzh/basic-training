#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) {
            return true;
        }
        if (wordDict.empty()) {
            return false;
        }
        vector<bool> canBreak(s.size());
        for (size_t i = 0; i < s.size(); i++) {
            bool currentCanBreak = false;
            for (auto &word: wordDict) {
                if (word.size() > i + 1) {
                    continue;
                }
                auto begin = i - word.size() + 1;
                if (word.size() > i + 1 ||
                    s.substr(begin, word.size()) != word) {
                    continue;
                }
                if (begin == 0 || canBreak[begin - 1]) {
                    currentCanBreak = true;
                    break;
                }
            }
            canBreak[i] = currentCanBreak;
        }
        return canBreak[s.size() - 1];
    }
};

int main() {
    string s("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab");
    vector<string> wordDict {
        "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"
    };
    //string s("leetcode");
    //vector<string> wordDict {
        //"leet", "code"
    //};
    cout << boolalpha << Solution().wordBreak(s, wordDict);
    return 0;
}
