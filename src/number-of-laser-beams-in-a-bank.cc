#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int numberOfBeams(vector<string> &bank) {
    int prev = 0, res = 0;
    for (auto &row : bank) {
      int count = 0;
      for (auto &x : row) {
        if (x == '1') {
          count++;
        }
      }
      if (count != 0) {
        res += prev * count;
        prev = count;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<string>> testCases{{"011001", "000000", "010100", "001000"},
                                   {"000", "111", "000"}};
  for (auto &testCase : testCases) {
    cout << Solution().numberOfBeams(testCase) << endl;
  }
  return 0;
}
