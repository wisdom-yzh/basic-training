#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> maximumBobPoints(int numArrows, vector<int> &aliceArrows) {
    constexpr int SCORE_RANGE = 12;

    int maxValue = 0, maxMask = 0;
    for (int i = (1 << SCORE_RANGE) - 1; i >= 0; i--) {
      int value = 0, arrowCount = numArrows;

      for (int j = SCORE_RANGE - 1; j >= 0; j--) {
        if ((i & (1 << j)) != 0) {
          arrowCount -= (aliceArrows[j] + 1);
          if (arrowCount < 0) {
            value = -1;
            break;
          }
          value += j;
        }
      }

      if (value > maxValue) {
        maxValue = value;
        maxMask = i;
      }
    }

    vector<int> res(SCORE_RANGE, 0);
    for (int i = SCORE_RANGE - 1; i >= 0; i--) {
      if ((maxMask & (1 << i)) != 0) {
        res[i] = aliceArrows[i] + 1;
        numArrows -= aliceArrows[i] + 1;
      }
    }

    res[0] += numArrows;
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<pair<int, vector<int>>> testCases{
      {9, {1, 1, 0, 1, 0, 0, 2, 1, 0, 1, 2, 0}},
      {3, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2}}};
  for (auto &[n, a] : testCases) {
    for (auto &x : Solution().maximumBobPoints(n, a)) {
      cout << x << ' ';
    }
    cout << endl;
  }
  return 0;
}
