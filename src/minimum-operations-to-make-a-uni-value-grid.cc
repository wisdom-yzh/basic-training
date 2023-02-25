#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
public:
  int minOperations(vector<vector<int>> &grid, int x) {
    vector<int> arr;
    for (auto &r : grid) {
      for (auto &c : r) {
        arr.push_back(c);
      }
    }
    std::sort(arr.begin(), arr.end());

    int median = arr[arr.size() / 2];
    int res = 0;
    for (auto &n : arr) {
      int delta = std::abs(median - n);
      if ((delta % x) != 0) {
        return -1;
      }
      res += delta / x;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<pair<vector<vector<int>>, int>> testCases{
      {{{2, 4}, {6, 8}}, 2}, {{{1, 5}, {2, 3}}, 1}, {{{1, 2}, {3, 4}}, 2}};
  for (auto &[grid, x] : testCases) {
    cout << Solution().minOperations(grid, x) << endl;
  }
  return 0;
}
