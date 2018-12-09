#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        uint64_t result = 1;
        uint64_t base = a % 1337;
        for (int i = 0; i < static_cast<int>(b.size()); i++) {
            uint64_t n = b.size() - 1 - i;
            if (!b[i]) {
                continue;
            }
            uint64_t x = myPow(base, b[i]) % 1337;
            for (uint64_t j = 0; j < n; j++) {
                x = myPow((x * x) % 1337, 5) % 1337;
            }
            result = (result * x) % 1337;
        }
        return result;
    }

    uint64_t myPow(uint64_t base, int exp) {
        if (exp == 0) {
            return 1;
        }
        if (exp == 1) {
            return base % 1337;
        }
        int result;
        if (exp % 2 == 0) {
            result = myPow(base, exp / 2);
            return (result * result) % 1337;
        }
        return (myPow(base, exp - 1) * base) % 1337;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

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
        int a = stringToInteger(line);
        getline(cin, line);
        vector<int> b = stringToIntegerVector(line);
        
        int ret = Solution().superPow(a, b);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
