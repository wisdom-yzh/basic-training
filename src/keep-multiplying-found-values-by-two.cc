#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findFinalValue(vector<int> &nums, int original) {
    while (true) {
      bool found = false;
      for (auto &num : nums) {
        if (num == original) {
          original *= 2;
          found = true;
          break;
        }
      }
      if (!found) {
        break;
      }
    }
    return original;
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
    int original = stringToInteger(line);

    int ret = Solution().findFinalValue(nums, original);

    string out = to_string(ret);
    cout << out << endl;
  }

  return 0;
}
