#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    const int d[4][2] {
        { 0, 1 },
        { 0, -1 },
        { -1, 0 },
        { 1, 0 }
    };

    int rows, cols;

    int getMaximumGold(vector<vector<int>>& grid) {
        int maxValue = 0;
        this->rows = grid.size();
        this->cols = grid[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] != 0) {
                    maxValue = std::max(maxValue, this->recursion(grid, r, c, 0));
                }
            }
        }
        return maxValue;
    }

    int recursion(vector<vector<int>> &grid, int r, int c, int val) {
        int current = grid[r][c] + val;
        int maxValue = current;

        grid[r][c] = 0;

        for (int i = 0; i < 4; i++) {
            int newR = r + d[i][0];
            int newC = c + d[i][1];
            if (newR >= 0 && newR < rows &&
                newC >= 0 && newC < cols &&
                grid[newR][newC] != 0) {
                maxValue = std::max(maxValue, recursion(grid, newR, newC, current));
            }
        }

        grid[r][c] = current - val;
        return maxValue;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
         {{0,6,0},{5,8,7},{0,9,0}},
         {{1,0,7},{2,0,6},{3,4,5},{0,3,0},{9,0,20}}
    };
    for (auto &testCase: testCases) {
        cout << Solution().getMaximumGold(testCase) << endl;
    }
    return 0;
}
