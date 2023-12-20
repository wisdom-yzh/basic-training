#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumProduct(vector<int> &nums, int k) {
    std::priority_queue<int, vector<int>, std::greater<>> q;
    for (auto &n : nums) {
      q.push(n);
    }

    for (size_t i = 0; i < k; i++) {
      int x = q.top();
      q.pop();
      q.push(x + 1);
    }

    uint64_t res = 1;
    while (!q.empty()) {
      res = (res * q.top()) % 1000000007;
      q.pop();
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<pair<vector<int>, int>> testCases{{{0, 4}, 5}, {{6, 3, 3, 2}, 2}};
  for (auto &[nums, k] : testCases) {
    cout << Solution().maximumProduct(nums, k) << endl;
  }
  return 0;
}
