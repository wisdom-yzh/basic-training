#include <vector>
#include <array>
#include <iostream>
using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.empty() || grid.size() < 3 || grid[0].size() < 3) {
            return 0;
        }
        int result = 0;
        for (int y = 0; y < grid.size() - 2; y++) {
            for (int x = 0; x < grid[0].size() - 2; x++) {
                if (check(grid, y, x)) {
                    result++;
                }
            }
        }
        return result;
    }

    bool check(vector<vector<int>> &grid, int r, int c) {
        std::array<bool, 10> flag { false };
        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 3; x++) {
                int num = grid[r+y][c+x];
                if (num < 1 || num > 9 || flag[num]) {
                    return false;
                }
                flag[num] = true;
            }
        }

        for (int y = r; y < r + 3; y++) {
            if (grid[y][c] + grid[y][c+1] + grid[y][c+2] != 15) {
                return false;
            }
        }
        for (int x = c; x < c + 3; x++) {
            if (grid[r][x] + grid[r+1][x] + grid[r+2][x] != 15) {
                return false;
            }
        }
        return grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] == 15 &&
            grid[r+2][c] + grid[r+1][c+1] + grid[r][c+2] == 15;
    }
};


int main() {
    vector<vector<int>> grid {
        {3,2,9,2,7},
        {6,1,8,4,2},
        {7,5,3,2,7},
        {2,9,4,9,6},
        {4,3,8,2,5}
    };
    cout << Solution().numMagicSquaresInside(grid);
    return 0;
}
