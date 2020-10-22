#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res;

        for (const auto & dest: d) {
            int i = 0, j = 0;
            for (; i < s.size() && j < dest.size(); i++) {
                if (s[i] == dest[j]) {
                    j++;
                }
            }

            if (j == dest.size() &&
                (dest.length() > res.length() ||
                 (dest.length() == res.length() && res > dest))) {
                res = std::move(dest);
            }
        }

        return res;
    }
};

int main() {
    vector<string> dic { "ale", "apple", "monkey", "plea" };
    std::cout << Solution().findLongestWord("abpcplea", dic);
    return 0;
}
