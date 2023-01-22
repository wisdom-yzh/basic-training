#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> construct2DArray(vector<int> &original, int m, int n) {
    if (m * n != original.size()) {
      return vector<vector<int>>{};
    }

    vector<vector<int>> res(m, vector<int>(n));
    int i = 0;
    for (int y = 0; y < m; y++) {
      for (int x = 0; x < n; x++) {
        res[y][x] = original[i++];
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<tuple<vector<int>, int, int>> testCases{
      {{1, 2, 3, 4}, 2, 2},
      {{1, 2, 3}, 1, 3},
      {{1, 2}, 1, 1},
  };
  for (auto &[o, m, n] : testCases) {
    for (auto &r : Solution().construct2DArray(o, m, n)) {
      for (auto &c : r) {
        cout << c << ' ';
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
