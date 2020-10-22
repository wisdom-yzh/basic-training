#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iterator>
using namespace std;

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if (nums.size() == 1) {
            return std::to_string(nums[0]);
        }
        if (nums.size() == 2) {
            return std::to_string(nums[0]) + "/" + std::to_string(nums[1]);
        }

        std::ostringstream oss;
        oss << nums[0] << "/(";
        for (int i = 1; i < nums.size() - 1; i++) {
            oss << nums[i] << '/';
        }
        oss << nums[nums.size() - 1] << ")";
        return oss.str();
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

        string ret = Solution().optimalDivision(nums);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
