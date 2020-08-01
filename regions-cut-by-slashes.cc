#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    const static vector<pair<int, int>> delta;

    int regionsBySlashes(vector<string>& grid) {
        int N = grid.size();
        vector<vector<int>> mat(N * 3, vector<int>(N * 3, 0));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                char ch = grid[i][j];
                int ii = i * 3;
                int jj = j * 3;
                if (ch == '/') {
                    mat[ii + 1][jj + 1] = mat[ii][jj + 2] = mat[ii + 2][jj] = 1;
                } else if (ch == '\\') {
                    mat[ii][jj] = mat[ii + 1][jj + 1] = mat[ii + 2][jj + 2] = 1;
                }
            }
        }

        int regions = 0;
        for (int y = 0; y < mat.size(); y++) {
            for (int x = 0; x < mat.size(); x++) {
                if (mat[y][x] == 1) {
                    continue;
                }
                regions++;
                mat[y][x] = 1;
                std::queue<pair<int, int>> q;
                q.push({ y, x });

                while (!q.empty()) {
                    auto p = q.front();
                    for (const auto &d: delta) {
                        int yy = p.first + d.first;
                        int xx = p.second + d.second;
                        if (yy >= 0 && yy < mat.size() && xx >= 0 && xx < mat.size() && mat[yy][xx] == 0) {
                            mat[yy][xx] = 1;
                            q.push({ yy, xx });
                        }
                    }
                    q.pop();
                }
            }
        }

        return regions;
    }
};

const vector<pair<int, int>> Solution::delta {
    { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 }
};



int main() {
    vector<vector<string>> testCases {
        {
          " /",
          "/ "
        },
        {
          " /",
          "  "
        },
        {
            "\\/",
            "/\\"
        }
    };

    for (auto &testCase: testCases) {
        cout << Solution().regionsBySlashes(testCase) << endl;
    }
    return 0;
}
