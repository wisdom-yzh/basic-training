#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  long long minimalKSum(vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end());
    auto last = std::unique(nums.begin(), nums.end());
    nums.erase(last, nums.end());

    long long sum = 0, i = 1, j = 0;

    while (k > 0) {
      if (j >= nums.size()) {
        break;
      }
      long long n = nums[j] - 1;

      if (n - i + 1 > k) {
        break;
      }

      sum += (n - i + 1) * (i + n) / 2l;

      k -= (n - i + 1);
      i = nums[j] + 1;
      j++;
    }

    sum += ((i) + (i + k - 1)) * k / 2l;
    return sum;
  }
};

int main(int argc, char *argv[]) {
  vector<pair<vector<int>, int>> testCases{
      {{1, 4, 25, 10, 25}, 2},
      {{5, 6}, 6},
      {{96, 44, 99, 25, 61, 84, 88, 18, 19, 33, 60, 86,  52, 19,
        32, 47, 35, 50, 94, 17, 29, 98, 22, 21, 72, 100, 40, 84},
       35},
  };
  for (auto [nums, k] : testCases) {
    cout << Solution().minimalKSum(nums, k) << endl;
  }
  return 0;
}
