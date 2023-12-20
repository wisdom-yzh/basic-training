#include <bits/stdc++.h>
#include <limits>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumCardPickup(vector<int> &cards) {
    int res = -1;
    std::map<int, int> dict;

    for (int i = 0; i < cards.size(); i++) {
      auto iter = dict.find(cards[i]);
      if (iter != dict.end()) {
        auto dist = i - iter->second + 1;
        if (res == -1 || res > dist) {
          res = dist;
        }
        iter->second = i;
      } else {
        dict.emplace(cards[i], i);
      }
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> testCases{{3, 4, 2, 3, 4, 7}, {1, 0, 5, 3}};
  for (auto &cards : testCases) {
    cout << Solution().minimumCardPickup(cards) << endl;
  }
  return 0;
}
