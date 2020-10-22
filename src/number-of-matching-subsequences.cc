#include <string>
#include <vector>
#include <array>
#include <iostream>
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        array<vector<int>, 26> wordIndex;
        wordIndex.fill(vector<int>(0));

        for (int i = 0; i < S.size(); i++) {
            wordIndex[S[i] - 'a'].push_back(i);
        }

        int count = 0;
        for (const auto &word: words) {
            if (checkSubSeq(wordIndex, word)) {
                count++;
            }
        }

        return count;
    }

    bool checkSubSeq(const array<vector<int>, 26> &indexes, const string &word) {
        std::array<int, 26> wordIndex {};
        int currentIndex = -1;

        for (const auto &ch: word) {
            int idx = ch - 'a';
            int index;

            while (true) {
                if (wordIndex[idx] >= indexes[idx].size()) {
                    return false;
                }
                index = indexes[idx][wordIndex[idx]];
                if (index < currentIndex) {
                    wordIndex[idx]++;
                } else {
                    break;
                }
            }

            currentIndex = index;
            wordIndex[idx]++;
        }

        return true;
    }
};

int main() {
    vector<string> words {"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"};
    cout << Solution().numMatchingSubseq("dsahjpjauf", words);
    return 0;
}
