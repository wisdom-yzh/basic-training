#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int res = 0;
        for (int i = 0; i < mat.size(); i++) {
            res += mat[i][i] + mat[i][mat.size() - 1 - i];
        }
        if (mat.size() % 2 != 0) {
            res -= mat[mat.size() / 2][mat.size() / 2];
        }
        return res;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{1,2,3},{4,5,6},{7,8,9}},
        {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}}
    };
    for (auto &testCase: testCases) {
        cout << Solution().diagonalSum(testCase) << endl;
    }
    return 0;
}
