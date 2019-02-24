#include <vector>
#include <string>
#include <numeric>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        size_t p = 0, q = 0;
        int minSize = numeric_limits<int>::max();
        int current = 0;
        while (q < nums.size()) {
            current += nums[q];
            q++;
            while (current >= s) {
                minSize = std::min(minSize, static_cast<int>(q - p));
                if (minSize == 1) {
                    return 1;
                }
                current -= nums[p];
                p++;
            }
        }
        return minSize == numeric_limits<int>::max() ? 0 : minSize;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

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
        int s = stringToInteger(line);
        getline(cin, line);
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().minSubArrayLen(s, nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
