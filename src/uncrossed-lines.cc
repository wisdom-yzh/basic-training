#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> memo;
    vector<int> A, B;

    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        this->memo.assign(A.size(), vector<int>(B.size(), -1));
        this->A = std::move(A);
        this->B = std::move(B);
        return this->recursiveLines(this->A.size() - 1, this->B.size() - 1);
    }

    int recursiveLines(int i, int j) {
        if (i < 0 || j < 0) {
            return 0;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int maxValue = 0;
        if (A[i] == B[j]) {
            maxValue = std::max(maxValue, recursiveLines(i - 1, j - 1) + 1);
        } else {
            maxValue = std::max(maxValue, recursiveLines(i - 1, j - 1));
        }

        maxValue = std::max(maxValue, recursiveLines(i - 1, j));
        maxValue = std::max(maxValue, recursiveLines(i, j - 1));

        memo[i][j] = maxValue;
        return maxValue;
    }
};

int main() {
    vector<pair<vector<int>, vector<int>>> testCases {
        {
            {1,4,2},
            {1,2,4},
        },
        {
            {2, 5,1,2,5},
            {10,5,2,1,5,2},
        },
        {
            {1,3,7,1,7,5},
            {1,9,2,5,1}
        }
    };

    for (auto &testCase: testCases) {
        cout << Solution().maxUncrossedLines(testCase.first, testCase.second) << endl;
    }
    return 0;
}
