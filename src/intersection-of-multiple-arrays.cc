#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> intersection(vector<vector<int>> &nums) {
    std::map<int, int> dict;

    for (auto &list : nums) {
      for (auto &num : list) {
        dict[num]++;
      }
    }

    vector<int> res;
    for (auto &[k, v] : dict) {
      if (v == nums.size()) {
        res.push_back(k);
      }
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<vector<int>>> testCases{
      {{3, 1, 2, 4, 5}, {1, 2, 3, 4}, {3, 4, 5, 6}}, {{1, 2, 3}, {4, 5, 6}}};
  for (auto &nums : testCases) {
    for (auto &x : Solution().intersection(nums)) {
      cout << x << ' ';
    }
    cout << endl;
  }
  return 0;
}
