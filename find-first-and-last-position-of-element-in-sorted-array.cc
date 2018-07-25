#include <sstream>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result { -1, -1 };
        if (nums.empty()) {
            return result;
        }

        int p = 0, q = nums.size() - 1;
        int mid = -1;
        bool found = false;
        while (p <= q) {
            mid = (p + q) >> 1;
            if (nums[mid] == target) {
                found = true;
                break;
            } else if (nums[mid] < target) {
                p = mid + 1;
            } else {
                q = mid - 1;
            }
        }

        if (found) {
            result[0] = this->searchLeftRange(nums, 0, mid, target);
            result[1] = this->searchRightRange(nums, mid, nums.size() - 1, target);
        }

        return result;
    }

    int searchLeftRange(vector<int> &nums, int p, int q, int target) {
        if (q == 0 || nums[q - 1] < target) {
            return q;
        }
        int mid = (p + q) >> 1;
        if (nums[mid] < target) {
            return this->searchLeftRange(nums, mid + 1, q, target);
        }
        if (nums[mid - 1] < target || mid == 0) {
            return mid;
        }
        return this->searchLeftRange(nums, p, mid - 1, target);
    }

    int searchRightRange(vector<int> &nums, int p, int q, int target) {
        if (p == (int)nums.size() - 1 || nums[p + 1] > target) {
            return p;
        }
        int mid = (p + q) >> 1;
        if (nums[mid] > target) {
            return this->searchRightRange(nums, p, mid - 1, target);
        }
        if (nums[mid + 1] > target || mid == (int)nums.size() - 1) {
            return mid;
        }
        return this->searchRightRange(nums, mid + 1, q, target);
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        vector<int> ret = Solution().searchRange(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
