#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  int countHillValley(vector<int> &nums) {
    auto end = std::unique(nums.begin(), nums.end());
    vector<int> uniqNums(nums.begin(), end);
    int res = 0;

    for (int i = 1; i < uniqNums.size() - 1; i++) {
      if (uniqNums[i] > uniqNums[i - 1] && uniqNums[i] > uniqNums[i + 1] ||
          uniqNums[i] < uniqNums[i - 1] && uniqNums[i] < uniqNums[i + 1]) {
        res++;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> testCases{{2, 4, 1, 1, 6, 5}, {6, 6, 5, 5, 4, 1}};
  for (auto &testCase : testCases) {
    cout << Solution().countHillValley(testCase) << endl;
  }
  return 0;
}
