#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        int64_t rest = goal;
        for (auto &num: nums) {
            rest -= num;
        }
        rest = std::abs(rest);
        int a = rest / limit;
        int b = rest % limit;

        return b == 0 ? a : (a + 1);
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
        int limit = stringToInteger(line);
        getline(cin, line);
        int goal = stringToInteger(line);
        
        int ret = Solution().minElements(nums, limit, goal);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
