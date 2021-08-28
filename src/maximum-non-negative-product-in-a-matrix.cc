#include <vector>
#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const int ROW = grid.size(), COL = grid[0].size();
        vector<vector<int64_t>> maxDp(grid.size(), vector<int64_t>(grid[0].size(), std::numeric_limits<int64_t>::min()));
        vector<vector<int64_t>> minDp(grid.size(), vector<int64_t>(grid[0].size(), std::numeric_limits<int64_t>::max()));

        maxDp[0][0] = minDp[0][0] = grid[0][0];
        for (int y = 0; y < ROW; y++) {
            for (int x = 0; x < COL; x++) {
                int n = grid[y][x];
                if (n == 0) {
                    maxDp[y][x] = minDp[y][x] = 0;
                } else if (n > 0) {
                    if (x > 0) {
                        maxDp[y][x] = maxDp[y][x - 1] * n;
                        minDp[y][x] = minDp[y][x - 1] * n;
                    }
                    if (y > 0) {
                        maxDp[y][x] = std::max(maxDp[y][x], maxDp[y - 1][x] * n);
                        minDp[y][x] = std::min(minDp[y][x], minDp[y - 1][x] * n);
                    }
                } else {
                    if (x > 0) {
                        maxDp[y][x] = minDp[y][x - 1] * n;
                        minDp[y][x] = maxDp[y][x - 1] * n;
                    }
                    if (y > 0) {
                        maxDp[y][x] = std::max(maxDp[y][x], minDp[y - 1][x] * n);
                        minDp[y][x] = std::min(minDp[y][x], maxDp[y - 1][x] * n);
                    }
                }
            }
        }
        return maxDp[ROW - 1][COL - 1] >= 0 ? (maxDp[ROW - 1][COL - 1] % static_cast<int>(1e9 + 7)) : -1;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {
            {-1,-2,-3},
            {-2,-3,-3},
            {-3,-3,-2}
        },
        {
            {1,-2,1},
            {1,-2,1},
            {3,-4,1}
        },
        {
            {1, 3},
            {0,-4}
        },
        {
            { 1, 4,4,0},
            {-2, 0,0,1},
            { 1,-1,1,1}
        }
    };
    for (auto &testCase: testCases) {
        cout << Solution().maxProductPath(testCase) << endl;
    }
    return 0;
}
