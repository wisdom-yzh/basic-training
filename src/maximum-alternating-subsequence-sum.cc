#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
public:
  long long maxAlternatingSum(vector<int> &nums) {
    int n = nums.size();
    long long odd = 0, even = nums[0];
    for (int i = 1; i < n; ++i) {
      tie(odd, even) =
          tuple{max(even - nums[i], odd), max(odd + nums[i], even)};
    }
    return even;
  }
};

int main() {
  auto testCases{
      vector<vector<int>>{{4, 2, 5, 3}, {5, 6, 7, 8}, {6, 2, 1, 2, 4, 5}}};

  for (auto &testCase : testCases) {
    cout << Solution().maxAlternatingSum(testCase) << endl;
  }
  return 0;
}
