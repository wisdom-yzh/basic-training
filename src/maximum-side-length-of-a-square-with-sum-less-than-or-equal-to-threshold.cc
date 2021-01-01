#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        const int ROWS = mat.size(), COLS = mat[0].size();
        vector<vector<int>> P(ROWS + 1, vector<int>(COLS + 1, 0));

        for (int i = 1; i <= ROWS; i++) {
            for (int j = 1; j <= COLS; j++) {
                P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }

        int R = min(ROWS, COLS), res = 0;
        for (int i = 1; i <= ROWS; i++) {
            for (int j = 1; j <= COLS; j++) {
                bool found = false;
                for (int c = res + 1; c <= R; c++) {
                    if (i + c - 1 <= ROWS && j + c - 1 <= COLS) {
                        int p = i + c - 1, q = j + c - 1;
                        if (P[p][q] - P[i - 1][q] - P[p][j - 1] + P[i - 1][j - 1] <= threshold) {
                            res++;
                            found = true;
                        }
                    }
                    if (!found) {
                        break;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    vector<pair<vector<vector<int>>, int>> testCases {
        { {{1,1,3,2,4,3,2},{1,1,3,2,4,3,2},{1,1,3,2,4,3,2}}, 4 },
        { {{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2}}, 1 },
        { {{1,1,1,1},{1,0,0,0},{1,0,0,0},{1,0,0,0}}, 6 },
        { {{18,70},{61,1},{25,85},{14,40},{11,96},{97,96},{63,45}}, 40184 },
    };
    for (auto &testCase: testCases) {
        cout << Solution().maxSideLength(testCase.first, testCase.second) << endl;
    }
    return 0;
}
