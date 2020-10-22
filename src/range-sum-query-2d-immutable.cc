#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        for (size_t i = 0; i < matrix.size(); i++) {
            int leftAcc = 0, rightAcc = 0;
            const size_t size = matrix[i].size();
            leftSum.push_back({});
            rightSum.push_back({});
            for (size_t j = 0; j < size; j++) {
                leftAcc += matrix[i][j];
                rightAcc += matrix[i][size - 1 - j];
                leftSum[i].push_back(leftAcc);
                rightSum[i].push_back(rightAcc);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int p = row1; p <= row2; p++) {
            sum += sumRange(p, col1, col2);
        }
        return sum;
    }

    int sumRange(int row, int i, int j) {
        auto &leftSumRow = leftSum[row], &rightSumRow = rightSum[row];
        int size = leftSumRow.size();
        int total = leftSumRow[size - 1];
        
        return total - (i > 0 ? leftSumRow[i - 1] : 0) - ((j < size - 1) ? rightSumRow[size - 2 - j] : 0);
   }

private:
    vector<vector<int>> leftSum, rightSum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
int main() {
    vector<vector<int>> mat = {
       {3, 0, 1, 4, 2},
       {5, 6, 3, 2, 1},
       {1, 2, 0, 1, 5},
       {4, 1, 0, 1, 7},
       {1, 0, 3, 0, 5}
    };
    NumMatrix matrix(mat);
    cout << matrix.sumRegion(2, 1, 4, 3) << endl;
    cout << matrix.sumRegion(1, 1, 2, 2) << endl;
    cout << matrix.sumRegion(1, 2, 2, 4) << endl;
    return 0;
}
