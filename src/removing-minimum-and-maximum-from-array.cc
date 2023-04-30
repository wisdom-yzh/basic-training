#include <algorithm>
#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

class Solution {
public:
  int minimumDeletions(vector<int> &nums) {
    int minIndex = 0, maxIndex = 0, minVal = nums[0], maxVal = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < minVal) {
        minVal = nums[i];
        minIndex = i;
      } else if (nums[i] > maxVal) {
        maxVal = nums[i];
        maxIndex = i;
      }
    }

    int size = nums.size();
    if (minIndex > maxIndex) {
      std::swap(minIndex, maxIndex);
    }
    return std::min(std::min(maxIndex + 1, size - minIndex),
                    size - maxIndex + minIndex + 1);
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

    int ret = Solution().minimumDeletions(nums);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
