#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        uint64_t MOD = 1000000007;
        vector<int> dp(n);

        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = dp[i - 1] * 2;
            if (dp[i] >= MOD) {
                dp[i] -= MOD;
            }
        }

        int l = 0, r = n - 1;
        int res = 0;
        while (l <= r) {
            int sum = nums[l] + nums[r];
            if (sum <= target) {
                res += dp[r - l];
                if (res >= MOD) {
                    res -= MOD;
                }
                l++;
            } else {
                r--;
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        int ret = Solution().numSubseq(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
