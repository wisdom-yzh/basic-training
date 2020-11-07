#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> memo;
    string x, y;

    int longestCommonSubsequence(string text1, string text2) {
        memo.assign(text1.size(), vector<int>(text2.size(), -1));

        x = move(text1);
        y = move(text2);

        return recursiveLCS(x.size() - 1, y.size() - 1);
    }

    int recursiveLCS(int i, int j) {
        if (i < 0 || j < 0) {
            return 0;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int maxValue = std::max(recursiveLCS(i - 1, j), recursiveLCS(i, j - 1));;
        if (x[i] == y[j]) {
            maxValue = std::max(maxValue, recursiveLCS(i - 1, j - 1) + 1);
        }

        memo[i][j] = maxValue;
        return maxValue;
    }
};

int main() {
    vector<pair<string, string>> testCases {
        { "abcde", "ace" },
        { "abc", "abc" },
        { "abc", "def" }
    };
    for (auto &testCase: testCases) {
        cout << Solution().longestCommonSubsequence(testCase.first, testCase.second) << endl;
    }
    return 0;
}
