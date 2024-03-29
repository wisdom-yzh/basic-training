#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> sortEvenOdd(vector<int> &nums) {
    vector<int> odd, even;
    for (int i = 0; i < nums.size(); i++) {
      if ((i % 2) == 0) {
        even.push_back(nums[i]);
      } else {
        odd.push_back(nums[i]);
      }
    }
    std::sort(odd.begin(), odd.end(), std::greater<int>());
    std::sort(even.begin(), even.end(), std::less<int>());

    for (int i = 0; i < even.size(); i++) {
      nums[i * 2] = even[i];
    }
    for (int i = 0; i < odd.size(); i++) {
      nums[i * 2 + 1] = odd[i];
    }
    return nums;
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

    vector<int> ret = Solution().sortEvenOdd(nums);

    string out = integerVectorToString(ret);
    cout << out << endl;
  }
  return 0;
}
