#include <algorithm>
#include <bits/stdc++.h>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumBags(vector<int> &capacity, vector<int> &rocks,
                  int additionalRocks) {
    for (int i = 0; i < rocks.size(); i++) {
      capacity[i] -= rocks[i];
    }

    std::sort(capacity.begin(), capacity.end());

    int res = 0;
    for (auto &c : capacity) {
      if (additionalRocks >= c) {
        additionalRocks -= c;
        res++;
      } else {
        break;
      }
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<tuple<vector<int>, vector<int>, int>> testCases{
      {{2, 3, 4, 5}, {1, 2, 4, 4}, 2}, {{10, 2, 2}, {2, 2, 0}, 100}};
  for (auto &[capacity, rocks, additionalRocks] : testCases) {
    std::cout << Solution().maximumBags(capacity, rocks, additionalRocks)
              << std::endl;
  }
  return 0;
}
