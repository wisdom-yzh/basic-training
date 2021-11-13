#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <numeric>
#include <iterator>
#include <map>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> sum(nums.begin(), nums.end());
        for (int i = 1; i < sum.size(); i++) {
            sum[i] += sum[i - 1];
        }

        int p = -1, res = 0, start = 0, end = 0;
        std::map<int, int> dict;

        for (int i = 0; i < nums.size(); i++) {
            auto iter = dict.find(nums[i]);
            if (iter == dict.end()) {
                dict.emplace(nums[i], i);
            } else {
                if (iter->second > p) {
                    p = iter->second;
                }
                iter->second = i;
            }

            int val = sum[i] - (p == -1 ? 0 : sum[p]);
            res = std::max(res, val);
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().maximumUniqueSubarray(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
