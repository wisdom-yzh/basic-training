#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <set>
#include <type_traits>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int minimizeTheDifference(vector<vector<int>> &mat, int target) {
    int m = mat.size(), n = mat[0].size();
    int maxsum = 0;
    vector<int> f = {1};
    for (int i = 0; i < m; ++i) {
      int best = *max_element(mat[i].begin(), mat[i].end());
      vector<int> g(maxsum + best + 1);
      for (int x : mat[i]) {
        for (int j = x; j <= maxsum + x; ++j) {
          g[j] |= f[j - x];
        }
      }
      f = move(g);
      maxsum += best;
    }
    int ans = std::numeric_limits<int>::max();
    for (int i = 0; i <= maxsum; ++i) {
      if (f[i] && abs(i - target) < ans) {
        ans = abs(i - target);
      }
    }
    return ans;
  }
};

int main(int argc, char *argv[]) {
  vector<pair<vector<vector<int>>, int>> testCases{
      {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 13},
      {{{1}, {2}, {3}}, 100},
      {{{1, 2, 9, 8, 7}}, 6},
  };
  for (auto &[mat, target] : testCases) {
    cout << Solution().minimizeTheDifference(mat, target) << endl;
  }
  return 0;
}
