#include <cmath>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  bool isThree(int n) {
    if (n == 1) {
      return false;
    }
    int x = static_cast<int>(sqrt(n));
    if (x * x != n) {
      return false;
    }
    return isPrime(x);
  }

  bool isPrime(int x) {
    for (int i = 2, s = sqrt(x); i <= s; i++) {
      if ((x % i) == 0) {
        return false;
      }
    }
    return true;
  }
};

int stringToInteger(string input) { return stoi(input); }

string boolToString(bool input) { return input ? "True" : "False"; }

int main() {
  string line;
  while (getline(cin, line)) {
    int n = stringToInteger(line);

    bool ret = Solution().isThree(n);

    string out = boolToString(ret);
    cout << out << endl;
  }
  return 0;
}
