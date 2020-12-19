#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        std::vector<int> indexes;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 1) {
                indexes.push_back(i);
            }
        }
        if (indexes.size() < k) {
            return 0;
        }

        int result = 0;

        for (auto iter = indexes.begin(); iter != prev(indexes.end(), k - 1); iter++) {
            int frontCount = 0, backCount = 0;

            if (iter == indexes.begin()) {
                frontCount = *iter - 0 + 1;
            } else {
                frontCount = *iter - *(prev(iter, 1));
            }

            if (next(iter, k - 1) == prev(indexes.end(), 1)) {
                backCount = nums.size() - *(next(iter, k - 1));
            } else {
                backCount = *(next(iter, k)) - *(next(iter, k - 1));
            }

            result += frontCount * backCount;
        }

        return result;
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

        int ret = Solution().numberOfSubarrays(nums, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
