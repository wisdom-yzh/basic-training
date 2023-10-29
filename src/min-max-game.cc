#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  int minMaxGame(vector<int> &nums) {
    if (nums.size() == 1) {
      return nums[0];
    }

    vector<int> newNums(nums.size() / 2, 0);
    for (size_t i = 0; i < nums.size() / 2; i++) {
      if (i % 2 == 0) {
        newNums[i] = std::min(nums[2 * i], nums[2 * i + 1]);
      } else {
        newNums[i] = std::max(nums[2 * i], nums[2 * i + 1]);
      }
    }

    return minMaxGame(newNums);
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> testCases{{1, 3, 5, 2, 4, 8, 2, 2}, {3}};
  for (auto &nums : testCases) {
    cout << Solution().minMaxGame(nums) << endl;
  }
  return 0;
}
