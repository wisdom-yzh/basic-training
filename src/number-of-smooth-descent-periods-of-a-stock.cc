#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  long long getDescentPeriods(vector<int> &prices) {
    long long res = prices.size();
    vector<int> descentSeries;
    int series = 0;

    for (int i = 0; i < prices.size(); i++) {
      if (series == 0) {
        series = 1;
        continue;
      }
      if (prices[i] == prices[i - 1] - 1) {
        series++;
      } else {
        if (series > 1) {
          res += (series - 1L) * static_cast<long long>(series) / 2;
        }
        series = 1;
      }
    }

    if (series > 1) {
      res += (series - 1L) * static_cast<long long>(series) / 2;
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> testCases{
      {3, 2, 1, 4},
      {8, 6, 7, 7},
      {1},
      {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 4, 3, 10, 9, 8, 7},
  };
  for (auto &testCase : testCases) {
    cout << Solution().getDescentPeriods(testCase) << endl;
  }
  return 0;
}
