#include <algorithm>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
  int countHighestScoreNodes(vector<int> &parents) {
    vector<vector<int>> children(parents.size());
    for (int i = 0; i < parents.size(); i++) {
      if (parents[i] != -1) {
        children[parents[i]].emplace_back(i);
      }
    }
    uint64_t maxScore = 0;
    int count = 0;
    dfs(children, 0, maxScore, count);
    return count;
  }

  int dfs(vector<vector<int>> &children, int start, uint64_t &maxScore,
          int &count) {
    long score = 1;
    int size = children.size() - 1;
    for (auto &c : children[start]) {
      int t = dfs(children, c, maxScore, count);
      score *= t;
      size -= t;
    }
    if (start != 0) {
      score *= size;
    }
    if (score == maxScore) {
      count++;
    } else if (score > maxScore) {
      maxScore = score;
      count = 1;
    }
    return children.size() - size;
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
    vector<int> parents = stringToIntegerVector(line);

    int ret = Solution().countHighestScoreNodes(parents);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
