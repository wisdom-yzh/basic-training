#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

// worst case O(n)
// emmmm......
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int p = 0, q = nums.size() - 1;
        while (p <= q) {
            int mid = (p + q) / 2;
            if (nums[mid] == target || nums[p] == target || nums[q] == target) {
                return true;
            }
            if (nums[p] < nums[q]) {
                if (target < nums[mid]) {
                    q = mid - 1;
                } else {
                    p = mid + 1;
                }
            } else {
                if (nums[mid] > nums[p]) {
                    if (target < nums[mid] && target > nums[p]) {
                        q = mid - 1;
                    } else {
                        p = mid + 1;
                    }
                } else if (nums[mid] < nums[p]) {
                    if (target > nums[mid] && target < nums[q]) {
                        p = mid + 1;
                    } else {
                        q = mid - 1;
                    }
                } else {
                    p++;
                }
            }
        }
        return false;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        bool ret = Solution().search(nums, target);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
