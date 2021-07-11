#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int> > row(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j == 0) {
                    row[i][j] = mat[i][j];
                } else if (mat[i][j]) {
                    row[i][j] = row[i][j - 1] + 1;
                }
                else {
                    row[i][j] = 0;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int col = row[i][j];
                for (int k = i; k >= 0 && col; --k) {
                    col = min(col, row[k][j]);
                    ans += col;
                }
            }
        }
        return ans;
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
            {0,1,1,0},
            {0,1,1,1},
            {1,1,1,0}
        },
        {
            {1,1,1,1,1,1}
        },
        {
            {1,0,1},
            {0,1,0},
            {1,0,1}
        }
    };
    for (auto &testCase: testCases) {
        cout << Solution().numSubmat(testCase) << endl;
    }
    return 0;
}
