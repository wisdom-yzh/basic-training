#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findPeakGrid(vector<vector<int>> &mat) {
    int y = 0, x = 0;

    while (!isPeak(mat, y, x)) {
      findNext(mat, y, x);
    }

    return {y, x};
  }

  bool isPeak(vector<vector<int>> &mat, int y, int x) {
    return (x == 0 || mat[y][x] > mat[y][x - 1]) &&
           (x == mat[0].size() - 1 || mat[y][x] > mat[y][x + 1]) &&
           (y == 0 || mat[y][x] > mat[y - 1][x]) &&
           (y == mat.size() - 1 || mat[y][x] > mat[y + 1][x]);
  }

  void findNext(vector<vector<int>> &mat, int &y, int &x) {
    auto nextY = y, nextX = x;
    auto num{mat[nextY][nextX]};

    if (y > 0 && mat[y - 1][x] > num) {
      num = mat[y - 1][x];
      nextY = y - 1;
    }
    if (y < mat.size() - 1 && mat[y + 1][x] > num) {
      num = mat[y + 1][x];
      nextY = y + 1;
    }
    if (x > 0 && mat[y][x - 1] > num) {
      num = mat[y][x - 1];
      nextX = x - 1;
    }
    if (x < mat[0].size() - 1 && mat[y][x + 1] > num) {
      num = mat[y][x + 1];
      nextX = x + 1;
    }

    y = nextY;
    x = nextX;
  }
};

int main() {
  auto testCases{
      vector<vector<vector<int>>>{{{1, 2, 3, 4, 5, 6, 7, 8},
                                   {2, 3, 4, 5, 6, 7, 8, 9},
                                   {3, 4, 5, 6, 7, 8, 9, 10},
                                   {4, 5, 6, 7, 8, 9, 10, 11}},
                                  {{1, 4}, {3, 2}},
                                  {{10, 20, 15}, {21, 30, 14}, {7, 16, 32}}}};
  for (auto &testCase : testCases) {
    for (auto &x : Solution().findPeakGrid(testCase)) {
      cout << x << ',';
    }
    cout << endl;
  }
  return 0;
}
