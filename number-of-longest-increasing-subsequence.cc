#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        vector<int> dp(nums.size(), 1), count(nums.size(), 1);
        int maxLen = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                        maxLen = std::max(maxLen, dp[i]);
                    } else if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j];
                    }
                } else if (nums[i] == nums[j]) {
                    if (dp[i] < dp[j]) {
                        dp[i] = dp[j];
                    }
                }
            }
        }

        int maxCount = 0;
        for (int i = 0; i < dp.size(); i++) {
            if (maxLen == dp[i]) {
                maxCount += count[i];
            }
        }

        return maxCount;
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

        int ret = Solution().findNumberOfLIS(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
