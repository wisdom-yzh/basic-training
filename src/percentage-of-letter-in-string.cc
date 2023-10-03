#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int percentageLetter(string s, char letter) {
    int count = 0, total = 0;
    for (auto &ch : s) {
      total++;
      if (ch == letter) {
        count++;
      }
    }
    return 100 * count / total;
  }
};

int main(int argc, char *argv[]) {
  vector<pair<string, char>> testCases{{"foobar", 'o'}, {"jjjj", 'k'}};
  for (auto &[s, l] : testCases) {
    cout << Solution().percentageLetter(s, l) << endl;
  }
  return 0;
}
