#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cassert>
#include <map>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        map<int, int> dict;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                dict[nums[i] * nums[j]]++;
            }
        }

        int res = 0;
        for (auto &[num, count]: dict) {
            res += 8 * count * (count - 1) / 2;
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

        int ret = Solution().tupleSameProduct(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
