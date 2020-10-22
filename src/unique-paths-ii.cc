#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int M = obstacleGrid.size();
        const int N = obstacleGrid[0].size();
        int paths[M][N];
        paths[0][0] = 1 - obstacleGrid[0][0];
        for (int i = 1; i < M; i++) {
            if (obstacleGrid[i][0] == 1) {
                paths[i][0] = 0;
            } else {
                paths[i][0] = paths[i - 1][0];
            }
        }
        for (int j = 1; j < N; j++) {
            if (obstacleGrid[0][j] == 1) {
                paths[0][j] = 0;
            } else {
                paths[0][j] = paths[0][j - 1];
            }
        }

        for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                if (obstacleGrid[i][j] == 1) {
                    paths[i][j] = 0;
                } else {
                    paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
                }
            }
        }

        return paths[M - 1][N - 1];
    }
};

int main() {
    vector<vector<int>> grid {
        { 0, 0, 0 },
        { 0, 1, 0 },
        { 0, 0, 0 },
    };
    cout << Solution().uniquePathsWithObstacles(grid);
    return 0;
}
