#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int addRungs(vector<int> &rungs, int dist) {
    int res = 0;
    int curr = 0;
    for (int h : rungs) {
      int d = h - curr;
      res += (d - 1) / dist;
      curr = h;
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

int main() {
  string line;
  while (getline(cin, line)) {
    vector<int> rungs = stringToIntegerVector(line);
    getline(cin, line);
    int dist = stringToInteger(line);

    int ret = Solution().addRungs(rungs, dist);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
