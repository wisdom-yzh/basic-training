#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        std::stringstream input(sentence), output;
        string word;

        while (std::getline(input, word, ' ')) {
            output << std::move(replace(word, dict)) << ' ';
        }

        string res = output.str();
        return res.substr(0, res.size() - 1);
    }

    string && replace(string &word, vector<string> &dict) {
        for (auto &root: dict) {
            if (word.substr(0, root.size()) == root) {
                word = root;
            }
        }
        return std::move(word);
    }
};

int main() {
    vector<string> dict {"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";
    std::cout << Solution().replaceWords(dict, sentence);
    return 0;
}
