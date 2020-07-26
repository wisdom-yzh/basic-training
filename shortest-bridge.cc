#include <vector>
#include <queue>
#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    static vector<pair<int, int>> direction;

    int shortestBridge(vector<vector<int>>& A) {
        int minDist = std::numeric_limits<int>::max();
        vector<vector<int>> dist(A.size(), vector<int>(A[0].size(), std::numeric_limits<int>::max()));
        std::queue<pair<int, int>> q;

        findIsland(A, dist, q);
        while (!q.empty()) {
            auto &front = q.front();

            for (const auto &d: direction) {
                auto nextPoint = make_pair(front.first + d.first, front.second + d.second);
                if (nextPoint.first >= 0 && nextPoint.first < A.size() &&
                    nextPoint.second >= 0 && nextPoint.second < A[0].size()) {
                    if (A[nextPoint.first][nextPoint.second] == 1) {
                        minDist = std::min(minDist, dist[front.first][front.second]);
                    } else {
                        dist[nextPoint.first][nextPoint.second] = std::min(
                            dist[nextPoint.first][nextPoint.second],
                            1 + dist[front.first][front.second]
                        );
                        if (A[nextPoint.first][nextPoint.second] != -1) {
                            A[nextPoint.first][nextPoint.second] = -1;
                            q.push(nextPoint);
                        }
                    }
                }
            }
            q.pop();
        }

        return minDist;
    }

    void findIsland(vector<vector<int>> &A, vector<vector<int>> &dist, std::queue<pair<int, int>> &q) {
        std::queue<pair<int, int>> island;

        for (int r = 0; r < A.size() && island.empty(); r++) {
            for (int c = 0; c < A[0].size() && island.empty(); c++) {
                if (A[r][c] == 1) {
                    A[r][c] = -1;
                    island.push({ r, c });
                    dist[r][c] = 0;
                }
            }
        }

        while (!island.empty()) {
            q.push(island.front());
            auto &point = island.front();

            for (const auto &d: direction) {
                auto nextPoint = make_pair(point.first + d.first, point.second + d.second);
                if (nextPoint.first >= 0 && nextPoint.first < A.size() &&
                    nextPoint.second >= 0 && nextPoint.second < A[0].size() &&
                    A[nextPoint.first][nextPoint.second] == 1) {
                    A[nextPoint.first][nextPoint.second] = -1;
                    dist[nextPoint.first][nextPoint.second] = 0;
                    island.push(nextPoint);
                }
            }
            island.pop();
        }
    }
};

vector<pair<int, int>> Solution::direction = {
    { -1, 0 },
    { 1, 0 },
    { 0, 1 },
    { 0, -1 }
};

int main() {
    vector<vector<vector<int>>> testCases {
        // {{0,1},{1,0}},
        // {{0,1,0},{0,0,0},{0,0,1}},
        // {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}},
        {{0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0},
         {0,0,0,1,1,0,1,0,0},
         {0,0,0,1,0,0,1,1,0},
         {0,0,0,0,0,1,1,0,0},
         {0,0,0,0,0,1,0,0,0},
         {0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0}}
    };
    for (auto &testCase: testCases) {
        cout << Solution().shortestBridge(testCase) << endl;
    }
    return 0;
}
