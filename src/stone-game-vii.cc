#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        const int size = stones.size();

        vector<int> preSum(stones);
        for (int i = 1; i < size; i++) {
            preSum[i] += preSum[i - 1];
        }

        vector<vector<int>> dp(size, vector<int>(size, 0));
        for (int i = 2; i <= size; i++) {
            for (int j = 0; j + i <= size; j++) {
                int k = i + j - 1;
                dp[j][k] = std::max(
                    preSum[k] - preSum[j] - dp[j + 1][k],
                    preSum[k - 1] - (j == 0 ? 0 : preSum[j - 1]) - dp[j][k - 1]
                );
            }
        }

        return dp[0][size - 1];
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
        vector<int> stones = stringToIntegerVector(line);

        int ret = Solution().stoneGameVII(stones);
        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
