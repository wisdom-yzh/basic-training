#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if (k == 0) {
            return vector<int>(code.size(), 0);
        }

        vector<int> result(code.size(), 0);
        int sum = std::accumulate(code.begin(), next(code.begin(), std::abs(k)), 0);
        if (k < 0) {
            result[-k] = sum;
        } else {
            result[code.size() - 1] = sum;
        }

        for (int i = 1; i < code.size(); i++) {
            sum = sum - code[i - 1] + code[(i - 1 + std::abs(k)) % code.size()];
            if (k < 0) {
                result[(i - k) % code.size()] = sum;
            } else {
                result[i - 1] = sum;
            }
        }

        return result;
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
        vector<int> code = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);

        vector<int> ret = Solution().decrypt(code, k);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
