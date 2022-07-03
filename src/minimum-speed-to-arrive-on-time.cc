#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
public:
  int minSpeedOnTime(vector<int> &dist, double hour) {
    int n = dist.size();
    if (n - 1.0 >= hour) {
      return -1;
    }

    int64_t hr = std::llround(hour * 100);
    int l = 1, r = 1e7;
    while (l < r) {
      int mid = (l + r) >> 1;
      int64_t t = 0;

      for (int i = 0; i < n - 1; ++i) {
        t += (dist[i] + mid - 1) / mid;
      }
      t *= mid;
      t += dist[n - 1];

      if (hr * mid >= t * 100) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }

    return l;
  }
};

int main() {
  auto testCases{vector<pair<vector<int>, double>>{
      {{1, 3, 2}, 6},
      {{1, 3, 2}, 2.7},
      {{1, 3, 2}, 1.9},
  }};
  for (auto &[dist, hour] : testCases) {
    cout << Solution().minSpeedOnTime(dist, hour) << endl;
  }
  return 0;
}
