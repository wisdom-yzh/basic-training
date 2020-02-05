#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }

        int prevLeft = -1, prevRight = -1;
        int left = 0, right = 0;
        int64_t count = 0, product = 1;

        while (left < nums.size()) {
            while (right < nums.size()) {
                product *= nums[right];
                if (product >= k) break;
                right++;
            }

            count += (right - left) * static_cast<int64_t>(right - left + 1) / 2;
            if (prevRight != -1 && left <= prevRight) {
                count -= (prevRight - left) * static_cast<int64_t>(prevRight - left + 1) / 2;
            }

            prevLeft = left;
            prevRight = right;

            if (right == nums.size()) {
                break;
            }

            while (product >= k) {
                product /= nums[left];
                left++;
            }
            right++;
        }

        return count;
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
        int k = stringToInteger(line);

        int ret = Solution().numSubarrayProductLessThanK(nums, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
