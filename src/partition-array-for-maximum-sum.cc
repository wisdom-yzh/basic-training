#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size() + 1, 0);
        dp[1] = arr[0];

        for (int i = 2; i <= arr.size(); i++) {
            int maxSum = 0;
            int maxOfPartition = 0;
            for (int j = 1; j <= k && j <= i; j++) {
                maxOfPartition = std::max(maxOfPartition, arr[i - j]);
                maxSum = std::max(maxSum, dp[i - j] + j * maxOfPartition);
            }
            dp[i] = maxSum;
        }

        return dp.back();
    }
};

int main() {
    vector<pair<vector<int>, int>> testCases {
        {{1,15,7,9,2,5,10}, 3},
        {{1,4,1,5,7,3,6,1,9,9,3}, 4},
        {{1}, 1}
    };
    for (auto &testCase: testCases) {
        cout << Solution().maxSumAfterPartitioning(testCase.first, testCase.second) << endl;
    }
    return 0;
}
