#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
#include <vector>
using namespace std;

class Solution {
public:
  long long minimumRemoval(vector<int> &beans) {
    std::sort(beans.begin(), beans.end());

    vector<long long> prefix(beans.begin(), beans.end());
    for (int i = 1; i < beans.size(); i++) {
      prefix[i] += prefix[i - 1];
    }

    long long res = std::numeric_limits<long long>::max();
    for (int i = 0; i < beans.size(); i++) {
      long long opts = 0;
      if (i > 0) {
        opts += prefix[i - 1];
      }
      if (i < beans.size() - 1) {
        long long n = beans.size() - 1 - i;
        opts += (prefix[beans.size() - 1] - prefix[i]) - (n * beans[i]);
      }
      res = std::min(res, opts);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> testCases{{4, 1, 6, 5}, {2, 10, 3, 2}};
  for (auto &testCase : testCases) {
    cout << Solution().minimumRemoval(testCase) << endl;
  }
  return 0;
}
