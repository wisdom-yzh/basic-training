#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class Solution {
public:
  static constexpr int MAX_NUM = 100;

  vector<int> minDifference(vector<int> &nums, vector<vector<int>> &queries) {
    vector<array<int, MAX_NUM + 1>> pre(nums.size() + 1);
    std::fill(pre[0].begin(), pre[0].end(), 0);
    for (int i = 0; i < nums.size(); i++) {
      std::copy_n(pre[i].begin(), MAX_NUM + 1, pre[i + 1].begin());
      pre[i + 1][nums[i]]++;
    }

    vector<int> res;
    for (auto &query : queries) {
      auto &l = query[0], &r = query[1];
      int prev = 0, minValue = -1;
      for (int i = 1; i <= MAX_NUM; i++) {
        if (pre[l][i] != pre[r + 1][i]) {
          if (prev != 0) {
            if (minValue == -1) {
              minValue = i - prev;
            } else {
              minValue = std::min(minValue, i - prev);
            }
          }
          prev = i;
        }
      }
      res.push_back(minValue);
    }

    return res;
  }
};

int main() {
  auto testCases{vector<pair<vector<int>, vector<vector<int>>>>{
      {{1, 3, 4, 8}, {{0, 1}, {1, 2}, {2, 3}, {0, 3}}},
      {{4, 5, 2, 2, 7, 10}, {{2, 3}, {0, 2}, {0, 5}, {3, 5}}},
  }};
  for (auto &[nums, queries] : testCases) {
    for (auto &x : Solution().minDifference(nums, queries)) {
      cout << x << ' ';
    }
    cout << endl;
  }
  return 0;
}
