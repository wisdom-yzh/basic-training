#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int res1 = 0, res2 = 0, value = 0;

        for (const auto &num: nums) {
            value += num;
            if (value < 0) {
                value = 0;
            } else {
                res1 = std::max(res1, value);
            }
        }

        value = 0;

        for (const auto &num: nums) {
            value += num;
            if (value > 0) {
                value = 0;
            } else {
                res2 = std::min(res2, value);
            }
        }

        return std::max(res1, -res2);
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

        int ret = Solution().maxAbsoluteSum(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
