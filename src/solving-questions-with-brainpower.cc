#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  long long mostPoints(vector<vector<int>> &questions) {
    vector<long long> dp(questions.size(), 0);
    dp.back() = questions.back()[0];
    for (int i = questions.size() - 2; i >= 0; i--) {
      long long solve = questions[i][0];
      int next = (i + questions[i][1]) + 1;
      if (next < dp.size()) {
        solve += dp[next];
      }
      dp[i] = std::max(solve, dp[i + 1]);
    }
    return dp[0];
  }
};

int main(int argc, char *argv[]) {
  vector<vector<vector<int>>> testCases{
      {{3, 2}, {4, 3}, {4, 4}, {2, 5}},
      {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}},
  };
  for (auto &testCase : testCases) {
    cout << Solution().mostPoints(testCase) << endl;
  }
  return 0;
}
