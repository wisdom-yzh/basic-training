#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        std::array<char, 26> count;
        std::fill(count.begin(), count.end(), 0);

        for (auto &ch: sentence) {
            count[ch - 'a']++;
        }
        
        for (auto &c: count) {
            if (c == 0) {
                return false;
            }
        }
        return true;
    }
};

int main (int argc, char *argv[]) {
    vector<string> testCases {
        "thequickbrownfoxjumpsoverthelazydog",
        "leetcode"
    };
    for (auto &testCase: testCases) {
        cout << boolalpha << Solution().checkIfPangram(testCase) << endl;
    }
    return 0;
}
