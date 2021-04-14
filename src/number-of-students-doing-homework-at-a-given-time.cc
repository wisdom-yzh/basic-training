#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int res = 0;
        for (int i = 0; i < startTime.size(); i++) {
            if (queryTime >= startTime[i] && queryTime <= endTime[i]) {
                res++;
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
        vector<int> startTime = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> endTime = stringToIntegerVector(line);
        getline(cin, line);
        int queryTime = stringToInteger(line);

        int ret = Solution().busyStudent(startTime, endTime, queryTime);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
