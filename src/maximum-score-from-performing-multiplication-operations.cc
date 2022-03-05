#include <limits>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        const int N = nums.size(), M = multipliers.size();
        int res = std::numeric_limits<int>::min();
        vector<vector<int>> dp(M + 1, vector<int>(M + 1, res));
        dp[0][0] = 0;

        for (int i = 1; i <= M; i++) {
            for (int p = 0; p <= i; p++) {
                int q = i - p;

                if (p > 0) {
                    dp[p][q] = dp[p - 1][q] + nums[p - 1] * multipliers[i - 1];
                }
                if (q > 0) {
                    dp[p][q] = std::max(dp[p][q], dp[p][q - 1] + nums[N - q] * multipliers[i - 1]);
                }
                if (i == M) {
                    res = std::max(res, dp[p][q]);
                }
            }
        }

        return res;
    }
};

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
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> multipliers = stringToIntegerVector(line);
        
        int ret = Solution().maximumScore(nums, multipliers);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
