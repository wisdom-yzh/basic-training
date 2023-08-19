#include <algorithm>
#include <array>
#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  string repeatLimitedString(string s, int repeatLimit) {
    std::array<int, 26> count;
    std::fill(count.begin(), count.end(), 0);
    for (auto &ch : s) {
      count[ch - 'a']++;
    }

    string res;
    for (int r = count.size() - 1; r >= 0;) {
      while (r >= 0 && count[r] == 0) {
        r--;
      }
      int l = r - 1;
      while (l >= 0 && count[l] == 0) {
        l--;
      }

      if (r < 0) {
        break;
      }

      int repeatNum = std::min(count[r], repeatLimit);
      for (int i = 0; i < repeatNum; i++) {
        res.push_back('a' + r);
      }
      count[r] -= repeatNum;

      if (count[r] > 0) {
        if (l < 0) {
          break;
        }
        res.push_back('a' + l);
        count[l]--;
      } else {
        r--;
      }
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<pair<string, int>> testCases{
      {"cczazcc", 3},
      {"aababab", 2},
  };
  for (auto &[s, rl] : testCases) {
    cout << Solution().repeatLimitedString(s, rl) << endl;
  }
  return 0;
}
