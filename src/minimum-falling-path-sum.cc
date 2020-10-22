#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        const int rows = A.size();
        const int cols = A[0].size();
        vector<vector<int>> dp(A.size(), vector<int>(A[0].size(), 0));

        for (int i = rows - 1; i >= 0; i--) {
            for (int j = 0; j < cols; j++) {
                if (i == rows - 1) {
                    dp[i][j] = A[i][j];
                } else {
                    dp[i][j] = A[i][j] + dp[i + 1][j];
                    if (j != 0) {
                        dp[i][j] = std::min(dp[i][j], A[i][j] + dp[i + 1][j - 1]);
                    }
                    if (j != cols - 1) {
                        dp[i][j] = std::min(dp[i][j], A[i][j] + dp[i + 1][j + 1]);
                    }
                }
            }
        }

        return *std::min_element(dp[0].begin(), dp[0].end());
    }
};

int main() {
    vector<vector<int>> testCase { {1,2,3},{4,5,6},{7,8,9} };
    cout << Solution().minFallingPathSum(testCase);
    return 0;
}
