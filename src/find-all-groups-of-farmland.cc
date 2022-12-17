#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> findFarmland(vector<vector<int>> &land) {
    vector<vector<int>> res;
    int ROWS = land.size(), COLS = land[0].size();

    for (int r = 0; r < ROWS; r++) {
      for (int c = 0; c < COLS; c++) {
        if (land[r][c] == 1 && (r == 0 || land[r - 1][c] != 1) &&
            (c == 0 || land[r][c - 1] != 1)) {
          int y = r + 1, x = c + 1;
          while (y < ROWS && land[y][c] == 1) {
            ++y;
          }
          while (x < COLS && land[r][x] == 1) {
            ++x;
          }
          res.push_back({r, c, y - 1, x - 1});
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<vector<int>>> testCases{
      {{1, 0, 0}, {0, 1, 1}, {0, 1, 1}},
      {{1, 1}, {1, 1}},
      {{0}},
  };
  for (auto &land : testCases) {
    for (const auto &r : Solution().findFarmland(land)) {
      for (const auto &c : r) {
        cout << c << ' ';
      }
      cout << endl;
    }
  }
  return 0;
}
