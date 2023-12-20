#include <bits/stdc++.h>
#include <cmath>
#include <limits>
#include <valarray>
#include <vector>
using namespace std;

class Solution {
public:
  int findClosestNumber(vector<int> &nums) {
    int res = -100000;
    for (auto &n : nums) {
      if (std::abs(n) < std::abs(res) ||
          std::abs(n) == std::abs(res) && n > 0) {
        res = n;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> testCases{{-4, -2, 1, 4, 8}, {2, -1, 1}};
  for (auto &nums : testCases) {
    cout << Solution().findClosestNumber(nums) << endl;
  }
  return 0;
}
