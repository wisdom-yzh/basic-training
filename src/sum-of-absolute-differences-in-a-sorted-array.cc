#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        vector<int> presum(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            presum[i] += presum[i - 1];
        }

        for (int i = 0; i < nums.size(); i++) {
            res[i] = (nums[i] * i) -
                (i == 0 ? 0 : presum[i - 1]) +
                presum[nums.size() - 1] - presum[i] -
                nums[i] * (nums.size() - i - 1);
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

        vector<int> ret = Solution().getSumAbsoluteDifferences(nums);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
