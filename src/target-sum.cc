#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        vector<int> reduceSums(nums.size());

        int reduceSum = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            reduceSum += nums[i];
            reduceSums[i] = reduceSum;
        }

        return findTargetSumWays(nums, 0, reduceSums, S);
    }

    int findTargetSumWays(vector<int> &nums, int index, vector<int> &reduceSums, int S) {
        if (index == nums.size()) {
            return S == 0 ? 1 : 0;
        }

        if (reduceSums[index] < std::abs(S)) {
            return 0;
        }
;
        return findTargetSumWays(nums, index + 1, reduceSums, S - nums[index]) +
            findTargetSumWays(nums, index + 1, reduceSums, S + nums[index]);
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
        int S = stringToInteger(line);

        int ret = Solution().findTargetSumWays(nums, S);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
