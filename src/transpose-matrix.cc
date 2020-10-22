#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int row = A.size(), col = A[0].size();
        vector<vector<int>> T(col, vector<int>(row));

        for (int r = 0; r < A.size(); r++) {
            for (int c = 0; c < A[0].size(); c++) {
                T[c][r] = A[r][c];
            }
        }

        return T;
    }
};

int main() {
    return 0;
}
