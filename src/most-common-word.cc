#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, int> dict;
        string word, maxCommonword;
        int maxCount = 0;

        stringstream ss(paragraph);
        while (getline(ss, word, ' ')) {
            stringstream iss(word);
            string w;
            while (getline(iss, w, ',')) {
                for (auto iter = w.begin(); iter != w.end(); ) {
                    if (*iter >= 'a' && *iter <= 'z') {
                        iter++;
                    } else if (*iter >= 'A' && *iter <= 'Z') {
                        *iter = std::tolower(*iter);
                        iter++;
                    } else {
                        iter = w.erase(iter);
                    }
                }
                if (w.size() > 0 && std::find(banned.begin(), banned.end(), w) == banned.end()) {
                    dict[w]++;
                    if (dict[w] > maxCount) {
                        maxCommonword = w;
                        maxCount = dict[w];
                    }
                }
            }
        }

        return maxCommonword;
    }
};

int main() {
    vector<string> banned { "a" };
    cout << Solution().mostCommonWord("a, a, a, a, b,b,b,c, c", banned);
    return 0;
}
