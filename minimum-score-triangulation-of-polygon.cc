#include <vector>
#include <limits>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> memo;

    int minScoreTriangulation(vector<int>& A) {
        memo.assign(A.size(), vector<int>(A.size(), -1));
        return dp(A, 0, A.size() - 1);
    }

    int dp(vector<int> &A, int p, int q) {
        if (q - p <= 1) {
            return 0;
        }

        if (memo[p][q] != -1) {
            return memo[p][q];
        }

        int minValue = std::numeric_limits<int>::max();
        for (int k = p + 1; k < q; k++) {
            minValue = std::min(minValue, dp(A, p, k) + dp(A, k, q) + A[p] * A[k] * A[q]);
        }

        memo[p][q] = memo[q][p] = minValue;
        return memo[p][q];
    }
};

int main() {
    vector<vector<int>> testCases {
        { 1,2,3 },
        { 3,7,4,5 },
        { 1,3,1,4,1,5 }
    };
    for (auto &testCase: testCases) {
        cout << Solution().minScoreTriangulation(testCase) << endl;
    }
    return 0;
}
