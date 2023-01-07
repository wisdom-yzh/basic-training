#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  static constexpr double EPS = 1e-8;
  long long interchangeableRectangles(vector<vector<int>> &rectangles) {
    vector<double> rect;
    for (auto &x : rectangles) {
      rect.push_back(static_cast<double>(x[0]) / static_cast<double>(x[1]));
    }

    std::sort(rect.begin(), rect.end());

    long long res{0L}, sameCount{1L};
    double val = rect[0];

    for (int i = 1; i < rect.size(); i++) {
      if (std::abs(val - rect[i]) <= EPS) {
        sameCount++;
      } else {
        res += (sameCount) * (sameCount - 1) / 2L;
        sameCount = 1L;
        val = rect[i];
      }
    }
    res += (sameCount) * (sameCount - 1) / 2L;

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<vector<int>>> testCases{{{4, 8}, {3, 6}, {10, 20}, {15, 30}},
                                        {{4, 5}, {7, 8}}};
  for (auto &testCase : testCases) {
    cout << Solution().interchangeableRectangles(testCase) << endl;
  }
  return 0;
}
