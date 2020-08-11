#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
using namespace std;

class Solution {
public:
    const static pair<int, int> direction[4];

    int orangesRotting(vector<vector<int>>& grid) {
        const int ROWS = grid.size(), COLS = grid[0].size();
        vector<vector<int>> maxDayMat(ROWS, vector<int>(COLS, -1));

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 0 || grid[i][j] == 2) {
                    maxDayMat[i][j] = 0;
                } else {
                    maxDayMat[i][j] = -1;
                }
            }
        }

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 2) {
                    std::queue<std::pair<int, int>> q;
                    q.push({i, j});

                    while (!q.empty()) {
                        int r, c, dr, dc;
                        std::tie(r, c) = q.front();

                        for (const auto &d: Solution::direction) {
                            std::tie(dr, dc) = d;
                            if (r + dr >= 0 && r + dr < ROWS &&
                                c + dc >= 0 && c + dc < COLS &&
                                grid[r + dr][c + dc] == 1 &&
                                (maxDayMat[r + dr][c + dc] == -1 ||
                                 maxDayMat[r + dr][c + dc] > maxDayMat[r][c] + 1)) {
                                maxDayMat[r + dr][c + dc] = maxDayMat[r][c] + 1;
                                q.push({ r + dr, c + dc });
                            }
                        }

                        q.pop();
                    }
                }
            }
        }

        int maxDays = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (maxDayMat[i][j] == -1 && grid[i][j] == 1) {
                    return -1;
                }
                maxDays = std::max(maxDays, maxDayMat[i][j]);
            }
        }
        return maxDays;
    }
};

const pair<int, int> Solution::direction[4] = {
    { 0, -1 },
    { 0, 1 },
    { 1, 0 },
    { -1, 0 },
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{2,1,1},{1,1,0},{0,1,1}},
        {{2,1,1},{0,1,1},{1,0,1}},
        {{0,2}}
    };
    for (auto &testCase: testCases) {
        cout << Solution().orangesRotting(testCase) << endl;
    }
    return 0;
}
