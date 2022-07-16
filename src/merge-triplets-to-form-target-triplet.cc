#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target) {
    vector<int> res{0, 0, 0};
    for (auto &t : triplets) {
      if (t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]) {
        res[0] = std::max(t[0], res[0]);
        res[1] = std::max(t[1], res[1]);
        res[2] = std::max(t[2], res[2]);
      }
    }

    return res == target;
  }
};

int main() {
  auto testCases{vector<pair<vector<vector<int>>, vector<int>>>{
      {{{2, 5, 3}, {1, 8, 4}, {1, 7, 5}}, {2, 7, 5}},
      {{{1, 3, 4}, {2, 5, 8}}, {2, 5, 8}},
      {{{2, 5, 3}, {2, 3, 4}, {1, 2, 5}, {5, 2, 3}}, {5, 5, 5}},
      {{{3, 4, 5}, {4, 5, 6}}, {3, 2, 5}}}};
  for (auto &[triplets, target] : testCases) {
    cout << boolalpha << Solution().mergeTriplets(triplets, target) << endl;
  }
  return 0;
}
