#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        bool begin = true;
        vector<int> subArray;
        vector<vector<int>> subArrayNegativeIndex;

        for (auto &num: nums) {
            if (num == 0) {
                begin = true;
                continue;
            }

            if (begin) {
                subArray.push_back(1);
                subArrayNegativeIndex.push_back(vector<int>());
                begin = false;
            } else {
                subArray.back()++;
            }

            if (num < 0) {
                subArrayNegativeIndex.back().push_back(subArray.back() - 1);
            }
        }

        int maxCount = 0;
        for (int i = 0; i < subArray.size(); i++) {
            if (subArrayNegativeIndex[i].size() % 2 == 0) {
                maxCount = std::max(maxCount, static_cast<int>(subArray[i]));
            } else {
                maxCount = std::max(
                    maxCount,
                    std::max(
                        subArrayNegativeIndex[i].back(),
                        static_cast<int>(subArray[i]) - 1 - subArrayNegativeIndex[i].front()
                    )
                );
            }
        }

        return maxCount;
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

        int ret = Solution().getMaxLen(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
