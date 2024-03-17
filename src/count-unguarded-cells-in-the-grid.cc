#include <bits/stdc++.h>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
public:
  static constexpr int Wall = 0, Empty = 1, Guarded = 2, Guard = 3;

  int countUnguarded(int m, int n, vector<vector<int>> &guards,
                     vector<vector<int>> &walls) {
    int res = m * n - guards.size() - walls.size();
    vector<vector<int>> block(m, vector<int>(n, Empty));

    for (const auto &wall : walls) {
      block[wall[0]][wall[1]] = Wall;
    }
    for (const auto &guard : guards) {
      block[guard[0]][guard[1]] = Guard;
    }

    for (const auto &guard : guards) {
      int r = guard[0], c = guard[1];
      for (int y = r - 1; y >= 0; y--) {
        if (block[y][c] == Wall || block[y][c] == Guard) {
          break;
        } else if (block[y][c] == Empty) {
          res--;
          block[y][c] = Guarded;
        }
      }
      for (int y = r + 1; y < m; y++) {
        if (block[y][c] == Wall || block[y][c] == Guard) {
          break;
        } else if (block[y][c] == Empty) {
          res--;
          block[y][c] = Guarded;
        }
      }
      for (int x = c - 1; x >= 0; x--) {
        if (block[r][x] == Wall || block[r][x] == Guard) {
          break;
        } else if (block[r][x] == Empty) {
          res--;
          block[r][x] = Guarded;
        }
      }
      for (int x = c + 1; x < n; x++) {
        if (block[r][x] == Wall || block[r][x] == Guard) {
          break;
        } else if (block[r][x] == Empty) {
          res--;
          block[r][x] = Guarded;
        }
      }
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<tuple<int, int, vector<vector<int>>, vector<vector<int>>>> testCases{
      {4, 6, {{0, 0}, {1, 1}, {2, 3}}, {{0, 1}, {2, 2}, {1, 4}}},
      {3, 3, {{1, 1}}, {{0, 1}, {1, 0}, {2, 1}, {1, 2}}}};
  for (auto &[m, n, guards, walls] : testCases) {
    cout << Solution().countUnguarded(m, n, guards, walls) << endl;
  }
  return 0;
}
