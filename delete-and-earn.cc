#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <tuple>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        std::map<int, int> cntDict;

        for (const auto &num: nums) {
            cntDict[num]++;
        }
        vector<int> dp(cntDict.size());
        vector<int> numsUniq(dp.size());
        int index = 0;

        for (const auto &item: cntDict) {
            int num, count;
            std::tie(num, count) = item;
            numsUniq[index] = num;
            if (index == 0) {
                dp[index] = num * count;
            } else if (index == 1) {
                dp[index] = num * count + ((numsUniq[index - 1] == num - 1) ? 0 : dp[index - 1]);
            } else {
                dp[index] = num * count + dp[index - 2];
                if (numsUniq[index - 1] != num - 1) {
                    dp[index] = std::max(dp[index], num * count + dp[index - 1]);
                } else if (index >= 3) {
                    dp[index] = std::max(dp[index], num * count + dp[index - 3]);
                }
            }
            index++;
        }

        if (dp.size() == 0) {
            return 0;
        } else if (dp.size() < 2) {
            return dp[0];
        }
        return std::max(dp[dp.size() - 1], dp[dp.size() - 2]);
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

        int ret = Solution().deleteAndEarn(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
