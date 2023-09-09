#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool divideArray(vector<int> &nums) {
    if ((nums.size() % 2) != 0) {
      return false;
    }

    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i += 2) {
      if (nums[i] != nums[i + 1]) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> testCases{{3, 2, 3, 2, 2, 2}, {1, 2, 3, 4}};
  for (auto &testCase : testCases) {
    cout << boolalpha << Solution().divideArray(testCase) << endl;
  }
  return 0;
}
