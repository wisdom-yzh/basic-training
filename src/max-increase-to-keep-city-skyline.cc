#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }

        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        vector<int> skyLineRow(ROWS, 0), skyLineCol(COLS, 0);

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                skyLineRow[i] = std::max(skyLineRow[i], grid[i][j]);
                skyLineCol[j] = std::max(skyLineCol[j], grid[i][j]);
            }
        }

        int result = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                result += std::min(skyLineRow[i], skyLineCol[j]) - grid[i][j];
            }
        }

        return result;
    }
};

int main() {
    vector<vector<int>> grid {
        {3, 0, 8, 4},
        {2, 4, 5, 7},
        {9, 2, 6, 3},
        {0, 3, 1, 0}
    };

    cout << Solution().maxIncreaseKeepingSkyline(grid);
    return 0;
}
