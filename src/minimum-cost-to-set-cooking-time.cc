#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minCostSetTime(int startAt, int moveCost, int pushCost,
                     int targetSeconds) {
    auto cost = [&](int m, int s) -> int {
      if (m < 0 || m > 99 || s < 0 || s > 99) {
        return INT_MAX;
      }
      vector<int> digits = {m / 10, m % 10, s / 10, s % 10};
      int start = 0;
      while (start < 4 && digits[start] == 0) {
        ++start;
      }

      int res = 0;
      int prev = startAt;
      for (int i = start; i < 4; ++i) {
        int d = digits[i];
        if (d != prev) {
          prev = d;
          res += moveCost;
        }
        res += pushCost;
      }
      return res;
    };

    int mm = targetSeconds / 60, ss = targetSeconds % 60;
    return min(cost(mm, ss), cost(mm - 1, ss + 60));
  }
};

int stringToInteger(string input) { return stoi(input); }

int main() {
  string line;
  while (getline(cin, line)) {
    int startAt = stringToInteger(line);
    getline(cin, line);
    int moveCost = stringToInteger(line);
    getline(cin, line);
    int pushCost = stringToInteger(line);
    getline(cin, line);
    int targetSeconds = stringToInteger(line);

    int ret =
        Solution().minCostSetTime(startAt, moveCost, pushCost, targetSeconds);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
