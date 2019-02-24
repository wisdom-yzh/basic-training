#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<vector<int>> setList;
        std::sort(nums.begin(), nums.end());
        for (auto iter = nums.begin(); iter != nums.end(); iter++) {
            const auto item = *iter;
            vector<int> currentSet = { item };
            for (auto &set: setList) {
                if (set.size() + 1 < currentSet.size()) {
                    continue;
                }
                const int maxElem = set[set.size() - 1];
                if (item % maxElem == 0) {
                    currentSet.assign(set.begin(), set.end());
                    currentSet.push_back(item);
                }
            }
            setList.push_back(currentSet);
        }
        return *std::max_element(setList.begin(), setList.end(), [](vector<int> &set1, vector<int> &set2) {
            return set1.size() < set2.size();
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

        vector<int> ret = Solution().largestDivisibleSubset(nums);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
