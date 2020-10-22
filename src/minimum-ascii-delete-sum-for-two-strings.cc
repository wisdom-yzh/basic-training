#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <limits>
#include <cassert>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int minValue = std::accumulate(s1.begin(), s1.end(), 0);
        minValue += std::accumulate(s2.begin(), s2.end(), 0);

        const int M = s1.size(), N = s2.size();
        vector<vector<int>> dp(M, vector<int>(N, minValue));

        dp[0][0] -= (s1[0] == s2[0]) ? (s1[0] * 2) : 0;

        for (int i = 1; i < M; i++) {
            dp[i][0] = std::min(dp[i - 1][0], minValue - ((s1[i] == s2[0]) ? (s1[i] * 2) : 0));
        }
        for (int j = 1; j < N; j++) {
            dp[0][j] = std::min(dp[0][j - 1], minValue - ((s1[0] == s2[j]) ? (s2[j] * 2) : 0));
        }

        for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                dp[i][j] = dp[i - 1][j - 1] - ((s1[i] == s2[j]) ? (2 * static_cast<int>(s1[i])) : 0);
                dp[i][j] = std::min(dp[i][j], dp[i - 1][j]);
                dp[i][j] = std::min(dp[i][j], dp[i][j - 1]);
            }
        }

        return dp[M - 1][N - 1];
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s1 = stringToString(line);
        getline(cin, line);
        string s2 = stringToString(line);

        int ret = Solution().minimumDeleteSum(s1, s2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
