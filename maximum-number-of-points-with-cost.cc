#include <algorithm>
#include <iostream>
#include <limits>
#include <ostream>
#include <vector>
using namespace std;

class Solution {
public:
  long long maxPoints(vector<vector<int>> &points) {
    int m = points.size();
    int n = points[0].size();
    vector<long long> f(n);

    for (int i = 0; i < m; ++i) {
      vector<long long> g(n);
      long long best = std::numeric_limits<long long>::min();
      for (int j = 0; j < n; ++j) {
        best = max(best, f[j] + j);
        g[j] = max(g[j], best + points[i][j] - j);
      }

      best = std::numeric_limits<long long>::min();
      for (int j = n - 1; j >= 0; --j) {
        best = max(best, f[j] - j);
        g[j] = max(g[j], best + points[i][j] + j);
      }
      f = move(g);
    }

    return *std::max_element(f.begin(), f.end());
  }
};

int main() {
  auto testCases(vector<vector<vector<int>>>{{{1, 2, 3}, {1, 5, 1}, {3, 1, 1}},
                                             {{1, 5}, {2, 3}, {4, 2}}});
  for (auto &testCase : testCases) {
    std::cout << Solution().maxPoints(testCase) << std::endl;
  }
  return 0;
}
