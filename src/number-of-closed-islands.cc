#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
using namespace std;

class Solution {
public:
    pair<int, int> DIRECTION[4] {
        { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 }
    };

    int rows, cols;

    int closedIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            if (grid[i][0] == 0) {
                floodFill(grid, i, 0);
            }
            if (grid[i][cols - 1] == 0) {
                floodFill(grid, i, cols - 1);
            }
        }
        for (int i = 0; i < cols; i++) {
            if (grid[0][i] == 0) {
                floodFill(grid, 0, i);
            }
            if (grid[rows - 1][i] == 0) {
                floodFill(grid, rows - 1, i);
            }
        }

        int count = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0) {
                    count++;
                    floodFill(grid, r, c);
                }
            }
        }

        return count;
    }

    void floodFill(vector<vector<int>> &grid, int r, int c) {
        std::queue<pair<int, int>> q;
        grid[r][c] = 1;
        q.push({ r, c });

        while (!q.empty()) {
            int r, c, dr, dc;
            std::tie(r, c) = q.front();

            for (auto &d: DIRECTION) {
                std::tie(dr, dc) = d;
                if (r + dr >= 0 && r + dr < rows &&
                    c + dc >= 0 && c + dc < cols &&
                    grid[r + dr][c + dc] == 0) {
                    grid[r + dr][c + dc] = 1;
                    q.push({ r + dr, c + dc });
                }
            }

            q.pop();
        }
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{1,1,1,1,1,1,1,0},
         {1,0,0,0,0,1,1,0},
         {1,0,1,0,1,1,1,0},
         {1,0,0,0,0,1,0,1},
         {1,1,1,1,1,1,1,0}},
        {{0,0,1,0,0},
         {0,1,0,1,0},
         {0,1,1,1,0}},
        {{1,1,1,1,1,1,1},
         {1,0,0,0,0,0,1},
         {1,0,1,1,1,0,1},
         {1,0,1,0,1,0,1},
         {1,0,1,1,1,0,1},
         {1,0,0,0,0,0,1},
         {1,1,1,1,1,1,1}}
    };
    for (auto &testCase: testCases) {
        cout << Solution().closedIsland(testCase) << endl;
    }
    return 0;
}
