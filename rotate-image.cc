#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void rotateElement(vector<vector<int>> &matrix, int row, int col) {
        int currentRow = row, currentCol = col, currentValue = matrix[row][col];
        int nextRow, nextCol, nextValue;

        while (true) {
            nextRow = currentCol;
            nextCol = matrix.size() - 1 - currentRow;
            nextValue = matrix[nextRow][nextCol];
            matrix[nextRow][nextCol] = currentValue;
            if (nextRow == row && nextCol == col) {
                break;
            }
            currentRow = nextRow;
            currentCol = nextCol;
            currentValue = nextValue;
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        const int SIZE = matrix.size();
        if (SIZE == 0 || SIZE == 1) {
            return;
        }

        int rotateRow, rotateCol;
        if ((SIZE & 1) == 0) {
            rotateRow = rotateCol = SIZE >> 1;
        } else {
            rotateRow = SIZE >> 1;
            rotateCol = rotateRow + 1;
        }

        for (auto row = 0; row < rotateRow; row++) {
            for (auto col = 0; col < rotateCol; col++) {
                this->rotateElement(matrix, row, col);
            }
        }
    }
};

int main () {
    vector<vector<int>> mat {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    Solution().rotate(mat);
    for (auto row: mat) {
        for (auto col: row) {
            cout << col << ',';
        }
        cout << endl;
    }
    return 0;
}
