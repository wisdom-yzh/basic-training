#include <iostream>
#include <sstream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        std::sort(coins.begin(), coins.end());
        int x = 0;
        for (auto &y: coins) {
            if (y > x + 1) {
                break;
            }
            x += y;
        }
        return x + 1;
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
        vector<int> coins = stringToIntegerVector(line);
        
        int ret = Solution().getMaximumConsecutive(coins);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
