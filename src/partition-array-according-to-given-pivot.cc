#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> pivotArray(vector<int> &nums, int pivot) {
    vector<int> left, right, middle;
    for (auto &num : nums) {
      if (num == pivot) {
        middle.push_back(num);
      } else if (num > pivot) {
        right.push_back(num);
      } else {
        left.push_back(num);
      }
    }

    std::copy(middle.begin(), middle.end(), std::back_inserter(left));
    std::copy(right.begin(), right.end(), std::back_inserter(left));
    return left;
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
    getline(cin, line);
    int pivot = stringToInteger(line);

    vector<int> ret = Solution().pivotArray(nums, pivot);

    string out = integerVectorToString(ret);
    cout << out << endl;
  }
  return 0;
}
