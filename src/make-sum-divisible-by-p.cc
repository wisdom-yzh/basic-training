#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        uint64_t sum = 0;

        for (int i = 0; i < nums.size(); i++) {
           sum += static_cast<uint64_t>(nums[i]);
        }

        if (sum % p == 0) {
            return 0;
        }

        uint64_t mod0 = sum % p;
        int res = nums.size();
        map<uint64_t, int> dict;
        dict[0] = -1;

        sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += static_cast<uint64_t>(nums[i]);
            uint64_t mod1 = sum % p;
            dict[mod1] = i;

            uint64_t x = mod1 >= mod0 ? (mod1 - mod0) : (mod1 - mod0 + p);
            if (dict.find(x) != dict.end()) {
                res = min(res, i - dict[x]);
            }
        }
        return res == nums.size() ? -1 : res;
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
        int p = stringToInteger(line);

        int ret = Solution().minSubarray(nums, p);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
