#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumSum(int num) {
    vector<int> nums;
    while (num != 0) {
      nums.push_back(num % 10);
      num /= 10;
    }
    std::sort(nums.begin(), nums.end());
    return 10 * nums[0] + 10 * nums[1] + nums[2] + nums[3];
  }
};

int stringToInteger(string input) { return stoi(input); }

int main() {
  string line;
  while (getline(cin, line)) {
    int num = stringToInteger(line);

    int ret = Solution().minimumSum(num);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
