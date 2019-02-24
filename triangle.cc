#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        const int ROW = triangle.size();
        int DP1[ROW], DP2[ROW];
        int *dp = DP1, *nextDp = DP2;
        dp[0] = triangle[0][0];
        for (int i = 1; i < ROW; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    nextDp[j] = dp[j] + triangle[i][j];
                } else if (j == i) {
                    nextDp[j] = dp[j - 1] + triangle[i][j];
                } else {
                    nextDp[j] = triangle[i][j] + std::min(dp[j], dp[j - 1]);
                }
            }
            int *tmp = dp;
            dp = nextDp;
            nextDp = tmp;
        }
        return *std::min_element(dp, dp + ROW);
    }
};

int main() {
    vector<vector<int>> triangle {
        { 2 },
        { 3, 4 },
        { 6, 5, 7 },
        { 4, 1, 8, 3 }
    };
    cout << Solution().minimumTotal(triangle);
    return 0;
}
