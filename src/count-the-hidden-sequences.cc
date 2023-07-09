#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <limits>
using namespace std;

class Solution {
public:
  int numberOfArrays(vector<int> &differences, int lower, int upper) {
    int64_t val = 0, min = 0, max = 0;
    if (differences.size() > 1) {
      for (auto &num : differences) {
        val += num;
        min = std::min(min, val);
        max = std::max(max, val);
      }

      return std::max(static_cast<int>(upper - lower - max + min + 1), 0);
    }

    return std::max(
        static_cast<int>(upper - lower - std::abs(differences[0]) + 1), 0);
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
    vector<int> differences = stringToIntegerVector(line);
    getline(cin, line);
    int lower = stringToInteger(line);
    getline(cin, line);
    int upper = stringToInteger(line);

    int ret = Solution().numberOfArrays(differences, lower, upper);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
