#include <iostream>
using namespace std;

class Solution {
public:
  static constexpr int MOD = 1000000007;

  int minNonZeroProduct(int p) {
    long long ret = ((1LL << p) - 1) % MOD, k = (1LL << (p - 1)) - 1;

    for (long long multi = ((1LL << p) - 2) % MOD; k; k >>= 1) {
      if (k & 1) {
        ret = ret * multi % MOD;
      }
      multi = multi * multi % MOD;
    }
    return ret;
  }
};

int stringToInteger(string input) { return stoi(input); }

int main() {
  string line;
  while (getline(cin, line)) {
    int p = stringToInteger(line);

    int ret = Solution().minNonZeroProduct(p);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
