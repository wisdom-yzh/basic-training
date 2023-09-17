#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int countCollisions(string directions) {
    auto prev = directions[0];
    int res = 0, x = 0;

    for (int i = 1; i < directions.size(); i++) {
      auto curr = directions[i];

      if (prev == 'R' && curr == 'L') {
        res += 2 + x;
        prev = 'S';
        x = 0;
      } else if (prev == 'S' && curr == 'L' || prev == 'R' && curr == 'S') {
        res += 1 + x;
        prev = 'S';
        x = 0;
      } else {
        if (curr == 'R' && prev == 'R') {
          x++;
        }
        prev = curr;
      }
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<string> testCases{"RLRSLL", "LLRR"};
  for (auto &d : testCases) {
    cout << Solution().countCollisions(d) << endl;
  }
  return 0;
}
