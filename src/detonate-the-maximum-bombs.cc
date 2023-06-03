#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maximumDetonation(vector<vector<int>> &bombs) {
    vector<vector<int>> g(bombs.size());
    for (int i = 0; i < bombs.size(); i++) {
      for (int j = 0; j < bombs.size(); j++) {
        if (i != j && isNear(bombs[i], bombs[j])) {
          g[i].push_back(j);
        }
      }
    }

    int res = 0;
    for (int i = 0; i < bombs.size(); i++) {
      res = std::max(res, bfs(g, i));
    }

    return res;
  }

  bool isNear(vector<int> &x, vector<int> &y) {
    int64_t dx = (x[0] - y[0]), dy = (x[1] - y[1]);
    int64_t r = x[2];
    return dx * dx + dy * dy <= r * r;
  }

  int bfs(vector<vector<int>> &g, int begin) {
    vector<bool> checked(g.size(), false);
    checked[begin] = true;
    queue<int> q;
    int res = 1;

    q.push(begin);
    while (!q.empty()) {
      auto i = q.front();
      for (auto &j : g[i]) {
        if (!checked[j]) {
          q.push(j);
          checked[j] = true;
          res += 1;
        }
      }
      q.pop();
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<vector<int>>> testCases{
      {{1, 2, 3}, {2, 3, 1}, {3, 4, 2}, {4, 5, 3}, {5, 6, 4}},
      {{1, 1, 5}, {10, 10, 5}},
      {{2, 1, 3}, {6, 1, 4}},
      {{54, 95, 4},
       {99, 46, 3},
       {29, 21, 3},
       {96, 72, 8},
       {49, 43, 3},
       {11, 20, 3},
       {2, 57, 1},
       {69, 51, 7},
       {97, 1, 10},
       {85, 45, 2},
       {38, 47, 1},
       {83, 75, 3},
       {65, 59, 3},
       {33, 4, 1},
       {32, 10, 2},
       {20, 97, 8},
       {35, 37, 3}}};
  for (auto &testCase : testCases) {
    cout << Solution().maximumDetonation(testCase) << endl;
  }
  return 0;
}
