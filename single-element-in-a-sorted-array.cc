#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int i = 0, j = nums.size() - 1, m;
        while (j > i) {
            m = (i + j) / 2;
            if (m % 2 == 0) {
                if (nums[m] == nums[m + 1]) {
                    i = m;
                } else if (nums[m] == nums[m - 1]) {
                    j = m;
                } else {
                    return nums[m];
                }
            } else {
                if (nums[m] == nums[m + 1]) {
                    j = m - 1;
                } else if (nums[m] == nums[m - 1]) {
                    i = m + 1;
                } else {
                    return nums[m];
                }
            }
        }
        return nums[i];
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

        int ret = Solution().singleNonDuplicate(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
