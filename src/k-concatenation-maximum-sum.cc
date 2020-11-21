#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    const static int MOD = 1e9 + 7;

    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int64_t preSum = 0, maxPreSum = 0;
        int64_t postSum = 0, maxPostSum = 0;
        int64_t midSum = 0, maxMidSum = 0, totalSum = 0;

        for (int i = 0; i < arr.size(); i++) {
            totalSum += arr[i];

            preSum += arr[i];
            maxPreSum = std::max(preSum, maxPreSum);

            postSum += arr[arr.size() - i - 1];
            maxPostSum = std::max(postSum, maxPostSum);

            midSum += arr[i];
            if (midSum < 0) {
                midSum = 0;
            }
            maxMidSum = std::max(midSum, maxMidSum);
        }

        if (k == 1) {
            return maxMidSum;
        }

        if (totalSum <= 0) {
            return std::max(maxMidSum, maxPreSum + maxPostSum);
        }

        int maxSeries = (totalSum * (k - 2) + maxPostSum + maxPreSum) % MOD;
        return std::max(static_cast<int>(maxMidSum), maxSeries);
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
        vector<int> arr = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);

        int ret = Solution().kConcatenationMaxSum(arr, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
