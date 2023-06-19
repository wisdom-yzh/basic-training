#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minSwaps(vector<int> &nums) {
    int len = 0;
    for (const auto &num : nums) {
      if (num == 1) {
        len++;
      }
    }

    int left = 0, right = len - 1, zeroCount = 0;
    for (int i = left; i <= right; i++) {
      if (nums[i] == 0) {
        zeroCount++;
      }
    }

    int res = zeroCount;
    while (left != nums.size()) {
      if (nums[left] == 0) {
        zeroCount--;
      }
      left++;
      right++;
      if (right == nums.size()) {
        right = 0;
      }
      if (nums[right] == 0) {
        zeroCount++;
      }

      res = std::min(res, zeroCount);
    }

    return res;
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

    int ret = Solution().minSwaps(nums);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
