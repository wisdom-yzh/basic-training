#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        const auto compare = [](const pair<int, string> &a, const pair<int, string> &b) {
           if (a.first == b.first) {
               return a.second > b.second;
           }
           return a.first < b.first;
        };

        std::map<std::string, int> wordMap;
        for (const auto &word: words) {
            if (wordMap.find(word) == wordMap.end()) {
                wordMap[word] = 1;
            } else {
                wordMap[word]++;
            }
        }

        std::set<pair<int, string>, decltype(compare)> topSet(compare);
        for (const auto &word: wordMap) {
            topSet.emplace(word.second, word.first);
        }

        std::vector<string> result;
        auto iter = topSet.rbegin();
        for (int i = 0; i < k; i++) {
            result.push_back(iter->second);
            iter++;
        }
        return result;
    }
};

int main() {
    vector<std::pair<vector<string>, int>> cases {
        make_pair(vector<string>({ "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is" }), 4),
        make_pair(vector<string>({ "i", "love", "leetcode", "i", "love", "coding" }), 2)
    };
    for (auto &words: cases) {
        for (const auto &str: Solution().topKFrequent(words.first, words.second)) {
            std::cout << str << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}
