#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
    int count = 0;

    for (int y = 0; y < grid2.size(); y++) {
      for (int x = 0; x < grid2[0].size(); x++) {
        if (grid2[y][x] == 1) {
          bool includes = true;
          queue<pair<int, int>> q;
          q.emplace(y, x);
          grid2[y][x] = 0;

          while (!q.empty()) {
            auto [y0, x0] = q.front();
            if (includes && grid1[y0][x0] == 0) {
              includes = false;
            }

            if (y0 < grid2.size() - 1 && grid2[y0 + 1][x0] == 1) {
              grid2[y0 + 1][x0] = 0;
              q.emplace(y0 + 1, x0);
            }
            if (y0 > 0 && grid2[y0 - 1][x0] == 1) {
              grid2[y0 - 1][x0] = 0;
              q.emplace(y0 - 1, x0);
            }
            if (x0 < grid2[0].size() - 1 && grid2[y0][x0 + 1] == 1) {
              grid2[y0][x0 + 1] = 0;
              q.emplace(y0, x0 + 1);
            }
            if (x0 > 0 && grid2[y0][x0 - 1] == 1) {
              grid2[y0][x0 - 1] = 0;
              q.emplace(y0, x0 - 1);
            }

            q.pop();
          }

          if (includes) {
            count++;
          }
        }
      }
    }

    return count;
  }
};

int main() {
  auto testCases{vector<pair<vector<vector<int>>, vector<vector<int>>>>{
      {{{1, 1, 1, 0, 0},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1}},
       {{1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1},
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0}}},
      {{{1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1}},
       {{0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {1, 0, 0, 0, 1}}},
      {{{0, 1, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 1, 0, 0, 1, 1, 1, 0, 0, 1},
        {1, 1, 0, 1, 1, 0, 0, 1, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 1, 0, 1, 1, 1, 1}},
       {{0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 1, 1, 0, 0, 1, 0},
        {1, 1, 1, 0, 1, 1, 0, 1, 1, 1},
        {1, 0, 0, 1, 0, 0, 1, 0, 1, 1},
        {0, 1, 1, 1, 0, 1, 0, 1, 1, 0},
        {1, 1, 1, 0, 0, 0, 1, 0, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 0}}}}};

  for (auto &[g1, g2] : testCases) {
    cout << Solution().countSubIslands(g1, g2) << endl;
  }
  return 0;
}
