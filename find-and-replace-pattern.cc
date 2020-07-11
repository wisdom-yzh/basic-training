#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        for (const auto &word: words) {
            if (matchPattern(word, pattern)) {
                result.push_back(word);
            }
        }
        return result;
    }

    bool matchPattern(const string &word, string &pattern) {
        char p2w[26], w2p[26];
        std::fill(p2w, p2w + 26, 0);
        std::fill(w2p, w2p + 26, 0);

        for (int i = 0; i < pattern.size(); i++) {
            char &w = p2w[(int)pattern[i] - 'a'];
            char &p = w2p[(int)word[i] - 'a'];
            if (w == 0 && p == 0) {
                w = word[i];
                p = pattern[i];
            } else if (w != word[i] || p != pattern[i]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    vector<string> words { "abc","deq","mee","aqq","dkd","ccc" };
    for (const auto &str: Solution().findAndReplacePattern(words, "abb")) {
        cout << str << endl;
    }
    return 0;
}
