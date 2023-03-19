#include <iostream>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

class Solution {
public:
  std::vector<int>
  platesBetweenCandles(std::string s, std::vector<std::vector<int>> &queries) {
    int n = s.length();
    std::vector<int> preSum(n);
    for (int i = 0, sum = 0; i < n; i++) {
      if (s[i] == '*') {
        sum++;
      }
      preSum[i] = sum;
    }
    std::vector<int> left(n);
    for (int i = 0, l = -1; i < n; i++) {
      if (s[i] == '|') {
        l = i;
      }
      left[i] = l;
    }
    std::vector<int> right(n);
    for (int i = n - 1, r = -1; i >= 0; i--) {
      if (s[i] == '|') {
        r = i;
      }
      right[i] = r;
    }
    std::vector<int> ans;
    for (auto &query : queries) {
      int x = right[query[0]], y = left[query[1]];
      ans.push_back(x == -1 || y == -1 || x >= y ? 0 : preSum[y] - preSum[x]);
    }
    return ans;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::pair<std::string, std::vector<std::vector<int>>>> testCases{
      {"**|**|***|", {{2, 5}, {5, 9}}},
      {"***|**|*****|**||**|*", {{1, 17}, {4, 5}}},
  };
  for (auto &[s, queries] : testCases) {
    for (auto &x : Solution().platesBetweenCandles(s, queries)) {
      std::cout << x << ' ';
    }
    std::cout << std::endl;
  }
  return 0;
}
