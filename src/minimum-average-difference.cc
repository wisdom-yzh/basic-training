#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <limits>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumAverageDifference(vector<int> &nums) {
    if (nums.size() == 1) {
      return 0;
    }

    int64_t diff = std::numeric_limits<int64_t>::max();
    int diffIndex = -1;
    int64_t prefix = 0,
            appendix = std::accumulate(nums.begin(), nums.end(), 0L);

    for (int64_t i = 0; i < nums.size(); i++) {
      prefix += nums[i];
      appendix -= nums[i];
      int64_t newDiff =
          i == nums.size() - 1
              ? std::abs(static_cast<int64_t>(prefix / nums.size()))
              : static_cast<int64_t>(
                    std::abs(std::floor(prefix / (i + 1L)) -
                             std::floor(appendix / (nums.size() - 1L - i))));

      if (newDiff < diff) {
        diff = newDiff;
        diffIndex = i;
      }
    }

    return diffIndex;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> testCases{{4, 2, 0}, {2, 5, 3, 9, 5, 3}, {0}};
  for (auto &nums : testCases) {
    cout << Solution().minimumAverageDifference(nums) << endl;
  }
  return 0;
}
