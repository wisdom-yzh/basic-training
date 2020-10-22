#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        if (mines.size() == N * N) {
            return 0;
        }
        vector<vector<int>> grid(N, vector<int>(N, 1));
        for (const auto &mine: mines) {
            grid[mine[0]][mine[1]] = 0;
        }

        int result = 1;
        vector<vector<int>> dp(grid);
        for (int i = 1; i < N; i++) {
            int count = grid[i][0];
            for (int j = 1; j < N - 1; j++) {
                if (grid[i][j] != 0) {
                    dp[i][j] = ++count;
                } else {
                    count = 0;
                }
            }

            count = grid[i][N - 1];
            for (int j = N - 2; j >= 1; j--) {
                if (grid[i][j] != 0) {
                    dp[i][j] = std::min(dp[i][j], ++count);
                } else {
                    count = 0;
                }
            }
        }

        for (int j = 1; j < N; j++) {
            int count = grid[0][j];
            for (int i = 1; i < N - 1; i++) {
                if (grid[i][j] != 0) {
                    dp[i][j] = std::min(dp[i][j], ++count);
                } else {
                    count = 0;
                }

            }

            count = grid[N - 1][j];
            for (int i = N - 2; i >= 1; i--) {
                if (grid[i][j] != 0) {
                    dp[i][j] = std::min(dp[i][j], ++count);
                    result = std::max(dp[i][j], result);
                } else {
                    count = 0;
                }
            }
        }

        return result;
    }
};

int main() {
    vector<vector<int>> mines {
        {0,0},{0,1},{0,4},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2},{2,3},{2,4},{3,0},{4,0},{4,1},{4,3},{4,4}
    };
    cout << Solution().orderOfLargestPlusSign(5, mines);
    return 0;
}
