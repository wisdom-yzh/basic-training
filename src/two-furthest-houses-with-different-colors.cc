#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int maxDistance(vector<int> &colors) {
    int l = 0, r = colors.size() - 1, n = colors.size();

    while (colors[n - 1] == colors[l] && l < n) {
      l++;
    }
    while (r >= 0 && colors[r] == colors[0]) {
      r--;
    }

    return std::max(r, n - 1 - l);
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
    vector<int> colors = stringToIntegerVector(line);

    int ret = Solution().maxDistance(colors);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
