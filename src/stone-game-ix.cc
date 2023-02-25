#include <algorithm>
#include <array>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
  bool stoneGameIX(vector<int> &stones) {
    std::array<int, 3> s{0, 0, 0};
    for (auto &i : stones) {
      s[i % 3]++;
    }

    if (s[0] % 2 == 0) {
      return s[1] != 0 && s[2] != 0;
    }

    return s[2] > s[1] + 2 || s[1] > s[2] + 2;
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

string boolToString(bool input) { return input ? "True" : "False"; }

int main() {
  string line;
  while (getline(cin, line)) {
    vector<int> stones = stringToIntegerVector(line);

    bool ret = Solution().stoneGameIX(stones);

    string out = boolToString(ret);
    cout << out << endl;
  }
  return 0;
}
