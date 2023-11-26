#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  long long numberOfWays(string s) {
    long long res = 0, left[s.size()][2], right[s.size()][2];

    left[0][0] = 0;
    left[0][1] = 0;
    for (size_t i = 1; i < s.size(); i++) {
      left[i][0] = left[i - 1][0];
      left[i][1] = left[i - 1][1];
      if (s[i - 1] == '0') {
        left[i][0]++;
      } else {
        left[i][1]++;
      }
    }

    right[s.size() - 1][0] = 0;
    right[s.size() - 1][1] = 0;
    for (int i = s.size() - 2; i >= 0; i--) {
      right[i][0] = right[i + 1][0];
      right[i][1] = right[i + 1][1];
      if (s[i + 1] == '0') {
        right[i][0]++;
      } else {
        right[i][1]++;
      }
    }

    for (size_t i = 1; i < s.size() - 1; i++) {
      if (s[i] == '0') {
        res += left[i][1] * right[i][1];
      } else {
        res += left[i][0] * right[i][0];
      }
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<string> testCases{"001101", "11100"};
  for (auto &s : testCases) {
    std::cout << Solution().numberOfWays(s) << std::endl;
  }
  return 0;
}
