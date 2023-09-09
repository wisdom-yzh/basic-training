#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumTop(vector<int> &nums, int k) {
    if (nums.size() == 0) {
      return -1;
    }
    if (k == 0) {
      return nums[0];
    }
    if (nums.size() == 1 && k % 2 != 0) {
      return -1;
    }
    if (nums.size() < k) {
      return *std::max_element(nums.begin(), nums.end());
    }

    int res = 0;
    for (int i = 0; i < k - 1; i++) {
      res = std::max(nums[i], res);
    }
    return std::max(nums[k], res);
  }
};

int main(int argc, char *argv[]) {
  std::vector<pair<vector<int>, int>> testCases{{{5, 2, 2, 4, 0, 6}, 4},
                                                {{2}, 1}};
  for (auto &[num, k] : testCases) {
    cout << Solution().maximumTop(num, k) << endl;
  }
  return 0;
}
