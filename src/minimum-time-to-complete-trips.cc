#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  long long minimumTime(vector<int> &time, int totalTrips) {
    long long l = 1, r = 1LL * totalTrips *
                         *std::max_element(time.begin(), time.end());
    while (l <= r) {
      long long mid = l + (r - l) / 2, count = 0;
      bool canFinish = false;

      for (auto &i : time) {
        count += mid / i;
        if (count >= totalTrips) {
          canFinish = true;
          break;
        }
      }

      if (canFinish) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    return l;
  }
};

int main(int argc, char *argv[]) {
  vector<pair<vector<int>, int>> testCases{{{1, 2, 3}, 5}, {{2}, 1}};
  for (auto &[time, totalTrips] : testCases) {
    cout << Solution().minimumTime(time, totalTrips) << endl;
  }
  return 0;
}
