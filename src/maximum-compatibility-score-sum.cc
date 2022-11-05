#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int maxCompatibilitySum(vector<vector<int>> &students,
                          vector<vector<int>> &mentors) {
    const int M = students.size();
    const int N = students[0].size();

    vector<vector<int>> g(M, vector<int>(M, 0));
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < M; j++) {
        for (int k = 0; k < N; k++) {
          g[i][j] += (students[i][k] == mentors[j][k]);
        }
      }
    }

    vector<int> v(M);
    std::iota(v.begin(), v.end(), 0);
    int res = 0;

    do {
      int val = 0;
      for (int i = 0; i < M; i++) {
        val += g[i][v[i]];
      }
      res = std::max(res, val);
    } while (std::next_permutation(v.begin(), v.end()));

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<pair<vector<vector<int>>, vector<vector<int>>>> testCases{
      {{{1, 1, 0}, {1, 0, 1}, {0, 0, 1}}, {{1, 0, 0}, {0, 0, 1}, {1, 1, 0}}},
      {{{0, 0}, {0, 0}, {0, 0}}, {{1, 1}, {1, 1}, {1, 1}}}};
  for (auto &[students, mentors] : testCases) {
    cout << Solution().maxCompatibilitySum(students, mentors) << endl;
  }
  return 0;
}
