#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  int minDeletion(vector<int> &nums) {
    if (nums.size() == 1) {
      return 1;
    }

    int res = 0;
    for (size_t i = 0; i < nums.size() - 1;) {
      if (nums[i] == nums[i + 1]) {
        res++;
        i++;
      } else {
        i += 2;
      }

      if (i == nums.size() - 1) {
        res++;
      }
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> testCases{{1, 1, 2, 3, 5}, {1, 1, 2, 2, 3, 3}};
  for (auto &nums : testCases) {
    std::cout << Solution().minDeletion(nums) << std::endl;
  }
  return 0;
}
