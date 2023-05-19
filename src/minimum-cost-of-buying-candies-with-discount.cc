#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
using namespace std;

class Solution {
public:
  int minimumCost(vector<int> &cost) {
    int res = 0;
    std::sort(cost.begin(), cost.end(), std::greater<int>());
    for (int i = 0; i < cost.size(); i += 3) {
      res += cost[i];
      if (i + 1 < cost.size()) {
        res += cost[i + 1];
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

int main() {
  string line;
  while (getline(cin, line)) {
    vector<int> cost = stringToIntegerVector(line);

    int ret = Solution().minimumCost(cost);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
