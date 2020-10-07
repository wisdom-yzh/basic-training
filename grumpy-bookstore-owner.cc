#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int res = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 0) {
                res += customers[i];
            }
        }

        int left = 0, right = X - 1, value = 0, maxValue = 0;
        for (int i = 0; i < X; i++) {
            if (grumpy[i] == 1) {
                value += customers[i];
            }
            maxValue = std::max(maxValue, value);
        }

        while (right < customers.size() - 1) {
            if (grumpy[left] == 1) {
                value -= customers[left];
            }
            left++;
            right++;
            if (grumpy[right] == 1) {
                value += customers[right];
            }
            maxValue = std::max(maxValue, value);
        }

        return res + maxValue;
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
        vector<int> customers = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> grumpy = stringToIntegerVector(line);
        getline(cin, line);
        int X = stringToInteger(line);

        int ret = Solution().maxSatisfied(customers, grumpy, X);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
