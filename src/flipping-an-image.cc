#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> result(A.size(), vector<int>(A.size(), 0));

        for (int r = 0; r < A.size(); r++) {
            for (int c = A.size() - 1; c >= 0; c--) {
                result[r][c] = 1 - A[r][A.size() - 1 - c];
            }
        }

        return result;
    }
};

int main() {
    return 0;
}
