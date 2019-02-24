#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        size_t left = 0, right = nums.size() - 1, mid;
        bool find = false;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] >= nums[left]) {
                if (mid < nums.size() - 1 && nums[mid + 1] < nums[mid]) {
                    mid++;
                    find = true;
                    break;
                }
                left = mid + 1;
            } else {
                if (mid > 0 && nums[mid - 1] > nums[mid]) {
                    find = true;
                    break;
                }
                right = mid - 1;
            }
        }

        if (!find) mid = 0;
        return nums[mid];
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
        
        int ret = Solution().findMin(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
