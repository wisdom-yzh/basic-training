#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int mostFrequent(vector<int> &nums, int key) {
    map<int, int> dict;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] == key) {
        dict[nums[i + 1]]++;
      }
    }

    int res = 0, maxVal = 0;
    for (auto &[k, v] : dict) {
      if (v > maxVal) {
        maxVal = v;
        res = k;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::pair<vector<int>, int>> testCases{
      {{1, 100, 200, 1, 100}, 1},
      {{2, 2, 2, 2, 3}, 2},
  };
  for (auto &[nums, key] : testCases) {
    cout << Solution().mostFrequent(nums, key) << endl;
  }
  return 0;
}
