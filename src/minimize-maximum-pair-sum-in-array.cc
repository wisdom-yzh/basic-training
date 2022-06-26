#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
  int minPairSum(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    auto i{0}, j{int(nums.size() - 1)};

    auto res{0};
    while (i < j) {
      res = std::max(nums[i] + nums[j], res);
      i++;
      j--;
    }

    return res;
  };
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

    int ret = Solution().minPairSum(nums);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
