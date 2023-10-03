#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<long long> kthPalindrome(vector<int> &queries, int intLength) {
    vector<long long> res;
    int last = std::pow(10, ((intLength + 1) / 2)) - 1;
    int first = std::pow(10, ((intLength + 1) / 2) - 1);
    int maxK = last - first + 1;

    for (auto &q : queries) {
      if (q > maxK) {
        res.push_back(-1);
        continue;
      }

      auto qStr = std::to_string(first + q - 1);
      auto qStrRev =
          (intLength % 2 == 0) ? qStr : qStr.substr(0, qStr.size() - 1);
      std::reverse(qStrRev.begin(), qStrRev.end());
      res.push_back(std::stoll(qStr + qStrRev));
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<pair<vector<int>, int>> testCases{{{1, 2, 3, 4, 5, 90}, 3},
                                           {{2, 4, 6}, 4}};
  for (auto &[q, i] : testCases) {
    for (auto &x : Solution().kthPalindrome(q, i)) {
      cout << x << ' ';
    }
    cout << endl;
  }
  return 0;
}
