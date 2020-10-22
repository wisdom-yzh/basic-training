#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:

    int combinationSum4(vector<int>& nums, int target, vector<int> &table) {
        if (target == 0) {
            return 1;
        }
        if (table[target] != -1) {
            return table[target];
        }
        int sum = 0;
        for (int &num: nums) {
            if (num < target) {
                table[target - num] = combinationSum4(nums, target - num, table);
                sum += table[target - num];
            } else if (num == target) {
                sum++;
            }
        }
        return sum;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> table(target + 1, -1);
        return combinationSum4(nums, target, table);
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
        int ret = Solution().combinationSum4(nums, target);
        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
