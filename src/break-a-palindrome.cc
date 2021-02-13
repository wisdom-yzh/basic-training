#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        if (palindrome.size() == 1) {
            return "";
        }

        auto idx = palindrome.find_first_not_of('a');
        if ((idx != string::npos) &&
            ((palindrome.size() % 2 != 0 && idx != palindrome.size() / 2) ||
            (palindrome.size() % 2 == 0))) {
            *(next(palindrome.begin(), idx)) = 'a';
        } else {
            *(prev(palindrome.end())) = 'b';
        }

        return palindrome;
    }
};

int main() {
    vector<string> testCases {
        "abccba",
        "a",
        "aa",
        "aba"
    };
    for (auto &testCase: testCases) {
        cout << Solution().breakPalindrome(testCase) << endl;
    }
    return 0;
}
