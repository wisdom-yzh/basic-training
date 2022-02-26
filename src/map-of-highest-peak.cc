#include <iostream>
#include <queue>
#include <limits>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        const int ROWS = isWater.size(), COLS = isWater[0].size();
        vector<vector<int>> res(ROWS, vector<int>(COLS, std::numeric_limits<int>::max()));
        std::queue<pair<int, int>> q;

        for (int y = 0; y < ROWS; y++) {
            for (int x = 0; x < COLS; x++) {
                if (isWater[y][x]) {
                    q.push({ y, x });
                    res[y][x] = 0;
                }
            }
        }

        const vector<pair<int, int>> directions {
            { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }
        };
        while (!q.empty()) {
            auto &[y, x] = q.front();
            for (auto &[dy, dx]: directions) {
                int ny = y + dy, nx = x + dx;
                if (ny < 0 || ny >= ROWS || nx < 0 || nx >= COLS || isWater[ny][nx]) {
                    continue;
                }
                res[ny][nx] = res[y][x] + 1;
                q.push({ ny, nx });
                isWater[ny][nx] = 1;
            }
            q.pop();
        }

        return res;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{0,1},{0,0}},
        {{0,0,1},{1,0,0},{0,0,0}},
    };
    for (auto &testCase : testCases) {
        for (auto &row: Solution().highestPeak(testCase)) {
            for (auto &col: row) {
                cout << col << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
