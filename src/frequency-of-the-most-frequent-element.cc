#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxFrequency(vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end());

    int maxDist{0};
    uint32_t sum{0};
    for (int i = 0, j = 0; j < nums.size(); j++) {
      while (nums[j] * (j - static_cast<uint32_t>(i)) - sum > k) {
        sum -= nums[i];
        i++;
      }
      sum += nums[j];
      maxDist = std::max(maxDist, j - i + 1);
    }

    return maxDist;
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

    int ret = Solution().maxFrequency(nums, k);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
