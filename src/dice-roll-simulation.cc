#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    const static int MOD = 1e9 + 7;

    int dieSimulator(int n, vector<int>& r) {
        vector<vector<int64_t>> dp(n, vector<int64_t>(6, 0));
        for (int i = 0; i < 6; i++) {
            dp[0][i] = 1;
        }

        for (int i = 1; i < n; i++){
            for (int j = 0; j < 6; j++){
                for (int k = 0; k < 6; k++) {
                    dp[i][j] += dp[i - 1][k];
                }

                if (i == r[j]) {
                    dp[i][j]--;
                } else if (i > r[j]) {
                    for (int k = 0; k < 6; k++) {
                        if (j != k) {
                            dp[i][j] = (dp[i][j] - dp[i - r[j] - 1][k] + MOD) % MOD;
                        }
                    }
                }
            }
        }

        int64_t ans = 0;
        for (int i = 0; i < 6; i++) {
            ans = (ans + dp[n-1][i]) % MOD;
        }
        return static_cast<int>(ans);
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                return !isspace(ch);
                }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        getline(cin, line);
        vector<int> rollMax = stringToIntegerVector(line);

        int ret = Solution().dieSimulator(n, rollMax);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
