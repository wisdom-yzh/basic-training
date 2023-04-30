#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> getAverages(vector<int> &nums, int k) {
    int size = (k * 2) + 1;
    if (nums.size() < size) {
      return vector<int>(nums.size(), -1);
    }
    vector<uint64_t> sum(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++) {
      sum[i] += sum[i - 1];
    }
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
      if (i - k < 0 || i + k >= nums.size()) {
        res.push_back(-1);
        continue;
      }
      res.push_back((sum[i + k] - (i - k == 0 ? 0 : sum[i - k - 1])) / size);
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
    int k = stringToInteger(line);

    vector<int> ret = Solution().getAverages(nums, k);

    string out = integerVectorToString(ret);
    cout << out << endl;
  }
  return 0;
}
