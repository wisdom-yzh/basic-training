#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(3, 0));

        dp[0][nums[0] % 3] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < 3; j++ ) {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j]);
            }
            for (int j = 0; j < 3; j++) {
                int x = dp[i - 1][j] + nums[i];
                int mod = x % 3;
                dp[i][mod] = std::max(dp[i][mod], x);
            }
        }

        return dp[nums.size() - 1][0];
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

        int ret = Solution().maxSumDivThree(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
