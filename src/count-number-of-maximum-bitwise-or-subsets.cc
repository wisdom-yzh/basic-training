#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
  int countMaxOrSubsets(vector<int> &nums) {
    int maxValue = 0;
    for (const auto &num : nums) {
      maxValue |= num;
    }

    int count = 0;
    dfs(nums, 0, count, 0, maxValue);
    return count;
  }

  void dfs(const vector<int> &nums, int idx, int &count, int value,
           const int &maxValue) {

    if (value == maxValue) {
      count += 1;
      auto remains = nums.size() - idx;
      if (remains > 0) {
        count += (1 << remains) - 1;
      }
      return;
    }

    if (idx == nums.size()) {
      return;
    }

    dfs(nums, idx + 1, count, value | nums[idx], maxValue);
    dfs(nums, idx + 1, count, value, maxValue);
  }
};

void trimLeftTrailingSpaces(string &input) {
  input.erase(input.begin(), find_if(input.begin(), input.end(),
                                     [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input) {
  input.erase(
      find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); })
          .base(),
      input.end());
}

vector<int> stringToIntegerVector(string input) {
  vector<int> output;
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  stringstream ss;
  ss.str(input);
  string item;
  char delim = ',';
  while (getline(ss, item, delim)) {
    output.push_back(stoi(item));
  }
  return output;
}

int main() {
  string line;
  while (getline(cin, line)) {
    vector<int> nums = stringToIntegerVector(line);

    int ret = Solution().countMaxOrSubsets(nums);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
