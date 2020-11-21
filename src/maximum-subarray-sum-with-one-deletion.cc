#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <limits>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(2, 0));
        dp[0][0] = dp[0][1] = arr[0];

        int maxValue = dp[0][0];

        for (int i = 1; i < arr.size(); i++) {
            dp[i][0] = std::max(dp[i - 1][0] + arr[i], arr[i]);
            dp[i][1] = std::max(dp[i - 1][1] + arr[i], dp[i - 1][0]);

            maxValue = std::max(maxValue, *std::max_element(dp[i].begin(), dp[i].end()));
        }

        return maxValue;
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
        vector<int> arr = stringToIntegerVector(line);

        int ret = Solution().maximumSum(arr);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
