#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> qs;
        int y = king[0], x = king[1];
        int s = std::max(std::max(y, x), std::max(8 - y, 8 - x));
        vector<bool> foundQueue(8, false);
        int D[8][2] {
            {-1,-1},{-1,0}, {-1,1},
            {0,-1},         {0,1},
            {1,-1}, {1,0},  {1,1},
        };

        vector<vector<bool>> grid(8, vector<bool>(8, false));
        for (auto &q: queens) {
            grid[q[0]][q[1]] = true;
        }

        for (int i = 1; i < s; i++) {
            for (int j = 0; j < 8; j++) {
                if (foundQueue[j]) {
                    continue;
                }
                int ny = king[0] + (i * D[j][0]);
                int nx = king[1] + (i * D[j][1]);
                if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8 && grid[ny][nx]) {
                    foundQueue[j] = true;
                    qs.push_back({ ny, nx });
                }
            }
        }

        return qs;
    }
};

int main() {
    vector<pair<vector<vector<int>>, vector<int>>> testCases {
        {{{0,1},{1,0},{4,0},{0,4},{3,3},{2,4}}, {0,0}},
        {{{0,0},{1,1},{2,2},{3,4},{3,5},{4,4},{4,5}}, {3,3}},
        {{{5,6},{7,7},{2,1},{0,7},{1,6},{5,1},{3,7},{0,3},{4,0},{1,2},{6,3},{5,0},
          {0,4},{2,2},{1,1},{6,4},{5,4},{0,0},{2,6},{4,5},{5,2},{1,4},{7,5},{2,3},
          {0,5},{4,2},{1,0},{2,7},{0,1},{4,6},{6,1},{0,6},{4,3},{1,7}}, {3,4}}
    };
    for (auto &testCase: testCases) {
        for (auto &item: Solution().queensAttacktheKing(testCase.first, testCase.second)) {
            cout << '[' << item[0] << ',' << item[1] << ']' << endl;
        }
        cout << endl;
    }
    return 0;
}
