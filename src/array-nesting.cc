#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxNestingCycle = 0;
        vector<bool> hasBeenUsed(nums.size(), false);

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int cycle = 0;
            if (hasBeenUsed[num]) {
                continue;
            }
            int next = num, prev;
            do {
                hasBeenUsed[next] = true;
                prev = next;
                next = nums[prev];
                cycle++;
            } while (next != num);

            maxNestingCycle = std::max(cycle, maxNestingCycle);
        }

        return maxNestingCycle;
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

        int ret = Solution().arrayNesting(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
