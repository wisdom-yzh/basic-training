#include <algorithm>
#include <array>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  int largestCombination(vector<int> &candidates) {
    std::array<int, 24> bits;
    std::fill(bits.begin(), bits.end(), 0);

    int res = 0;
    for (auto &c : candidates) {
      for (int i = 0; i < 24; i++) {
        bits[i] += (c & 1);
        c /= 2;
        res = std::max(res, bits[i]);
      }
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> testCases{{16, 17, 71, 62, 12, 24, 14}, {8, 8}};
  for (auto &candidates : testCases) {
    cout << Solution().largestCombination(candidates) << endl;
  }
  return 0;
}
