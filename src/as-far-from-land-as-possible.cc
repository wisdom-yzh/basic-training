#include <vector>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        const pair<int, int> DIRECTION[] {{ -1, 0 }, { 1, 0}, { 0, -1 }, { 0, 1 }};
        const int ROW = grid.size(), COL = grid[0].size();

        vector<vector<int>> dist(ROW, vector<int>(COL, -1));
        queue<vector<pair<int, int>>> q;
        q.push({});

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    q.back().push_back({ i, j });
                    dist[i][j] = 0;
                }
            }
        }

        int maxDist = -1;
        while (!q.empty() && !q.back().empty()) {
            int current = maxDist == -1 ? 1 : maxDist + 1;
            auto &arr = q.front();

            q.push({});
            for (auto &p: arr) {
                int r, c;
                std::tie(r, c) = p;

                for (int i = 0; i < 4; i++) {
                    if (r + DIRECTION[i].first >= 0 && r + DIRECTION[i].first < ROW &&
                        c + DIRECTION[i].second >= 0 && c + DIRECTION[i].second < COL &&
                        dist[r + DIRECTION[i].first][c + DIRECTION[i].second] == -1) {
                        dist[r + DIRECTION[i].first][c + DIRECTION[i].second] = current;
                        maxDist = current;
                        q.back().push_back({ r + DIRECTION[i].first, c + DIRECTION[i].second });
                    }
                }
            }

            q.pop();
        }

        return maxDist;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{1,0,1},{0,0,0},{1,0,1}},
        {{1,0,0},{0,0,0},{0,0,0}}
    };
    for (auto &testCase: testCases) {
        cout << Solution().maxDistance(testCase) << endl;
    }
    return 0;
}
