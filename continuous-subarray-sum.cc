#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) {
            return false;
        }

        if (k == 0) {
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i - 1] == 0 && nums[i] == 0) {
                    return true;
                }
            }
            return false;
        }

        if (k < 0) {
            k = -k;
        }

        std::map<int, int> dict;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int mod = sum % k;

            if (mod == 0 && i >= 1) {
                return true;
            }

            if (dict.find(mod) == dict.end()) {
                dict[mod] = i;
            } else if (i - dict[mod] > 1) {
                return true;
            }
        }

        return false;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);

        bool ret = Solution().checkSubarraySum(nums, k);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
