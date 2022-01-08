#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0, val = 0;
        for (int i = 0; i < gain.size(); i++) {
            val += gain[i];
            res = std::max(res, val);
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> gain = stringToIntegerVector(line);

        int ret = Solution().largestAltitude(gain);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
