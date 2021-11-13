#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <limits>
#include <map>
#include <iterator>
using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size(), std::numeric_limits<int>::min());
        map<int, int> s;

        dp[nums.size() - 1] = nums.back();
        s[nums.back()]++;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + k < nums.size() - 1) {
                auto iter = s.find(dp[i + k + 1]);
                if (iter->second > 1) {
                    iter->second--;
                } else {
                    s.erase(iter);
                }
            }
            dp[i] = nums[i] + prev(s.end())->first;
            s[dp[i]]++;
        }

        return dp[0];
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
        int k = stringToInteger(line);

        int ret = Solution().maxResult(nums, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
