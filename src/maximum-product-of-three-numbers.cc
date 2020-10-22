#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <limits>
#include <cmath>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;

        if (nums[l] >= 0 || nums[r] <= 0) {
            while (l <= r && nums[l] == 0) {
                l++;
            }
            while (r >= 0 && nums[r] == 0) {
                r--;
            }
            return r - l < 2 ? 0 : nums[r] * nums[r - 1] * nums[r - 2];
        }

        return std::max(nums[l] * nums[l + 1] * nums[r],
                nums[r] * nums[r - 1] * nums[r - 2]);
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

        int ret = Solution().maximumProduct(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
