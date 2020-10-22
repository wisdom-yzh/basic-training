#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // 要求O(1)的空间复杂度
        const int M = matrix.size();
        const int N = matrix[0].size();
        bool findZero = false;
        int zeroRow, zeroCol;

        for (auto i = 0; i < M && !findZero; i++) {
            for (auto j = 0; j < N && !findZero; j++) {
                if (matrix[i][j] == 0) {
                    findZero = true;
                    zeroRow = i;
                    zeroCol = j;
                }
            }
        }
        if (!findZero) {
            return;
        }
        for (auto i = 0; i < M; i++) {
            if (i == zeroRow) continue;
            for (auto j = 0; j < N; j++) {
                if (j == zeroCol) continue;
                if (matrix[i][j] == 0) {
                    matrix[i][zeroCol] = 0;
                    matrix[zeroRow][j] = 0;
                }
            }
        }
        for (auto i = 0; i < M; i++) {
            if (i == zeroRow) continue;
            for (auto j = 0; j < N; j++) {
                if (j == zeroCol) continue;
                if (matrix[i][zeroCol] == 0 || matrix[zeroRow][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (auto i = 0; i < M; i++) {
            matrix[i][zeroCol] = 0;
        }
        for (auto j = 0; j < N; j++) {
            matrix[zeroRow][j] = 0;
        }
    }
};

int main() {
    vector<vector<int>> mat {
        { 0, 1, 2, 0 },
        { 3, 4, 5, 2 },
        { 1, 3, 1, 5 }
    };
    Solution().setZeroes(mat);
    for (auto row: mat) {
        for (auto col: row) {
            cout << col << ',';
        }
        cout << endl;
    }
    return 0;
}
