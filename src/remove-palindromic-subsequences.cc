#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.empty()){
            return 0;
        }

        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return 2;
            }
        }

        return 1;
    }
};

int main() {
    vector<string> testCases {
        "ababa",
        "abb",
        "baabb",
        "",
    };
    for (auto &s: testCases) {
        cout << Solution().removePalindromeSub(s) << endl;
    }
    return 0;
}
