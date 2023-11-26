#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumCandies(vector<int> &candies, long long k) {
    uint64_t sum = std::accumulate(candies.begin(), candies.end(), 1LL);
    if (sum < k) {
      return 0;
    }

    uint64_t low = 1, high = sum / k;
    while (low <= high) {
      uint64_t mid = low + (high - low) / 2;
      uint64_t count = 0;

      for (int i = 0; i < candies.size(); i++) {
        count += static_cast<uint64_t>(candies[i] / mid);
      }

      if (count >= k) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return high;
  }
};

int main(int argc, char *argv[]) {
  vector<pair<vector<int>, long long>> testCases{{{5, 8, 6}, 3}, {{2, 5}, 11}};
  for (auto &[candies, k] : testCases) {
    cout << Solution().maximumCandies(candies, k) << endl;
  }
  return 0;
}
