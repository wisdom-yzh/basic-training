#include <iostream>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
public:
  bool validPath(int n, vector<vector<int>> &edges, int source,
                 int destination) {
    if (source == destination) {
      return true;
    }

    set<int> used;
    vector<vector<int>> g(n);
    for (const auto e : edges) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }

    std::queue<int> q;
    q.push(source);
    used.insert(source);

    while (!q.empty()) {
      auto u = q.front();
      for (auto &v : g[u]) {
        if (used.find(v) == used.end()) {
          if (v == destination) {
            return true;
          }
          used.insert(v);
          q.push(v);
        }
      }
      q.pop();
    }

    return false;
  }
};

int main(int argc, char *argv[]) {
  vector<tuple<int, vector<vector<int>>, int, int>> testCases{
      {3, {{0, 1}, {1, 2}, {2, 0}}, 0, 2},
      {6, {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}}, 0, 5},
  };
  for (auto &[n, edges, s, d] : testCases) {
    cout << boolalpha << Solution().validPath(n, edges, s, d) << endl;
  }
  return 0;
}
