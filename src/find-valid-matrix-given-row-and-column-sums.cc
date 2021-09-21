#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> mat(rowSum.size(), vector<int>(colSum.size(), 0));

        for (int r = 0; r < rowSum.size(); r++) {
            for (int c = 0; c < colSum.size(); c++) {
                mat[r][c] = min(rowSum[r], colSum[c]);
                rowSum[r] -= mat[r][c];
                colSum[c] -= mat[r][c];
            }
        }

        return mat;
    }
};

int main() {
    vector<pair<vector<int>, vector<int>>> testCases {
        {
            {3, 8},
            {4, 7}
        },
        {
            {5,7,10},
            {8,6,8}
        },
        {
            {14,9},
            {6,9,8}
        },
        {
            {1,0},
            {1}
        },
        {
            {0},
            {0}
        }
    };

    for (auto &[rowSum, colSum]: testCases) {
        for (auto &r: Solution().restoreMatrix(rowSum, colSum)) {
            for (auto &c: r) {
                cout << c << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}
