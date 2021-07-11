#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4) {
            return 0;
        }

        std::sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;

        int res = std::numeric_limits<int>::max();

        for (int i = 0; i <= 3; i++) {
            res = std::min(res, nums[r - i] - nums[l + 3 - i]);
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

        int ret = Solution().minDifference(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
