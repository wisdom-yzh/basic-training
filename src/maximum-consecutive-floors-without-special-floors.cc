#include <algorithm>
#include <bits/stdc++.h>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  int maxConsecutive(int bottom, int top, vector<int> &special) {
    int res = 0;

    std::set<int> s(special.begin(), special.end());

    for (int x = bottom; x <= top;) {
      auto iter = s.lower_bound(x);

      if (iter == s.end()) {
        res = std::max(res, top - x + 1);
        break;
      }

      if (*iter == x) {
        x++;
      }

      res = std::max(res, *iter - x);
      x = *iter + 1;
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<tuple<int, int, vector<int>>> testCases{{2, 9, {4, 6}},
                                                 {6, 8, {7, 6, 8}}};
  for (auto &[b, t, s] : testCases) {
    cout << Solution().maxConsecutive(b, t, s) << endl;
  }
  return 0;
}
