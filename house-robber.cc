#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return std::max(nums[0], nums[1]);
        }

        const size_t SIZE = nums.size();
        int robMax[SIZE];
        std::fill(robMax, robMax + SIZE, 0);

        robMax[SIZE - 1] = nums[SIZE - 1];
        robMax[SIZE - 2] = std::max(nums[SIZE - 1], nums[SIZE - 2]);
        for (int i = (int)SIZE - 3; i >= 0; i--) {
            robMax[i] = std::max(robMax[i + 1], nums[i] + robMax[i + 2]);
        }
        return robMax[0];
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
        
        int ret = Solution().rob(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
