#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
  int mapped(vector<int> &mapping, int num) {
    int x = 0, b = 0;
    while (num >= 0) {
      x += std::pow(10, b) * mapping[num % 10];
      b++;
      num /= 10;
      if (num == 0) {
        break;
      }
    }
    return x;
  }

  vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums) {
    unordered_map<int, int> idx, mappedNums;

    for (int i = 0; i < nums.size(); i++) {
      idx[nums[i]] = i;
      mappedNums[nums[i]] = mapped(mapping, nums[i]);
    }

    std::sort(nums.begin(), nums.end(), [&mappedNums, &idx](auto &a, auto &b) {
      if (mappedNums[a] == mappedNums[b]) {
        return idx[a] < idx[b];
      }
      return mappedNums[a] < mappedNums[b];
    });

    return nums;
  }
};

int main(int argc, char *argv[]) {
  vector<pair<vector<int>, vector<int>>> testCases{
      {{9, 8, 7, 6, 5, 4, 3, 2, 1, 0}, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}},
      {{8, 9, 4, 0, 2, 1, 3, 5, 7, 6}, {991, 338, 38}},
      {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, {789, 456, 123}},
  };
  for (auto &[m, n] : testCases) {
    for (auto &x : Solution().sortJumbled(m, n)) {
      cout << x << ' ';
    }
    cout << endl;
  }
  return 0;
}
