#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class Solution {
public:
  long long maxMatrixSum(vector<vector<int>> &matrix) {
    const int ROWS = matrix.size(), COLS = matrix[0].size();
    long long sum{0};
    int negCount{0}, minAbs{std::numeric_limits<int>::max()};

    for (int y = 0; y < ROWS; y++) {
      for (int x = 0; x < COLS; x++) {
        if (matrix[y][x] > 0) {
          sum += matrix[y][x];
          minAbs = std::min(minAbs, matrix[y][x]);
        } else {
          negCount++;
          sum -= matrix[y][x];
          minAbs = std::min(minAbs, -matrix[y][x]);
        }
      }
    }

    if ((negCount % 2) != 0) {
      sum -= 2 * minAbs;
    }

    return sum;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<vector<int>>> testCases{
      {{1, -1}, {-1, 1}},
      {{1, 2, 3}, {-1, -2, -3}, {1, 2, 3}},
  };
  for (auto &testCase : testCases) {
    cout << Solution().maxMatrixSum(testCase) << endl;
  }
  return 0;
}
