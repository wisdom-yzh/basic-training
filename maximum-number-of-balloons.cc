#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int singleWord[] = { 0, 0 };
        int doubleWord[] = { 0, 0 };

        for (auto &ch: text) {
            switch (ch) {
                case 'b':
                    singleWord[0]++;
                    break;
                case 'a':
                    singleWord[1]++;
                    break;
                case 'l':
                    doubleWord[0]++;
                    break;
                case 'o':
                    doubleWord[1]++;
                    break;
            }
        }

        return std::min(
            *std::min_element(singleWord, singleWord + 2),
            (*std::min_element(doubleWord, doubleWord + 2)) / 2
        );
    }
};

int main() {
    vector<string> testCases {
        "nlaebolko",
        "loonbalxballpoon",
        "leetcode"
    };
    for (auto &testCase: testCases) {
        cout << Solution().maxNumberOfBalloons(testCase) << endl;
    }
    return 0;
}
