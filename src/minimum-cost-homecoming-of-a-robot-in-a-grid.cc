#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minCost(vector<int> &startPos, vector<int> &homePos,
              vector<int> &rowCosts, vector<int> &colCosts) {
    int res = 0;
    const vector<const vector<int> *> costs{&rowCosts, &colCosts};

    for (int x = 0; x <= 1; x++) {
      int step = startPos[x] < homePos[x] ? 1 : -1;

      for (int i = startPos[x]; i != homePos[x]; i += step) {
        res += (*costs[x])[i + step];
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
    vector<int> startPos = stringToIntegerVector(line);
    getline(cin, line);
    vector<int> homePos = stringToIntegerVector(line);
    getline(cin, line);
    vector<int> rowCosts = stringToIntegerVector(line);
    getline(cin, line);
    vector<int> colCosts = stringToIntegerVector(line);

    int ret = Solution().minCost(startPos, homePos, rowCosts, colCosts);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
