#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int maxLength = 0;
        vector<vector<int>> dp(A.size(), vector<int>(B.size(), 0));

        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                if (A[i] == B[j]) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                    maxLength = std::max(maxLength, dp[i][j]);
                }
            }
        }

        return maxLength;
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
        getline(cin, line);
        vector<int> B = stringToIntegerVector(line);

        int ret = Solution().findLength(A, B);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
