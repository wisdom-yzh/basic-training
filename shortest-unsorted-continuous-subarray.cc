#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int left = -1, right = -1;
        vector<int> sorted(nums);

        std::sort(sorted.begin(), sorted.end());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != sorted[i]) {
                left = i;
                break;
            }
        }

        if (left == -1) {
            return 0;
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] != sorted[i]) {
                right = i;
                break;
            }
        }

        return right - left + 1;
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

        int ret = Solution().findUnsortedSubarray(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
