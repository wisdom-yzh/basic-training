#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    if (matrix.empty()) {
      return {};
    }
    const int ROWS = matrix.size();
    const int COLS = matrix[0].size();
    const int MAX_INT = std::numeric_limits<int>::max();
    int x = 0, y = 0, dx = 1, dy = 0;
    vector<int> result;

    for (int i = 0; i < ROWS * COLS; i++) {
      result.push_back(matrix[y][x]);
      matrix[y][x] = MAX_INT;
      if (dy == 0 && (x + dx == COLS || x + dx == -1 ||
                      matrix[y + dy][x + dx] == MAX_INT)) {
        dy = dx;
        dx = 0;
      } else if (dx == 0 && (y + dy == ROWS || y + dy == -1 ||
                             matrix[y + dy][x + dx] == MAX_INT)) {
        dx = -dy;
        dy = 0;
      }
      x += dx;
      y += dy;
    }

    return result;
  }
};

int main() {
  vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  auto output = Solution().spiralOrder(matrix);
  std::copy(output.begin(), output.end(), ostream_iterator<int>(cout, ","));
  return 0;
}
