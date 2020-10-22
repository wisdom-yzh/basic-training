#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        if (!A.size()) {
            return 0;
        }

        int result = 0;
        bool findMore = false;
        const int ROWS = A.size(), COLS = A[0].size();

        do {
            result = 0;
            findMore = false;

            // flip cols
            for (int j = 0; j < COLS; j++) {
                int numOfZero = 0;
                for (int i = 0; i < ROWS; i++) {
                    if (A[i][j] == 0) numOfZero++;
                }
                if (numOfZero > ROWS / 2) {
                    flipCol(A, j);
                    findMore = true;
                }
            }

            // flip rows
            for (int i = 0; i < ROWS; i++) {
                int row = static_cast<uint32_t>(calcRow(A[i]));
                int flipped = ((1 << COLS) - 1) & (~row);
                if (flipped > row) {
                    findMore = true;
                    flipRow(A[i]);
                    result += flipped;
                } else {
                    result += row;
                }
            }
        } while (findMore);

        return result;
    }

    void flipCol(vector<vector<int>> &A, int col) {
        for (int i = 0; i < A.size(); i++) {
            A[i][col] = 1 - A[i][col];
        }
    }

    void flipRow(vector<int> &row) {
        for (auto &el: row) {
            el = 1 - el;
        }
    }

    int calcRow(vector<int> &row) {
        int sum = 0;
        for (int i = row.size() - 1; i >= 0; i--) {
            sum += (row[i] << (row.size() - 1 - i));
        }
        return sum;
    }
};

int main() {
    vector<vector<int>> M {
        { 0,0,1,1 },
        { 1,0,1,0 },
        { 1,1,0,0 }
    };
    cout << Solution().matrixScore(M);
    return 0;
}
