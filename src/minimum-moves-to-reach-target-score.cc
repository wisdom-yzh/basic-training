#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minMoves(int target, int maxDoubles) {
    int ret = 0;
    while (target != 1 && maxDoubles != 0) {
      ret += target % 2 + 1;
      target /= 2;
      maxDoubles--;
    }
    ret += target - 1;
    return ret;
  }
};

int stringToInteger(string input) { return stoi(input); }

int main() {
  string line;
  while (getline(cin, line)) {
    int target = stringToInteger(line);
    getline(cin, line);
    int maxDoubles = stringToInteger(line);

    int ret = Solution().minMoves(target, maxDoubles);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
