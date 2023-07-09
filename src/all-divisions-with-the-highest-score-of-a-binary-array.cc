#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> maxScoreIndices(vector<int> &nums) {
    vector<int> left(nums.size() + 1, 0), right(nums.size() + 1, 0);
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        left[i + 1] = left[i] + 1;
      } else {
        left[i + 1] = left[i];
      }
      if (nums[nums.size() - 1 - i] == 1) {
        right[nums.size() - 1 - i] = right[nums.size() - i] + 1;
      } else {
        right[nums.size() - 1 - i] = right[nums.size() - i];
      }
    }
    vector<int> res;
    int val = 0;
    for (int i = 0; i < left.size(); i++) {
      if (res.empty()) {
        res.push_back(i);
        val = left[i] + right[i];
        continue;
      }

      if (val == left[i] + right[i]) {
        res.push_back(i);
      } else if (val < left[i] + right[i]) {
        res.clear();
        res.push_back(i);
        val = left[i] + right[i];
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

string integerVectorToString(vector<int> list, int length = -1) {
  if (length == -1) {
    length = list.size();
  }

  if (length == 0) {
    return "[]";
  }

  string result;
  for (int index = 0; index < length; index++) {
    int number = list[index];
    result += to_string(number) + ", ";
  }
  return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
  string line;
  while (getline(cin, line)) {
    vector<int> nums = stringToIntegerVector(line);

    vector<int> ret = Solution().maxScoreIndices(nums);

    string out = integerVectorToString(ret);
    cout << out << endl;
  }
  return 0;
}
