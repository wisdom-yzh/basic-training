#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience) {
    int n = patience.size();
    vector<vector<int>> g(n, vector<int>());
    vector<int> dist(n, -1);

    for (const auto &e : edges) {
      g[e[0]].emplace_back(e[1]);
      g[e[1]].emplace_back(e[0]);
    }

    std::queue<int> q;
    q.push(0);
    dist[0] = 0;

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto &v : g[u]) {
        if (dist[v] == -1) {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }

    int res{0};
    for (int i = 1; i < n; i++) {
      int len = 2 * dist[i];
      int tmp = len + 1;
      if (len >= patience[i]) {
        if (len % patience[i] == 0) {
          tmp += len - patience[i];
        } else {
          tmp += len - (len % patience[i]);
        }
      }
      res = std::max(res, tmp);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<pair<vector<vector<int>>, vector<int>>> testCases{
      {{{0, 1}, {1, 2}}, {0, 2, 1}}};
  for (auto &[edges, patience] : testCases) {
    cout << Solution().networkBecomesIdle(edges, patience) << endl;
  }
  return 0;
}
