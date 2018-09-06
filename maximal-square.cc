#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), sz = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j] - '0';
            sz = max(sz, dp[0][j]);
        }
        for (int i = 1; i < m; i++) {
            dp[i][0] = matrix[i][0] - '0';
            sz = max(sz, dp[i][0]);
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    sz = max(sz, dp[i][j]);
                }
            }
        }
        return sz * sz;
    }
};

int main() {
    vector<vector<char>> matrix {
        { '1', '0', '1', '0', '0' },
        { '1', '0', '1', '1', '1' },
        { '1', '1', '1', '1', '1' },
        { '1', '0', '0', '1', '0' },
    };
    return 0;
}
