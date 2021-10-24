#include <vector>
#include <queue>
#include <limits>
#include <iostream>
#include <cmath>
#include <tuple>
using namespace std;

class Solution {
public:
    const pair<int, int> direction[4] { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1} };

    int minimumEffortPath(vector<vector<int>>& heights) {
        const int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> minValue(rows, vector<int>(cols, std::numeric_limits<int>::max()));
        minValue[0][0] = 0;

        std::queue<pair<int, int>> q;
        q.push(make_pair(0, 0));

        while (!q.empty()) {
            auto &[r, c] = q.front();

            for (auto &[dr, dc]: direction) {
                if (r + dr >= 0 && r + dr < rows &&
                    c + dc >= 0 && c + dc < cols) {
                    int val = std::max(minValue[r][c], std::abs(heights[r + dr][c + dc] - heights[r][c]));
                    if (val >= minValue[r + dr][c + dc]) {
                        continue;
                    }
                    minValue[r + dr][c + dc] = val;
                    q.push(make_pair(r + dr, c + dc));
                }
            }
            q.pop();
        }

        return minValue[rows - 1][cols - 1];
    }
};

auto main() -> int {
    vector<vector<vector<int>>> testCases {
        {{4,3,4,10,5,5,9,2},{10,8,2,10,9,7,5,6},{5,8,10,10,10,7,4,2},{5,1,3,1,1,3,1,9},{6,4,10,6,10,9,4,6}},
        {{1,2,2},{3,8,2},{5,3,5}},
        {{1,2,3},{3,8,4},{5,3,5}},
        {{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}}
    };
    for (auto &testCase: testCases) {
        cout << Solution().minimumEffortPath(testCase) << endl;
    }
    return 0;
}
