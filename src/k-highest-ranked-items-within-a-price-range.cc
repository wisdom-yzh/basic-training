#include <bits/stdc++.h>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
public:
  static constexpr int dx[4] = {1, 0, -1, 0};
  static constexpr int dy[4] = {0, 1, 0, -1};

  vector<vector<int>> highestRankedKItems(vector<vector<int>> &grid,
                                          vector<int> &pricing,
                                          vector<int> &start, int k) {
    vector<tuple<int, int, int, int>> items;
    queue<tuple<int, int, int>> q;
    q.emplace(start[0], start[1], 0);

    if (pricing[0] <= grid[start[0]][start[1]] &&
        grid[start[0]][start[1]] <= pricing[1]) {
      items.emplace_back(0, grid[start[0]][start[1]], start[0], start[1]);
    }

    grid[start[0]][start[1]] = 0;
    int m = grid.size();
    int n = grid[0].size();
    while (!q.empty()) {
      auto [x, y, d] = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > 0) {
          if (pricing[0] <= grid[nx][ny] && grid[nx][ny] <= pricing[1]) {
            items.emplace_back(d + 1, grid[nx][ny], nx, ny);
          }
          q.emplace(nx, ny, d + 1);
          grid[nx][ny] = 0;
        }
      }
    }

    sort(items.begin(), items.end());
    vector<vector<int>> res;
    int cnt = min(k, static_cast<int>(items.size()));
    for (int i = 0; i < cnt; ++i) {
      auto [d, price, x, y] = items[i];
      res.push_back({x, y});
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<tuple<vector<vector<int>>, vector<int>, vector<int>, int>> testCases{
      {
          {{1, 2, 0, 1}, {1, 3, 0, 1}, {0, 2, 5, 1}},
          {2, 5},
          {0, 0},
          3,
      },
      {
          {{1, 2, 0, 1}, {1, 3, 3, 1}, {0, 2, 5, 1}},
          {2, 3},
          {2, 3},
          2,
      },
      {
          {{1, 1, 1}, {0, 0, 1}, {2, 3, 4}},
          {2, 3},
          {0, 0},
          3,
      }};

  for (auto &[grid, pricing, start, k] : testCases) {
    for (auto &r : Solution().highestRankedKItems(grid, pricing, start, k)) {
      for (auto &c : r) {
        cout << c << ' ';
      }
      cout << endl;
    }
  }
  return 0;
}
