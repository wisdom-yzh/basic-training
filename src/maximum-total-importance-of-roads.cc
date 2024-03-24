#include <algorithm>
#include <bits/stdc++.h>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  long long maximumImportance(int n, vector<vector<int>> &roads) {
    vector<pair<int, int>> degree(n, make_pair(0, 0));
    for (int i = 0; i < n; i++) {
      degree[i].second = i;
    }
    for (auto &road : roads) {
      degree[road[0]].first++;
      degree[road[1]].first++;
    }

    std::sort(degree.begin(), degree.end(),
              [](auto &a, auto &b) { return a.first < b.first; });

    vector<int> importances(n, 0);
    for (int i = 1; i <= degree.size(); i++) {
      importances[degree[i - 1].second] = i;
    }

    long long res = 0l;
    for (auto &road : roads) {
      res += importances[road[0]] + importances[road[1]];
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<tuple<int, vector<vector<int>>>> testCases{
      {5, {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}}},
      {5, {{0, 3}, {2, 4}, {1, 3}}}};
  for (auto &[n, roads] : testCases) {
    cout << Solution().maximumImportance(n, roads) << endl;
  }
  return 0;
}
