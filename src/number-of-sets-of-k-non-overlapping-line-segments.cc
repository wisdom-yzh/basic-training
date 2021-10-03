#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    constexpr static int MODULO = 1e9 + 7;

    int numberOfSets(int n, int k) {
        int dp[1000][1001][2];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i <= n - 1; i++) {
            dp[i][0][0] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % MODULO;
                dp[i][j][1] = dp[i - 1][j][1];
                if (j > 0) {
                    dp[i][j][1] += dp[i - 1][j - 1][0];
                    dp[i][j][1] %= MODULO;
                    dp[i][j][1] += dp[i - 1][j - 1][1];
                    dp[i][j][1] %= MODULO;
                }
            }
        }

        return (dp[n - 1][k][0] + dp[n - 1][k][1]) % MODULO;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        getline(cin, line);
        int k = stringToInteger(line);

        int ret = Solution().numberOfSets(n, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
