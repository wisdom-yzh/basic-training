#include <string>
#include <vector>
#include <array>
#include <iostream>
using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        std::array<int, 26> dict;
        dict.fill(0);
        for (auto &ch: licensePlate) {
            char c = std::tolower(ch);
            if (c >= 'a' && c <= 'z') {
                dict[c - 'a']++;
            }
        }

        string shortestWord;

        for (const auto &word: words) {
            auto d = dict;

            for (const auto &ch: word) {
                if (d[ch - 'a'] != 0) {
                    d[ch - 'a']--;
                }
            }

            bool contain = true;
            for (auto &ch: d) {
                if (ch != 0) {
                    contain = false;
                    break;
                }
            }

            if (contain && (shortestWord.empty() || shortestWord.size() > word.size())) {
                shortestWord = word;
            }
        }

        return shortestWord;
    }
};

int main() {
    vector<string> words { "step", "steps", "stripe", "stepple" };
    std::cout << Solution().shortestCompletingWord("1s3 PSt", words);
    return 0;
}
