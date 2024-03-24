#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> getSlope(vector<vector<int>> &stockPrices, int i) {
    return {stockPrices[i][1] - stockPrices[i - 1][1],
            stockPrices[i][0] - stockPrices[i - 1][0]};
  }

  int minimumLines(vector<vector<int>> &stocks) {
    if (stocks.size() == 1) {
      return 0;
    }

    sort(stocks.begin(), stocks.end());

    vector<int> prevSlope = getSlope(stocks, 1);
    int ans = 1;

    for (int i = 2; i < stocks.size(); i++) {
      vector<int> slope = getSlope(stocks, i);

      if ((long long int)slope[0] * prevSlope[1] !=
          (long long int)slope[1] * prevSlope[0]) {
        prevSlope = slope;
        ans++;
      }
    }

    return ans;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<vector<int>>> testCases{
      {{{1, 7}, {2, 6}, {3, 5}, {4, 4}, {5, 4}, {6, 3}, {7, 2}, {8, 1}}},
      {{{3, 4}, {1, 2}, {7, 8}, {2, 3}}}};
  for (auto &stocks : testCases) {
    cout << Solution().minimumLines(stocks) << endl;
  }
  return 0;
}
