#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
  int minSideJumps(vector<int> &obstacles) {
    auto jumps{vector<vector<int>>(obstacles.size(), vector<int>(3, 0))};

    for (int i = jumps.size() - 2; i >= 0; i--) {
      auto nextObs{obstacles[i + 1] - 1};
      auto currObs{obstacles[i] - 1};
      auto minJump{std::numeric_limits<int>::max()};

      for (int j = 0; j < 3; j++) {
        if (j == currObs) {
          jumps[i][j] = -1;
        } else if (j != nextObs) {
          jumps[i][j] = jumps[i + 1][j];
          minJump = std::min(minJump, jumps[i][j]);
        }
      }

      if (nextObs != -1) {
        jumps[i][nextObs] = minJump + 1;
      }
    }

    return jumps[0][1];
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
    vector<int> obstacles = stringToIntegerVector(line);

    int ret = Solution().minSideJumps(obstacles);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
