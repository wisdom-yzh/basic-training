#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <functional>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        std::unordered_map<int, int> dict;
        for (int i = 0; i < A.size(); i++) {
            dict[A[i]] = i;
        }

        int maxValue = 0;
        vector<vector<int>> dp(A.size(), vector<int>(A.size(), 0));

        for (int j = A.size() - 1; j >= 1; j--) {
            for (int i = j - 1; i >= 0; i--) {
                auto p = dict.find(A[i] + A[j]);
                if (p == dict.end()) {
                    dp[i][j] = 2;
                } else {
                    dp[i][j] = dp[j][p->second] + 1;
                }
                maxValue = std::max(maxValue, dp[i][j]);
            }
        }

        return maxValue >= 3 ? maxValue : 0;
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
        vector<int> A = stringToIntegerVector(line);

        int ret = Solution().lenLongestFibSubseq(A);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
