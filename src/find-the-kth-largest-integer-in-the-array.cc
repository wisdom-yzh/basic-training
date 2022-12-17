#include <algorithm>
#include <ctime>
#include <iostream>
#include <ostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  string kthLargestNumber(vector<string> &nums, int k) {
    std::sort(nums.begin(), nums.end(), [](auto &s1, auto &s2) {
      if (s1.size() == s2.size()) {
        return s1 > s2;
      }
      return s1.size() > s2.size();
    });
    return nums[k - 1];
  }
};

int main(int argc, char *argv[]) {
  vector<pair<vector<string>, int>> testCases{
      {{"3", "6", "7", "10"}, 4}, {{"2", "21", "12", "1"}, 3}, {{"0", "0"}, 2}};

  for (auto &[nums, k] : testCases) {
    cout << Solution().kthLargestNumber(nums, k) << endl;
  }
  return 0;
}
