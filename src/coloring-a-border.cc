#include <vector>
#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

class Solution {
public:
    const static vector<pair<int, int>> DIRECTION;
    const static int EDGE = -2;
    const static int INNER = -1;

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        auto checkGrid = grid;
        int source = grid[r0][c0];
        const int ROWS = grid.size(), COLS = grid[0].size();
        std::queue<pair<int, int>> q;
        q.push({ r0, c0 });

        while (!q.empty()) {
            int r, c, dr, dc;
            std::tie(r, c) = q.front();

            int neighbours = 0;
            for (auto &d: DIRECTION) {
                std::tie(dr, dc) = d;

                if (r + dr >= 0 && r + dr < ROWS &&
                    c + dc >= 0 && c + dc < COLS) {
                    if (grid[r + dr][c + dc] == source) {
                        neighbours++;
                    }
                    if (checkGrid[r + dr][c + dc] == source) {
                        q.push({ r + dr, c + dc });
                    }
                }
            }
            checkGrid[r][c] = neighbours != 4 ? EDGE : INNER;
            q.pop();
        }

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[r].size(); c++) {
                if (checkGrid[r][c] == EDGE) {
                    grid[r][c] = color;
                }
            }
        }

        return grid;
    }
};

const vector<pair<int, int>> Solution::DIRECTION = {
    { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 }
};

int main() {
    vector<tuple<vector<vector<int>>, int, int, int>> testCases {
        { {{1,1},{1,2}}, 0, 0, 3 },
        { {{1,2,2},{2,3,2}}, 0, 1, 3},
        { {{1,1,1},{1,1,1},{1,1,1}}, 1, 1, 2}
    };
    for (auto &testCase: testCases) {
        for (auto &r: Solution().colorBorder(get<0>(testCase), get<1>(testCase), get<2>(testCase), get<3>(testCase))) {
            for (auto &x: r) {
                cout << x << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
