#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        std::set<std::string> s;
        std::sort(words.begin(), words.end());

        int maxLength = 0, length = 0;
        string result;
        for (int i = 0; i < words.size(); i++) {
            int wsize = words[i].size();
            if (wsize == 1 || s.find(words[i].substr(0, wsize - 1)) != s.end()) {
                s.insert(words[i]);
                if (wsize > maxLength) {
                    maxLength = wsize;
                    result = words[i];
                }
            }
        }

        return result;
    }
};

int main() {
    vector<string> words {
        "rac","rs","ra","on","r","otif","o","onpdu","rsf","rs","ot","oti","racy","onpd"
    };
    cout << Solution().longestWord(words);
    return 0;
}