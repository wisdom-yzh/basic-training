#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> dict, harmoryDict;
        for (const auto &num: nums) {
            dict[num]++;
            harmoryDict[num]++;
            harmoryDict[num - 1]++;
        }
        int max = 0;
        for (const auto &pair: dict) {
            if (dict.find(pair.first + 1) == dict.end()) {
                continue;
            }
            max = std::max(max, harmoryDict[pair.first]);
        }
        return max;
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

        int ret = Solution().findLHS(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
