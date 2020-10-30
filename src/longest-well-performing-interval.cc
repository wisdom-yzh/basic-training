#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int ret = 0;
        std::unordered_map<int, int> dict;

        hours[0] = hours[0] > 8 ? 1 : -1;
        for (int i = 1; i < hours.size(); i++) {
            hours[i] = (hours[i] > 8 ? 1 : -1) + hours[i - 1];
        }

        for (int i = 0; i < hours.size(); i++) {
            if (hours[i] > 0) {
                ret = i + 1;
            } else {
                dict.emplace(hours[i], i);
                auto iter = dict.find(hours[i] - 1);
                if (iter != dict.end()) {
                    ret = std::max(ret, i - iter->second);
                }
            }
        }

        return ret;
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
        vector<int> hours = stringToIntegerVector(line);

        int ret = Solution().longestWPI(hours);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
