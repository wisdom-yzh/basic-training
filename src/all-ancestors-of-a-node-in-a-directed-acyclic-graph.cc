#include <bits/stdc++.h>
#include <queue>
#include <set>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
    vector<vector<bool>> g(n, vector<bool>(n, false));
    vector<int> inDegree(n, 0);

    for (auto &edge : edges) {
      g[edge[0]][edge[1]] = true;
      inDegree[edge[1]]++;
    }

    vector<set<int>> ancestorSet(n, set<int>());
    queue<int> q;
    vector<int> visited(n, false);

    for (int i = 0; i < n; i++) {
      if (inDegree[i] == 0) {
        q.push(i);
        visited[i] = true;
      }
    }

    while (!q.empty()) {
      auto u = q.front();

      for (int v = 0; v < n; v++) {
        if (g[u][v]) {
          for (auto &w : ancestorSet[u]) {
            ancestorSet[v].insert(w);
          }
          ancestorSet[v].insert(u);
          inDegree[v]--;
        }

        if (!visited[v] && inDegree[v] == 0) {
          q.push(v);
          visited[v] = true;
        }
      }

      q.pop();
    }

    vector<vector<int>> res;
    for (auto &set : ancestorSet) {
      res.push_back(vector<int>(set.begin(), set.end()));
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<pair<int, vector<vector<int>>>> testCases{{8,
                                                    {{0, 3},
                                                     {0, 4},
                                                     {1, 3},
                                                     {2, 4},
                                                     {2, 7},
                                                     {3, 5},
                                                     {3, 6},
                                                     {3, 7},
                                                     {4, 6}}},
                                                   {5,
                                                    {{0, 1},
                                                     {0, 2},
                                                     {0, 3},
                                                     {0, 4},
                                                     {1, 2},
                                                     {1, 3},
                                                     {1, 4},
                                                     {2, 3},
                                                     {2, 4},
                                                     {3, 4}}}};
  for (auto &[n, edges] : testCases) {
    int idx = 0;
    for (auto &row : Solution().getAncestors(n, edges)) {
      cout << idx++ << " : ";
      for (auto &x : row) {
        cout << x << ' ';
      }
      cout << endl;
    }
  }
  return 0;
}
