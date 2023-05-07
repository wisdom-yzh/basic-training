#include <bits/stdc++.h>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  bool checkValid(vector<vector<int>> &matrix) {
    const int N = matrix.size();
    for (int i = 0; i < N; i++) {
      set<int> s(matrix[i].begin(), matrix[i].end());
      if (s.size() != N) {
        return false;
      }

      set<int> s2;
      for (int j = 0; j < N; j++) {
        if (!s2.insert(matrix[j][i]).second) {
          return false;
        }
      }
    }

    return true;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<vector<int>>> testCases{
      {{1, 2, 3}, {3, 1, 2}, {2, 3, 1}},
      {{1, 1, 1}, {1, 2, 3}, {1, 2, 3}},
  };
  for (auto &testCase : testCases) {
    cout << boolalpha << Solution().checkValid(testCase) << endl;
  }
  return 0;
}
