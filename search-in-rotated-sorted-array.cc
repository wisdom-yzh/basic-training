#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }

        int p = 0, q = nums.size() - 1, index = -1;
        while (p <= q) {
            int mid = (p + q) >> 1;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[p] < nums[q]) {
                // normal binary search
                if (nums[mid] > target) {
                    q = mid - 1;
                } else {
                    p = mid + 1;
                }
            } else {
                if (nums[p] > nums[mid]) { // rotate in [ p ... mid ]
                    if (target > nums[mid] && target <= nums[q]) {
                        p = mid + 1;
                    } else {
                        q = mid - 1;
                    }
                } else { // rotate in [ mid ... q ]
                    if (target >= nums[p] && target < nums[mid]) {
                        q = mid - 1;
                    } else {
                        p = mid + 1;
                    }
                }

            }
        }
        return index;
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
        int target = stringToInteger(line);
        
        int ret = Solution().search(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
