#include <functional>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class Solution {
public:
  static constexpr int MOD = 1e9 + 7;
  int countPaths(int n, vector<vector<int>> &roads) {
    vector<vector<long long>> dist(
        n, vector<long long>(n, std::numeric_limits<int64_t>::max() / 2));
    for (int i = 0; i < n; ++i) {
      dist[i][i] = 0;
    }
    for (auto &&road : roads) {
      int x = road[0], y = road[1], z = road[2];
      dist[x][y] = dist[y][x] = z;
    }

    // Dijkstra 算法求解最短路 完成后，dist[0][i] 即为正文部分的 dist[i]
    vector<int> used(n);
    for (int _ = 0; _ < n; ++_) {
      int u = -1;
      for (int i = 0; i < n; ++i) {
        if (!used[i] && (u == -1 || dist[0][i] < dist[0][u])) {
          u = i;
        }
      }
      used[u] = true;
      for (int i = 0; i < n; ++i) {
        dist[0][i] = min(dist[0][i], dist[0][u] + dist[u][i]);
      }
    }

    vector<vector<int>> g(n);
    for (auto &&road : roads) {
      int x = road[0], y = road[1], z = road[2];
      if (dist[0][y] - dist[0][x] == z) {
        g[x].push_back(y);
      } else if (dist[0][x] - dist[0][y] == z) {
        g[y].push_back(x);
      }
    }

    vector<int> f(n, -1);
    function<int(int)> dfs = [&](int u) {
      if (u == n - 1) {
        return 1;
      }
      if (f[u] != -1) {
        return f[u];
      }

      f[u] = 0;
      for (int v : g[u]) {
        f[u] += dfs(v);
        if (f[u] >= MOD) {
          f[u] -= MOD;
        }
      }
      return f[u];
    };
    return dfs(0);
  }
};

int main(int argc, char *argv[]) {
  vector<pair<int, vector<vector<int>>>> testCases{{7,
                                                    {{0, 6, 7},
                                                     {0, 1, 2},
                                                     {1, 2, 3},
                                                     {1, 3, 3},
                                                     {6, 3, 3},
                                                     {3, 5, 1},
                                                     {6, 5, 1},
                                                     {2, 5, 1},
                                                     {0, 4, 5},
                                                     {4, 6, 2}}},
                                                   {2, {{1, 0, 10}}}};
  for (auto &[n, roads] : testCases) {
    cout << Solution().countPaths(n, roads) << endl;
  }
  return 0;
}
