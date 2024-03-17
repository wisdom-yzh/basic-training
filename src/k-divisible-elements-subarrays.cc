#include <bits/stdc++.h>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
public:
  int countDistinct(vector<int> &nums, int k, int p) {
    unordered_map<int, unordered_set<int>> hashMap;
    int res = 0;

    for (int i = 0; i < nums.size(); i++) {
      long long hash = 0, cntP = 0, mod = 1e9 + 7, pow = 200;
      for (int j = i; j < nums.size(); j++) {
        if (nums[j] % p == 0)
          cntP++;
        if (cntP > k)
          break;
        hash = (hash * pow + nums[j]) % mod;
        if (hashMap[j - i + 1].insert(hash).second)
          res++;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<tuple<vector<int>, int, int>> testCases{{{2, 3, 3, 2, 2}, 2, 2},
                                                 {{1, 2, 3, 4}, 4, 1}};
  for (auto &[nums, k, p] : testCases) {
    cout << Solution().countDistinct(nums, k, p) << endl;
  }
  return 0;
}
