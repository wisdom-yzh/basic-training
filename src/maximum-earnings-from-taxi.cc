#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  long long maxTaxiEarnings(int n, vector<vector<int>> &rides) {
    std::sort(rides.begin(), rides.end(),
              [](auto &p, auto &q) { return p[1] < q[1]; });

    vector<long long> dp(n + 1, 0);
    int index = 0;

    for (int i = 1; i <= n; i++) {
      dp[i] = dp[i - 1];
      while (index < rides.size() && rides[index][1] == i) {
        dp[i] = std::max(dp[i], dp[rides[index][0]] + rides[index][1] -
                                    rides[index][0] + rides[index][2]);
        index++;
      }
    }
    return dp[n];
  }
};

int main(int argc, char *argv[]) {
  vector<pair<int, vector<vector<int>>>> testCases{{5, {{2, 5, 4}, {1, 5, 1}}},
                                                   {20,
                                                    {{1, 6, 1},
                                                     {3, 10, 2},
                                                     {10, 12, 3},
                                                     {11, 12, 2},
                                                     {12, 15, 2},
                                                     {13, 18, 1}}}};
  for (auto &[n, rides] : testCases) {
    cout << Solution().maxTaxiEarnings(n, rides) << endl;
  }
  return 0;
}
