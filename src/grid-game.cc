#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class Solution {
public:
  long long gridGame(vector<vector<int>> &grid) {
    vector<uint64_t> firstSum(grid[0].size()), secondSum(grid[0].size());
    firstSum[0] = grid[0][0];
    secondSum[0] = grid[1][0];
    for (int i = 1; i < grid[0].size(); i++) {
      firstSum[i] = grid[0][i] + firstSum[i - 1];
      secondSum[i] = grid[1][i] + secondSum[i - 1];
    }

    uint64_t res = std::numeric_limits<uint64_t>::max();
    for (int i = 0; i < firstSum.size(); i++) {
      res = std::min(res, std::max(firstSum.back() - firstSum[i],
                                   i == 0 ? 0 : secondSum[i - 1]));
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<vector<int>>> testCases{
      {{2, 5, 4}, {1, 5, 1}},
      {{3, 3, 1}, {8, 5, 2}},
      {{1, 3, 1, 15}, {1, 3, 3, 1}},
  };
  for (auto &testCase : testCases) {
    cout << Solution().gridGame(testCase) << endl;
  }
  return 0;
}
