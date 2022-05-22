#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> countPoints(vector<vector<int>> &points,
                          vector<vector<int>> &queries) {
    auto res{vector<int>{}};

    for (const auto &query : queries) {
      auto cnt{0};
      for (const auto &point : points) {
        auto dx{point[0] - query[0]}, dy{point[1] - query[1]};
        if (dx * dx + dy * dy <= query[2] * query[2]) {
          cnt++;
        }
      }
      res.push_back(cnt);
    }
    return res;
  }
};

int main() {
  auto testCases{vector<pair<vector<vector<int>>, vector<vector<int>>>>{
      {{{1, 3}, {3, 3}, {5, 3}, {2, 2}}, {{2, 3, 1}, {4, 3, 1}, {1, 1, 2}}},
      {{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}},
       {{1, 2, 2}, {2, 2, 2}, {4, 3, 2}, {4, 3, 3}}}}};

  for (auto &[points, queries] : testCases) {
    for (const auto &x : Solution().countPoints(points, queries)) {
      cout << x << ' ';
    }
    cout << endl;
  }

  return 0;
}
