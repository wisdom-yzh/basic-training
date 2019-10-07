#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <limits>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty()) {
            return word2.size();
        }
        if (word2.empty()) {
            return word1.size();
        }

        vector<vector<int>> minDists(word1.size(), vector<int>(word2.size()));
        minDists[0][0] = word1[0] == word2[0] ? 0 : 2;

        for (int index2 = 1; index2 < word2.size(); index2++) {
            minDists[0][index2] = word2[index2] == word1[0] ?
                index2 :
                minDists[0][index2 - 1] + 1;
        }

        for (int index2 = 0; index2 < word2.size(); index2++) {
            for (int index1 = 1; index1 < word1.size(); index1++) {
                int minDist = minDists[index1 - 1][index2] + 1;
                for (int i = 0; i <= index2; i++) {
                    if (word1[index1] == word2[i]) {
                        if (i == 0) {
                            minDist = std::min(
                                minDist,
                                index1 + index2
                            );
                        } else {
                            minDist = std::min(
                                minDist,
                                minDists[index1 - 1][i - 1] + index2 - i
                            );
                        }
                    }
                }
                minDists[index1][index2] = minDist;
            }
        }
        return minDists[word1.size() - 1][word2.size() - 1];
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string word1 = stringToString(line);
        getline(cin, line);
        string word2 = stringToString(line);

        int ret = Solution().minDistance(word1, word2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
