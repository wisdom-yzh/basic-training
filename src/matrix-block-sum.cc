#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        const int ROWS = mat.size(), COLS = mat[0].size();
        vector<vector<int>> res(ROWS, vector<int>(COLS));

        for (int y = 0; y < ROWS; y++) {
            for (int x = 0; x < COLS; x++) {
                res[y][x] = sum(mat, K, y, x);
            }
        }

        return res;
    }

    int sum(vector<vector<int>>& mat, int K, int y, int x) {
        const int ROWS = mat.size(), COLS = mat[0].size();
        int res = 0;
        for (int yy = std::max(0, y - K); yy <= std::min(y + K, ROWS - 1); yy++) {
            for (int xx = std::max(0, x - K); xx <= std::min(x + K, COLS - 1); xx++) {
                res += mat[yy][xx];
            }
        }
        return res;
    }
};

int main() {
    vector<pair<vector<vector<int>>, int>> testCases {
        { {{1,2,3},{4,5,6},{7,8,9}}, 1 },
        { {{1,2,3},{4,5,6},{7,8,9}}, 2 }
    };
    for (auto &testCase: testCases) {
        for (auto &row: Solution().matrixBlockSum(testCase.first, testCase.second)) {
            for (auto &x: row) {
                cout << x << ' ';
            }
            cout << "\n";
        }
        cout << "\n\n";
    }
    return 0;
}
