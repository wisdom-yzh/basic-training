#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  int triangularSum(vector<int> &nums) {
    if (nums.size() == 1) {
      return nums[0];
    }

    vector<int> newNums(nums.size() - 1, 0);
    for (size_t i = 0; i < nums.size() - 1; i++) {
      newNums[i] = (nums[i] + nums[i + 1]) % 10;
    }
    return triangularSum(newNums);
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> testCases{{1, 2, 3, 4, 5}, {5}};
  for (auto &nums : testCases) {
    cout << Solution().triangularSum(nums) << endl;
  }
  return 0;
}
