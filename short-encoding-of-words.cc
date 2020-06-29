#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        vector<string> postfixes;
        for (auto &word: words) {
            std::reverse(word.begin(), word.end());
            bool found = false;
            for (auto &postfix: postfixes) {
                if (word.size() > postfix.size() && word.find(postfix) == 0) {
                    postfix = word;
                    found = true;
                    break;
                }
                if (postfix.find(word) == 0) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                postfixes.push_back(word);
            }
        }

        return std::accumulate(postfixes.begin(), postfixes.end(), 0, [](int acc, string &postfix) {
            return acc + postfix.size() + 1;
        });
    }
};

int main() {
    vector<string> words { "time", "me", "bell" };
    cout << Solution().minimumLengthEncoding(words);
    return 0;
}
