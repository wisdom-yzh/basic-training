#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        dfs(nums, 0, 0, sum);
        return sum;
    }

    void dfs(vector<int> &nums, int pos, int val, int &sum) {
        if (pos == nums.size()) {
            sum += val;
            return;
        }
        
        dfs(nums, pos + 1, val ^ nums[pos], sum);
        dfs(nums, pos + 1, val, sum);
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
        
        int ret = Solution().subsetXORSum(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
