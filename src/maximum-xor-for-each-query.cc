#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> getMaximumXor(vector<int> &nums, int maximumBit) {
    int n = nums.size();
    int ret = (1 << maximumBit) - 1;
    vector<int> arr(n);
    arr[0] = nums[0];
    for (int i = 1; i < n; i++) {
      arr[i] = arr[i - 1] ^ nums[i];
    }
    for (int i = 0; i < n; i++) {
      arr[i] ^= ret;
    }
    reverse(arr.begin(), arr.end());
    return arr;
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
    int maximumBit = stringToInteger(line);

    vector<int> ret = Solution().getMaximumXor(nums, maximumBit);

    string out = integerVectorToString(ret);
    cout << out << endl;
  }
  return 0;
}
