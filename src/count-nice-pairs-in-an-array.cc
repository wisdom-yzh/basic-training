#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int countNicePairs(vector<int>& nums) {
        map<int, int> dict;
        for (auto &num: nums) {
            dict[num - this->rev(num)]++;
        }

        uint64_t res = 0;
        for (auto &[_, count]: dict) {
            res = (res + ((uint64_t)count * (count - 1)) / 2) % MOD;
        }
        return res;
    }

    int rev(int num) {
        auto str = std::to_string(num);
        std::reverse(str.begin(), str.end());
        return std::stoi(str);
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
        
        int ret = Solution().countNicePairs(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
