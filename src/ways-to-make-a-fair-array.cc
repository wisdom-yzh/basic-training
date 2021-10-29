#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int sum = 0;
        vector<int> oddSum(nums.size() + 2, 0);

        for (int i = 0; i < nums.size(); i++) {
            oddSum[i + 2] = oddSum[i] + nums[i];
            sum += nums[i];
        }

        int maxNum = oddSum[(nums.size() - 1) % 2 == 0 ? nums.size() : nums.size() + 1];
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (
                (i % 2) == 0 &&
                (2 * (oddSum[i] + maxNum - oddSum[i + 1]) == sum - nums[i]) ||
                (i % 2) != 0 &&
                (2 * (oddSum[i + 1] + maxNum - oddSum[i + 2]) == sum - nums[i])
            ) {
                res++;
            }
        }
        return res;
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

        int ret = Solution().waysToMakeFair(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
