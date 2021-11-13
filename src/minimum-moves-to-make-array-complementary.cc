#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> diff(limit * 2 + 2, 0);

        int n = nums.size();
        for (int i = 0; i < n / 2; i++) {
            int A = nums[i], B = nums[n - 1 - i];

            int l = 2, r = 2 * limit;
            diff[l] += 2, diff[r + 1] -= 2;

            l = 1 + min(A, B), r = limit + max(A, B);
            diff[l] += -1, diff[r + 1] -= -1;

            l = A + B, r = A + B;
            diff[l] += -1, diff[r + 1] -= -1;
        }

        int res = n, sum = 0;
        for (int i = 2; i <= 2 * limit; i++) {
            sum += diff[i];
            if (sum < res) {
                res = sum;
            }
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
        int limit = stringToInteger(line);

        int ret = Solution().minMoves(nums, limit);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
