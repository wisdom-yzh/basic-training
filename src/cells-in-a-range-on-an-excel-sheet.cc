#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> cellsInRange(string s) {
    char srcAlphabet = s[0], dstAlphabet = s[3];
    char srcNum = s[1], dstNum = s[4];

    vector<string> res;
    for (auto x = srcAlphabet; x <= dstAlphabet; x++) {
      for (auto y = srcNum; y <= dstNum; y++) {
        res.push_back(std::string{x, y});
      }
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<string> testCases{
      "K1:L2",
      "A1:F1",
  };
  for (auto &s : testCases) {
    for (auto &x : Solution().cellsInRange(s)) {
      cout << x << ' ';
    }
    cout << endl;
  }
  return 0;
}
