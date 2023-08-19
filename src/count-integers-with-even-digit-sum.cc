#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countEven(int num) {
    int res = 0;
    for (int i = 1; i <= num; i++) {
      int sum = 0, x = i;
      while (x != 0) {
        sum += (x % 10);
        x /= 10;
      }
      res += 1 - (sum % 2);
    }

    return res;
  }
};

int stringToInteger(string input) { return stoi(input); }

int main() {
  string line;
  while (getline(cin, line)) {
    int num = stringToInteger(line);

    int ret = Solution().countEven(num);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
