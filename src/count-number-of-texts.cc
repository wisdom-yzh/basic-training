#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  constexpr static int MOD = 1e9 + 7;

  int countTexts(string pressedKeys) {
    vector<uint32_t> dp(pressedKeys.size(), 0);
    dp[dp.size() - 1] = 1;

    for (int i = dp.size() - 2; i >= 0; i--) {
      dp[i] = dp[i + 1];

      if (pressedKeys[i] == pressedKeys[i + 1]) {
        dp[i] += (i + 2 == dp.size() ? 1 : dp[i + 2]);
      }

      if (i + 2 < dp.size() && pressedKeys[i] == pressedKeys[i + 1] &&
          pressedKeys[i] == pressedKeys[i + 2]) {
        dp[i] += (i + 3 == dp.size() ? 1 : dp[i + 3]);
      }

      if (i + 3 < dp.size() && pressedKeys[i] == pressedKeys[i + 1] &&
          pressedKeys[i] == pressedKeys[i + 2] &&
          pressedKeys[i] == pressedKeys[i + 3] &&
          (pressedKeys[i] == '7' || pressedKeys[i] == '9')) {
        dp[i] += i + 4 == dp.size() ? 1 : dp[i + 4];
      }

      dp[i] %= MOD;
    }

    return dp[0];
  }
};

int main(int argc, char *argv[]) {
  vector<string> testCases{"22233", "222222222222222222222222222222222222"};
  for (auto &keys : testCases) {
    cout << Solution().countTexts(keys) << endl;
  }
  return 0;
}
