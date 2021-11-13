#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <numeric>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = std::accumulate(nums.begin(), nums.end(), -x);
        if (target == 0) {
            return nums.size();
        }

        int p = 0, q = 0, val = 0, res = -1;
        while (q < nums.size()) {
            val += nums[q];
            while (val > target && p < q) {
                val -= nums[p];
                p++;
            }
            if (val == target) {
                if (res == -1) {
                    res = nums.size() - 1 - q + p;
                } else {
                    res = std::min(res, (int)nums.size() - 1 - q + p);
                }
            }
            q++;
        }

        return res;
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
        int x = stringToInteger(line);

        int ret = Solution().minOperations(nums, x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
