#include <cstdint>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<long long>> splitPainting(vector<vector<int>> &segments) {
    std::map<int, long long> color;
    for (auto &seg : segments) {
      int l = seg[0], r = seg[1], delta = seg[2];
      color[l] += delta;
      color[r] -= delta;
    }

    vector<vector<long long>> res;
    for (auto iter = next(color.begin()); iter != color.end(); iter++) {
      iter->second += prev(iter)->second;
      if (prev(iter)->second != 0) {
        res.push_back({prev(iter)->first, iter->first, prev(iter)->second});
      }
    }

    return res;
  }
};

int main() {
  vector<vector<vector<int>>> testCases{
      {{1, 4, 5}, {4, 7, 7}, {1, 7, 9}},
      {{1, 7, 9}, {6, 8, 15}, {8, 10, 7}},
      {{1, 4, 5}, {1, 4, 7}, {4, 7, 1}, {4, 7, 11}}};

  for (auto &testCase : testCases) {
    for (const auto &row : Solution().splitPainting(testCase)) {
      for (const auto &x : row) {
        cout << x << ' ';
      }
      cout << endl;
    }
  }
  return 0;
}
