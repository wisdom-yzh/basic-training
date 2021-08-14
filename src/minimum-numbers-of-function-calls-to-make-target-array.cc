#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int op = 0;
        int maxBit = 1;

        for (auto &num: nums) {
            int bit = 0;
            while (num > 0) {
                if ((num & 1) != 0) {
                    op++;
                }
                num >>= 1;
                bit++;
            }
            maxBit = std::max(maxBit, bit);
        }

        return op + maxBit - 1;
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

        int ret = Solution().minOperations(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
