#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> findWinners(vector<vector<int>> &matches) {
    std::map<int, int> loseCount;
    for (auto &x : matches) {
      if (loseCount.find(x[0]) == loseCount.end()) {
        loseCount[x[0]] = 0;
      }
      loseCount[x[1]]++;
    }

    vector<int> loseZero, loseOne;
    for (auto &[x, count] : loseCount) {
      if (count == 0) {
        loseZero.push_back(x);
      } else if (count == 1) {
        loseOne.push_back(x);
      }
    }
    return {loseZero, loseOne};
  }
};

int main(int argc, char *argv[]) {
  vector<vector<vector<int>>> testCases{{{1, 3},
                                         {2, 3},
                                         {3, 6},
                                         {5, 6},
                                         {5, 7},
                                         {4, 5},
                                         {4, 8},
                                         {4, 9},
                                         {10, 4},
                                         {10, 9}},
                                        {{2, 3}, {1, 3}, {5, 4}, {6, 4}}};
  for (auto &matches : testCases) {
    for (auto &row : Solution().findWinners(matches)) {
      for (auto &x : row) {
        cout << x << ' ';
      }
      cout << endl;
    }
  }
  return 0;
}
