#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        const int ROWS = mat.size(), COLS = mat[0].size();
        for (int y = ROWS - 1; y >= 0; y--) {
            sort(mat, y, 0);
        }
        for (int x = 1; x < COLS; x++) {
            sort(mat, 0, x);
        }
        return mat;
    }

    void sort(vector<vector<int>> &mat, int r, int c) {
        const int ROWS = mat.size(), COLS = mat[0].size();
        int dr = r, dc = c;
        vector<int> tmp;

        tmp.push_back(mat[r][c]);

        while (true) {
            dr++;
            dc++;
            if (dr >= ROWS || dc >= COLS) {
                break;
            }
            tmp.push_back(mat[dr][dc]);
        }

        std::sort(tmp.begin(), tmp.end());
        for (auto &x: tmp) {
            mat[r++][c++] = x;
        }
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{3,3,1,1},{2,2,1,2},{1,1,1,2}},
        {{11,25,66,1,69,7},{23,55,17,45,15,52},{75,31,36,44,58,8},{22,27,33,25,68,4},{84,28,14,11,5,50}}
    };
    for (auto &testCase: testCases) {
        for (auto &row: Solution().diagonalSort(testCase)) {
            for (auto &x: row) {
                cout << x << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
