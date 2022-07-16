#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int largestMagicSquare(vector<vector<int>> &grid) {
    const auto ROWS{grid.size()}, COLS{grid[0].size()};
    vector<vector<int>> sumR(ROWS, vector<int>(COLS, 0));
    vector<vector<int>> sumC(ROWS, vector<int>(COLS, 0));

    for (int y = 0; y < ROWS; y++) {
      sumR[y][0] = grid[y][0];
      for (int x = 1; x < COLS; x++) {
        sumR[y][x] = sumR[y][x - 1] + grid[y][x];
      }
    }

    for (int x = 0; x < COLS; x++) {
      sumC[0][x] = grid[0][x];
      for (int y = 1; y < ROWS; y++) {
        sumC[y][x] = sumC[y - 1][x] + grid[y][x];
      }
    }

    for (int e = std::min(ROWS, COLS); e >= 2; e--) {
      for (int y = 0; y + e <= ROWS; y++) {
        for (int x = 0; x + e <= COLS; x++) {
          int sum = sumR[y][x + e - 1] - (x > 0 ? sumR[y][x - 1] : 0);

          bool check = true;
          for (int yy = y + 1; yy < y + e; yy++) {
            if (sumR[yy][x + e - 1] - (x > 0 ? sumR[yy][x - 1] : 0) != sum) {
              check = false;
              break;
            }
          }
          if (!check) {
            continue;
          }

          for (int xx = x; xx < x + e; xx++) {
            if (sumC[y + e - 1][xx] - (y > 0 ? sumC[y - 1][xx] : 0) != sum) {
              check = false;
              break;
            }
          }
          if (!check) {
            continue;
          }

          int d1 = 0, d2 = 0;
          for (int k = 0; k < e; ++k) {
            d1 += grid[y + k][x + k];
            d2 += grid[y + k][x + e - 1 - k];
          }
          if (d1 == sum && d2 == sum) {
            return e;
          }
        }
      }
    }

    return 1;
  }
};

int main() {
  auto testCases{vector<vector<vector<int>>>{
      {{7, 1, 4, 5, 6}, {2, 5, 1, 6, 4}, {1, 5, 4, 3, 2}, {1, 2, 7, 3, 4}},
      {{5, 1, 3, 1}, {9, 3, 3, 1}, {1, 3, 3, 8}}}};

  for (auto &testCase : testCases) {
    cout << Solution().largestMagicSquare(testCase) << endl;
  }
  return 0;
}
