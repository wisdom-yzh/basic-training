#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        int maxFront = 0, maxBack = 0, result = INT_MIN;
        for (size_t i = 0; i < nums.size(); i++) {
            maxFront = maxFront ? maxFront * nums[i] : nums[i];
            maxBack = maxBack ? maxBack * nums[n - 1 - i] : nums[n - i - 1];
            result = max(result, max(maxBack, maxFront));
        }
        return result;
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

        int ret = Solution().maxProduct(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
