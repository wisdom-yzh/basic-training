#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int waysToSplitArray(vector<int> &nums) {
    vector<int64_t> preSum(nums.size());
    preSum[0] = nums[0];
    for (size_t i = 1; i < nums.size(); i++) {
      preSum[i] = preSum[i - 1] + nums[i];
    }

    int res = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (preSum[i] >= preSum[nums.size() - 1] - preSum[i]) {
        res++;
      }
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> testCases{{10, 4, -8, 7}, {2, 3, 1, 0}};
  for (auto &nums : testCases) {
    cout << Solution().waysToSplitArray(nums) << endl;
  }
  return 0;
}
