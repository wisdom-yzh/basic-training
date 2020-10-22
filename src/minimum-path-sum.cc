#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int M = grid.size();
        const int N = grid[0].size();
        int minPathSum[M][N];

        minPathSum[0][0] = grid[0][0];
        for (int i = 1; i < M; i++) {
            minPathSum[i][0] = grid[i][0] + minPathSum[i - 1][0];
        }
        for (int j = 1; j < N; j++) {
            minPathSum[0][j] = grid[0][j] + minPathSum[0][j - 1];
        }
        
        for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                minPathSum[i][j] = std::min(
                    minPathSum[i - 1][j],
                    minPathSum[i][j - 1]
                ) + grid[i][j];
            }
        }

        return minPathSum[M - 1][N - 1];
    }
};

int main() {
    vector<vector<int>> grid {
        { 1, 3, 1 },
        { 1, 5, 1 },
        { 4, 2, 1 }
    };
    cout << Solution().minPathSum(grid);
    return 0;
}
