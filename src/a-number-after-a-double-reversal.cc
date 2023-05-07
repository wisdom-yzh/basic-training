#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isSameAfterReversals(int num) { return !(num != 0 && (num % 10) == 0); }
};

int stringToInteger(string input) { return stoi(input); }

string boolToString(bool input) { return input ? "True" : "False"; }

int main() {
  string line;
  while (getline(cin, line)) {
    int num = stringToInteger(line);

    bool ret = Solution().isSameAfterReversals(num);

    string out = boolToString(ret);
    cout << out << endl;
  }
  return 0;
}
