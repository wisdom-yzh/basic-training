#include <algorithm>
#include <functional>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> getBiggestThree(vector<vector<int>> &grid) {
    set<int, std::greater<int>> result;

    const int ROWS = grid.size(), COLS = grid[0].size();

    for (int y = 0; y < ROWS; y++) {
      for (int x = 0; x < COLS; x++) {
        int maxEdge =
            std::min(std::min(y, x), std::min(ROWS - 1 - y, COLS - 1 - x));

        for (int i = 0; i <= maxEdge; i++) {
          int val = 0;
          for (int j = -i; j <= 0; j++) {
            val += grid[y + j][x + (i + j)];
            if (j != -i) {
              val += grid[y + j][x - (i + j)];
            }
          }
          for (int j = i; j > 0; j--) {
            val += grid[y + j][x + (i - j)];
            if (j != i) {
              val += grid[y + j][x - (i - j)];
            }
          }
          result.insert(val);
        }
      }
    }

    vector<int> res;
    for (int i = 0; i < 3; i++) {
      if (!result.empty()) {
        res.push_back(*result.begin());
        result.erase(result.begin());
      }
    }
    return res;
  }
};

int main() {
  auto testCases{vector<vector<vector<int>>>{{{3, 4, 5, 1, 3},
                                              {3, 3, 4, 2, 3},
                                              {20, 30, 200, 40, 10},
                                              {1, 5, 5, 4, 1},
                                              {4, 3, 2, 2, 5}},
                                             {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
                                             {{7, 7, 7}}}};
  for (auto &testCase : testCases) {
    for (auto &x : Solution().getBiggestThree(testCase)) {
      cout << x << ' ';
    }
    cout << endl;
  }
  return 0;
}
