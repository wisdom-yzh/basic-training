#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    const static std::vector<std::set<char>> ROWS;

    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        for (const auto & word: words) {
            bool satisfied = true;
            int index = -1;
            for (auto ch: word) {
                if (ch >= 'A' && ch <= 'Z') {
                    ch = ch - 'A' + 'a';
                }
                for (int i = 0; i < Solution::ROWS.size(); i++) {
                    const auto &collection = Solution::ROWS[i];
                    if (collection.find(ch) != collection.end()) {
                        if (index == -1) {
                            index = i;
                        } else if (index != i) {
                            satisfied = false;
                            break;
                        }
                    }
                    if (!satisfied) {
                        break;
                    }
                }
            }
            if (satisfied) {
                result.push_back(word);
            }
        }
        return result;
    }
};

const std::vector<std::set<char>> Solution::ROWS = {
    std::set<char>({ 'z', 'x', 'c', 'v', 'b', 'n', 'm' }),
    std::set<char>({ 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l' }),
    std::set<char>({ 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p' })
};


int main() {
    vector<string> words { "Hello", "Alaska", "Dad", "Peace" };
    for (const auto &word: Solution().findWords(words)) {
        std::cout << word << std::endl;
    }
    return 0;
}
