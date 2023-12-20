#include <bits/stdc++.h>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
public:
  long long waysToBuyPensPencils(int total, int cost1, int cost2) {
    int64_t res = 0;

    int count1 = total / cost1;
    for (size_t i = 0; i <= count1; i++) {
      int remain = total - i * cost1;
      res += (remain / cost2) + 1;
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<tuple<int, int, int>> testCases{{20, 10, 5}, {5, 10, 10}};
  for (auto &[t, c1, c2] : testCases) {
    cout << Solution().waysToBuyPensPencils(t, c1, c2) << endl;
  }
  return 0;
}
