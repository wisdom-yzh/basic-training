#include <cmath>
#include <limits>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res = std::numeric_limits<int>::max();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                res = std::min(res, std::abs(i - start));
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        getline(cin, line);
        int start = stringToInteger(line);
        
        int ret = Solution().getMinDistance(nums, target, start);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
