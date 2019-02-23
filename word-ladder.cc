#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& words) {
        if (find(words.begin(), words.end(), endWord) == words.end()) {
            return 0;
        }
        unordered_set<string> wordDict(words.begin(), words.end());
        wordDict.insert(endWord);
        queue<string> toVisit;
        addNextWords(beginWord, wordDict, toVisit);
        int dist = 2;
        while (!toVisit.empty()) {
            int num = toVisit.size();
            for (int i = 0; i < num; i++) {
                string word = toVisit.front();
                toVisit.pop();
                if (word == endWord) return dist;
                addNextWords(word, wordDict, toVisit);
            }
            dist++;
        }
        return 0;
    }
private:
    void addNextWords(string word, unordered_set<string>& wordDict, queue<string>& toVisit) {
        wordDict.erase(word);
        for (int p = 0; p < (int)word.length(); p++) {
            char letter = word[p];
            for (int k = 0; k < 26; k++) {
                word[p] = 'a' + k;
                if (wordDict.find(word) != wordDict.end()) {
                    toVisit.push(word);
                    wordDict.erase(word);
                }
            }
            word[p] = letter;
        }
    }
};

int main() {
    vector<string> set {
        "hot",
        "dog",
    };
    cout << Solution().ladderLength("hot", "dog", set);
    vector<string> set2 {
        "hot",
        "dot",
        "dog",
        "lot",
        "log",
        "cog"
    };
    cout << Solution().ladderLength("hit", "cog", set2);
    return 0;
}
