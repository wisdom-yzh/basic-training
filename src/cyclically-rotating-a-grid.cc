#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k) {
    vector<vector<int>> newGrid(grid);
    const auto ROWS = grid.size(), COLS = grid[0].size();
    const auto SIZE = std::min(ROWS, COLS) / 2;

    for (int i = 0; i < SIZE; i++) {
      const int Y = ROWS - 1 - i, X = COLS - 1 - i;
      vector<pair<int, int>> vec;
      auto [y, x] = pair{i, i};
      while (y < Y) {
        vec.push_back({y, x});
        y++;
      }
      while (x < X) {
        vec.push_back({y, x});
        x++;
      }
      while (y > i) {
        vec.push_back({y, x});
        y--;
      }
      while (x > i) {
        vec.push_back({y, x});
        x--;
      }

      auto m = (k % vec.size());
      for (int j = 0; j < vec.size(); j++) {
        const auto [oldY, oldX] = vec[j];
        const auto [newY, newX] = vec[(j + m) % vec.size()];
        newGrid[newY][newX] = grid[oldY][oldX];
      }
    }

    return newGrid;
  }
};

int main() {
  auto testCases{vector<pair<vector<vector<int>>, int>>{
      {{{40, 10}, {30, 20}}, 1},
      {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}}, 2}}};
  for (auto &[grid, k] : testCases) {
    for (const auto &r : Solution().rotateGrid(grid, k)) {
      for (const auto &c : r) {
        cout << c << ' ';
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
