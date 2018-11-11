#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int dp[amount + 1];
        fill(dp, dp + amount + 1, INT_MAX);
        if (amount == 0) {
            return 0;
        }
        return innerCoinChange(coins, amount, dp);
    }

    int innerCoinChange(vector<int> &coins, int amount, int *dp) {
        if (amount == 0) {
            return 0;
        }
        if (dp[amount] != INT_MAX) {
            return dp[amount];
        }
        int count = -1;
        for (auto &coin: coins) {
            if (coin > amount) {
                continue;
            } else {
                int temp = innerCoinChange(coins, amount - coin, dp); 
                if (temp == -1) {
                    continue;
                }
                
                if (count == -1) {
                    count = temp + 1;
                } else {
                    count = std::min(count, temp + 1);
                }
            }
        }
        dp[amount] = count;
        return dp[amount];
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
        vector<int> coins = stringToIntegerVector(line);
        getline(cin, line);
        int amount = stringToInteger(line);
        
        int ret = Solution().coinChange(coins, amount);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
