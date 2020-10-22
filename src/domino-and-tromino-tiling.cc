#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numTilings(int N) {
        int mod = 1000000007;
        int n = N;
        if (n == 1) {
            return 1;
        }

        vector<vector<int>> dp(n + 2, vector<int>(3));
        dp[0][0] = dp[1][0] = dp[1][1] = dp[1][2] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                switch (j) {
                    case 0:
                        dp[i + 1][0] += dp[i][0], dp[i + 1][0] %= mod;
                        dp[i + 2][0] += dp[i][0], dp[i + 2][0] %= mod;
                        dp[i + 2][1] += dp[i][0], dp[i + 2][1] %= mod;
                        dp[i + 2][2] += dp[i][0], dp[i + 2][2] %= mod;
                        break;
                    case 1:
                        dp[i + 1][2] += dp[i][1], dp[i + 1][2] %= mod;
                        dp[i + 1][0] += dp[i][1], dp[i + 1][0] %= mod;
                        break;
                    case 2:
                        dp[i + 1][1] += dp[i][2], dp[i + 1][1] %= mod;
                        dp[i + 1][0] += dp[i][2], dp[i + 1][0] %= mod;
                        break;
                }
            }
        }

        return dp[n - 1][0];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int N = stringToInteger(line);

        int ret = Solution().numTilings(N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
