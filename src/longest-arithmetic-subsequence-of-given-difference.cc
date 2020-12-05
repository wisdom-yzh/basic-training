#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dict;
        dict[arr[0]] = 1;

        int res = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (dict[arr[i] - difference] == 0) {
                dict[arr[i]] = 1;
            } else {
                int newVal = dict[arr[i] - difference] + 1;
                res = std::max(res, newVal);
                dict[arr[i]] = newVal;
            }
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> arr = stringToIntegerVector(line);
        getline(cin, line);
        int difference = stringToInteger(line);

        int ret = Solution().longestSubsequence(arr, difference);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
