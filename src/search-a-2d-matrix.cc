#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int M = matrix.size();
        if (M == 0) return false;
        const int N = matrix[0].size();
        int i = 0, j = N - 1;
        
        while (i != M && j != -1) {
            if (matrix[i][j] > target) {
                j--;
            } else if (matrix[i][j] < target) {
                i++;
            } else {
                return true;
            }
        }

        return false;
    }
};

int main () {
    vector<vector<int>> mat {
      {1,   3,  5,  7},
      {10, 11, 16, 20},
      {23, 30, 34, 50}
    };
    cout << boolalpha << Solution().searchMatrix(mat, 3);
    return 0;
}


