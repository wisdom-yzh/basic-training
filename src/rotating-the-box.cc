#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<char>> rotateTheBox(vector<vector<char>> &box) {
    const auto COLS{box.size()}, ROWS{box.front().size()};
    auto res{vector<vector<char>>(ROWS, vector<char>(COLS))};

    for (auto y = 0; y < COLS; y++) {
      int delta = 0;
      for (int x = ROWS - 1; x >= 0; x--) {
        if (box[y][x] == '*') {
          delta = 0;
        } else if (box[y][x] == '#') {
          box[y][x] = '.';
          box[y][x + delta] = '#';
        } else {
          delta++;
        }
      }
    }

    for (auto y = 0; y < COLS; y++) {
      for (auto x = 0; x < ROWS; x++) {
        res[x][COLS - 1 - y] = box[y][x];
      }
    }

    return res;
  }
};

int main() {
  auto testCases{
      vector<vector<vector<char>>>{{{'#', '.', '#'}},
                                   {{'#', '.', '*', '.'}, {'#', '#', '*', '.'}},
                                   {{'#', '#', '*', '.', '*', '.'},
                                    {'#', '#', '#', '*', '.', '.'},
                                    {'#', '#', '#', '.', '#', '.'}}}};
  for (auto &testCase : testCases) {
    for (auto &row : Solution().rotateTheBox(testCase)) {
      for (auto &x : row) {
        cout << x << ' ';
      }
      cout << endl;
    }
  }
  return 0;
}
