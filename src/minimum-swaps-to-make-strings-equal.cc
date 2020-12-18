#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int countX = 0, countY = 0;

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s2[i]) {
                continue;
            }
            if (s1[i] == 'x') {
                countX++;
            } else {
                countY++;
            }
        }

        if ((countX + countY) % 2 != 0) {
            return -1;
        }

        return countX / 2 + countY / 2 + 2 * (countX % 2);
    }
};

int main() {
    vector<pair<string, string>> testCases {
        { "xx", "yy" },
        { "xy", "yx" },
        { "xxyyxyxyxx", "xyyxyxxxyx" },
    };
    for (auto &testCase: testCases) {
        cout << Solution().minimumSwap(testCase.first, testCase.second) << endl;
    }
    return 0;
}
