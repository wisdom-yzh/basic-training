#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
using namespace std;

class Solution {
public:
  int minimumDifference(vector<int> &nums, int k) {
    int res = std::numeric_limits<int>::max();
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - k + 1; i++) {
      res = std::min(res, nums[i + k - 1] - nums[i]);
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

int stringToInteger(string input) { return stoi(input); }

int main() {
  string line;
  while (getline(cin, line)) {
    vector<int> nums = stringToIntegerVector(line);
    getline(cin, line);
    int k = stringToInteger(line);

    int ret = Solution().minimumDifference(nums, k);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
