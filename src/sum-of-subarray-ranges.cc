#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  long long subArrayRanges(vector<int> &nums) {
    long long res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int minN = nums[i];
      int maxN = nums[i];
      for (int j = i + 1; j < nums.size(); ++j) {
        maxN = max(maxN, nums[j]);
        minN = min(minN, nums[j]);
        res += (maxN - minN);
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> testCases{{1, 2, 3}, {1, 3, 3}, {4, -2, -3, 4, 1}};
  for (auto &testCase : testCases) {
    cout << Solution().subArrayRanges(testCase) << endl;
  }
  return 0;
}
