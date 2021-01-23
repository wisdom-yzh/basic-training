#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        const int M = matrix.size(), N = matrix[0].size();
        vector<int> minValueColOfRow(M, 0);
        vector<int> result;

        for (int y = 0; y < M; y++) {
            int minCol = 0, minValue = matrix[y][0];
            for (int x = 1; x < N; x++) {
                if (matrix[y][x] < minValue) {
                    minValue = matrix[y][x];
                    minCol = x;
                }
            }
            minValueColOfRow[y] = minCol;
        }

        for (int x = 0; x < N; x++) {
            int maxRow = 0, maxValue = matrix[0][x];
            for (int y = 1; y < M; y++) {
                if (matrix[y][x] > maxValue) {
                    maxValue = matrix[y][x];
                    maxRow = y;
                }
            }

            if (minValueColOfRow[maxRow] == x) {
                result.push_back(matrix[maxRow][x]);
            }
        }

        return result;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{3,7,8},{9,11,13},{15,16,17}},
        {{1,10,4,2},{9,3,8,7},{15,16,17,12}},
        {{7,8},{1,2}}
    };
    for (auto &testCase: testCases) {
        for (auto &x: Solution().luckyNumbers(testCase)) {
            cout << x << endl;
        }
    }
    return 0;
}
