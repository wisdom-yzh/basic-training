#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        for (int p = 0, q = matrix[0].size() - 1;
            p < (int)matrix.size() && q >= 0;) {
            int num = matrix[p][q];
            if (target == num) {
                return true;
            } else if (target > num) {
                p++;
            } else {
                q--;
            }
        }
        return false;
    }
};

int main() {
    return 0;
}
