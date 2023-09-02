#include <bits/stdc++.h>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findKDistantIndices(vector<int> &nums, int key, int k) {
    vector<int> res;
    int p = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == key) {
        for (int x = std::max(i - k, p);
             x <= std::min(i + k, static_cast<int>(nums.size()) - 1); x++) {
          res.push_back(x);
          p = x + 1;
        }
      }
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<tuple<vector<int>, int, int>> testCases{
      {{3, 4, 9, 1, 3, 9, 5}, 9, 1},
      {{2, 2, 2, 2, 2}, 2, 2},
  };
  for (auto &[nums, key, k] : testCases) {
    for (auto &x : Solution().findKDistantIndices(nums, key, k)) {
      cout << x << ' ';
    }
    cout << endl;
  }
  return 0;
}
