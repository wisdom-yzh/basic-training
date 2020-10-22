#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        std::vector<int> maxProfitValue(prices.size(), 0);

        int maxDiffValue = prices[prices.size() - 1], maxDiffIndex = prices.size() - 1;
        for (int i = prices.size() - 2; i >= 0; i--) {
            // prices[j] + maxProfitValue[i]是一个常量，内层循环可以被干掉
            // for (int j = i + 1; j < prices.size(); j++) {
            //     if (prices[j] - prices[i] - fee > 0) {
            //         profit = std::max(profit,  prices[j] - prices[i] - fee + maxProfitValue[j]);
            //     } else {
            //         profit = std::max(profit, maxProfitValue[j]);
            //     }
            // }
            maxProfitValue[i] = std::max(maxProfitValue[i + 1], maxDiffValue - prices[i] - fee);
            if (maxProfitValue[i] + prices[i] > maxDiffValue) {
                maxDiffValue = maxProfitValue[i] + prices[i];
                maxDiffIndex = i;
            }
        }

        return maxProfitValue[0];
    }

    int maxProfitByDp(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        dp[0][1] = 0;
        dp[0][0] = -prices[0] - fee;

        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] - prices[i] - fee);
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[prices.size() - 1][1];
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
        vector<int> prices = stringToIntegerVector(line);
        getline(cin, line);
        int fee = stringToInteger(line);

        int ret = Solution().maxProfit(prices, fee);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
