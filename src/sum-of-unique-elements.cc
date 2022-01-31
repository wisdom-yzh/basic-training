#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        std::map<int, int> dict;
        for (const auto &num: nums) {
            dict[num]++;
        }

        int res = 0;
        for (const auto [key, num]: dict) {
            if (num == 1) {
                res += key;
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().sumOfUnique(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
