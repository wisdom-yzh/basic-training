#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    result += (4 - checkNeigbor(grid, i, j));
                }
            }
        }
        return result;
    }

    int checkNeigbor(vector<vector<int>> &grid, int i, int j ) {
        int result = 0;
        if (i > 0) result += grid[i - 1][j];
        if (j > 0) result += grid[i][j - 1];
        if (i + 1 < grid.size()) result += grid[i + 1][j];
        if (j + 1 < grid[0].size()) result += grid[i][j + 1];
        return result;
    }
};

int main() {
    vector<vector<int>> grid {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    };
    cout << Solution().islandPerimeter(grid);

    vector<vector<int>> grid2 {
        {1},
        {0}
    };
    cout << Solution().islandPerimeter(grid2);
    return 0;
}
