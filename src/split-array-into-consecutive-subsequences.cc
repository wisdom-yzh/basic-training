#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        vector<std::pair<int, int>> ranges;

        for (const int &num: nums) {
            int rangeIndex = -1, rangeSize = 0;
            for (int i = 0; i < ranges.size(); i++) {
                if (num == ranges[i].second + 1 && (rangeIndex == -1 || rangeSize > ranges[i].second - ranges[i].first)) {
                    rangeIndex = i;
                    rangeSize = ranges[i].second - ranges[i].first + 1;
                }
            }
            if (rangeIndex == -1) {
                ranges.push_back(std::make_pair(num, num));
            } else {
                ranges[rangeIndex].second++;
            }
        }

        for (const auto &range: ranges) {
            if (range.second - range.first < 2) {
                return false;
            }
        }

        return true;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        bool ret = Solution().isPossible(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
