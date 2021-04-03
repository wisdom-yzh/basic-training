#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    enum Direction {
        Left = 0,
        Right = 1,
        Top = 2,
        Bottom = 3,
        All = 4,
    };

    bool hasValidPath(vector<vector<int>>& grid) {
        return move(grid, 0, 0, All);
    }

    bool move(vector<vector<int>> &grid, int y, int x, Direction from) {
        if (y == grid.size() - 1 && x == grid[0].size() - 1) {
            return true;
        }

        int res = false;
        int val = grid[y][x];

        // move right
        if ((val == 1 || val == 4 || val == 6) &&
            (x < grid[0].size() - 1) &&
            (from != Right)) {
            int ny = y, nx = x + 1, nVal = grid[ny][nx];
            if (nVal == 1 || nVal == 3 || nVal == 5) {
                grid[y][x] = 0;
                res |= move(grid, ny, nx, Direction::Left);
                grid[y][x] = val;
            }
        }
        // move left
        if ((val == 1 || val == 3 || val == 5) &&
            (x > 0) &&
            (from != Left)) {
            int ny = y, nx = x - 1, nVal = grid[ny][nx];
            if (nVal == 1 || nVal == 4 || nVal == 6) {
                grid[y][x] = 0;
                res |= move(grid, ny, nx, Direction::Right);
                grid[y][x] = val;
            }
        }
        // move down
        if ((val == 2 || val == 3 || val == 4) &&
            (y < grid.size() - 1) &&
            (from != Bottom)) {
            int ny = y + 1, nx = x, nVal = grid[ny][nx];
            if (nVal == 2 || nVal == 5 || nVal == 6) {
                grid[y][x] = 0;
                res |= move(grid, ny, nx ,Direction::Top);
                grid[y][x] = val;
            }
        }
        // move up
        if ((val == 2 || val == 5 || val == 6) &&
            (y > 0) &&
            (from != Top)) {
            int ny = y - 1, nx = x, nVal = grid[ny][nx];
            if (nVal == 2 || nVal == 3 || nVal == 4) {
                grid[y][x] = 0;
                res |= move(grid, ny, nx, Direction::Bottom);
                grid[y][x] = val;
            }
        }
        return res;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{4,3,3},{6,5,2}},
        {{2,4,3},{6,5,2}},
        {{1,2,1},{1,2,1}},
        {{1,1,2}},
        {{1,1,1,1,1,1,3}},
        {{2},{2},{2},{2},{2},{2},{6}},
        {{4,1},{6,1}}
    };

    for (auto &testCase: testCases) {
        cout << boolalpha << Solution().hasValidPath(testCase) << endl;
    }

    return 0;
}
