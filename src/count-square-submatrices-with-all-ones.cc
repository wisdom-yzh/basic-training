#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();

        int res = 0;
        for (int i = 0; i < ROWS; i++) {
            res += matrix[i][0];
        }
        for (int i = 0; i < COLS; i++) {
            res += matrix[0][i];
        }

        res -= matrix[0][0];

        for (int i = 1; i < ROWS; i++) {
            for (int j = 1; j < COLS; j++) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] = min(min(matrix[i - 1][j], matrix[i][j - 1]), matrix[i - 1][j - 1]) + 1;
                    res += matrix[i][j];
                }
            }
        }
        return res;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {
          {1,0,1},
          {1,1,0},
          {1,1,0}
        },
        {
          {0,1,1,1},
          {1,1,1,1},
          {0,1,1,1}
        },
    };
    for (auto &testCase: testCases) {
        cout << Solution().countSquares(testCase) << endl;
    }
    return 0;
}
