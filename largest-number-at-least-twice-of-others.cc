#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int a = -1, b = -1, maxIndex = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > a) {
                b = a;
                a = nums[i];
                maxIndex = i;
            } else if (nums[i] > b) {
                b = nums[i];
            }
        }

        return a >= b * 2 ? maxIndex : -1;
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

        int ret = Solution().dominantIndex(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
