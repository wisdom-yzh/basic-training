#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        uint64_t left = 1, right = 10e6 - 1;

        while (left < right) {
            uint64_t mid = (left + right) / 2;
            auto val = value(nums, mid);
            if (val > threshold) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return right;
    }

    uint64_t value(vector<int>& nums, uint64_t divider) {
        return std::accumulate(nums.begin(), nums.end(), static_cast<uint64_t>(0), [&] (uint64_t &acc, int &num) {
            acc += static_cast<uint64_t>(std::ceil(static_cast<double>(num) / divider));
            return acc;
        });
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
        int threshold = stringToInteger(line);

        int ret = Solution().smallestDivisor(nums, threshold);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
