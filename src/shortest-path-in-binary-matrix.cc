#include <vector>
#include <queue>
#include <iostream>
#include <tuple>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) {
            return -1;
        }
        const vector<pair<int, int>> DIRECTIONS = {
            { -1, -1 }, { -1, 0 }, { -1, 1 },
            { 0, -1 },             { 0, 1 },
            { 1, -1 }, { 1, 0 }, { 1, 1 },
        };
        const int ROWS = grid.size(), COLS = grid[0].size();
        vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), -1));
        std::queue<pair<int, int>> q;

        memo[0][0] = 1;
        q.push({ 0, 0 });

        while (!q.empty()) {
            int r, c, nr, nc;
            std::tie(r, c) = q.front();
            for (const auto &d: DIRECTIONS) {
                nr = r + d.first;
                nc = c + d.second;
                if (nr < ROWS && nc < COLS && nr >= 0 && nc >= 0 && grid[nr][nc] == 0) {
                    if (memo[nr][nc] == -1) {
                        q.push({ nr, nc });
                        memo[nr][nc] = memo[r][c] + 1;
                    } else {
                        memo[nr][nc] = std::min(memo[nr][nc], memo[r][c] + 1);
                    }
                }
            }

            grid[r][c] = 1;
            q.pop();
        }

        return memo.back().back();
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{0,1}, {1, 0}},
        {{0,0,0},{1,1,0},{1,1,0}}
    };
    for (auto &testCase: testCases) {
        cout << Solution().shortestPathBinaryMatrix(testCase) << endl;
    }
    return 0;
}
