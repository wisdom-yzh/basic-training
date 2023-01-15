#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
  int sumOfBeauties(vector<int> &nums) {
    int res = 0;
    vector<int> leftMax(nums.size()), rightMin(nums.size());

    leftMax[0] = nums[0];
    rightMin[nums.size() - 1] = nums[nums.size() - 1];

    for (int i = 1; i < nums.size(); i++) {
      leftMax[i] = std::max(leftMax[i - 1], nums[i]);
      rightMin[nums.size() - 1 - i] =
          std::min(rightMin[nums.size() - i], nums[nums.size() - 1 - i]);
    }

    for (int i = 1; i <= nums.size() - 2; i++) {
      if (nums[i] > leftMax[i - 1] && nums[i] < rightMin[i + 1]) {
        res += 2;
      } else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1]) {
        res += 1;
      }
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

    int ret = Solution().sumOfBeauties(nums);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
