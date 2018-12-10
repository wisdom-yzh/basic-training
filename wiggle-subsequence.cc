#include <vector>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return 1;
        }
        vector<int> subMax(nums.size());
        vector<int> symbol(nums.size(), 0);
        subMax[0] = 1;
        for (size_t i = 1; i < nums.size(); i++) {
            int maxValue = 0;
            for (size_t j = 0; j < i; j++) {
                int value = 0;
                if (nums[i] != nums[j] &&
                    (j == 0 || (nums[i] - nums[j]) * symbol[j] < 0)) {
                    value = subMax[j] + 1;
                } else {
                    value = subMax[j];
                }
                if (value > maxValue) {
                    maxValue = std::max(value, maxValue);
                    symbol[i] = nums[i] - nums[j];
                }
            }
            subMax[i] = maxValue;
        }
        return subMax[nums.size() - 1];
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

        int ret = Solution().wiggleMaxLength(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
