#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <map>
using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        std::map<int, int> dict;

        for (auto &num: nums) {
            dict[num]++;
        }

        while (!dict.empty()) {
            int num, count;
            std::tie(num, count) = *dict.begin();
            dict.erase(dict.begin());

            for (int i = 1; i < k; i++) {
                auto iter = dict.find(num + i);
                if (iter == dict.end() || iter->second < count) {
                    return false;
                }
                if (iter->second == count) {
                    dict.erase(iter);
                } else {
                    iter->second -= count;
                }
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

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);

        bool ret = Solution().isPossibleDivide(nums, k);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
