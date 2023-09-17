#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int minBitFlips(int start, int goal) {
    int res = 0;
    int x = std::max(start, goal);
    int y = std::min(start, goal);

    while (x != 0) {
      if ((x & 1) != (y & 1)) {
        res++;
      }
      y >>= 1;
      x >>= 1;
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<pair<int, int>> testCases{{10, 7}, {3, 4}};
  for (auto &[start, goal] : testCases) {
    std::cout << Solution().minBitFlips(start, goal) << std::endl;
  }
  return 0;
}
