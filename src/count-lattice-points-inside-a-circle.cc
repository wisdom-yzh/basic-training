#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  int countLatticePoints(vector<vector<int>> &circles) {
    int res = 0;
    for (size_t y = 0; y <= 200; y++) {
      for (size_t x = 0; x <= 200; x++) {
        for (auto &c : circles) {
          int x0 = c[0], y0 = c[1];
          if ((x - x0) * (x - x0) + (y - y0) * (y - y0) <= c[2] * c[2]) {
            res++;
            break;
          }
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<vector<int>>> testCases{{{2, 2, 1}}, {{2, 2, 2}, {3, 4, 1}}};
  for (auto &c : testCases) {
    cout << Solution().countLatticePoints(c) << endl;
  }
  return 0;
}
