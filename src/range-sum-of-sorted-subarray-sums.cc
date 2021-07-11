#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        std::vector<int> arr;
        for (int i = 0; i < nums.size(); i++) {
            int n = 0;
            for (int j = i; j < nums.size(); j++) {
                n += nums[j];
                arr.push_back(n);
            }
        }

        std::sort(arr.begin(), arr.end());

        const int MOD = 1e9 + 7;
        uint32_t res = 0;
        for (int i = left - 1; i < right; i++) {
            res = (res + arr[i]) % MOD;
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
        int n = stringToInteger(line);
        getline(cin, line);
        int left = stringToInteger(line);
        getline(cin, line);
        int right = stringToInteger(line);

        int ret = Solution().rangeSum(nums, n, left, right);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
