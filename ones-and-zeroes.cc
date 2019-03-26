#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto &s: strs) {
            int ones = count(s.begin(), s.end(), '1');
            int zeros = s.size() - ones;
            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    vector<string> strs { "10", "0001", "111001", "1", "0" };
    cout << Solution().findMaxForm(strs, 5, 3);
    return 0;
}
