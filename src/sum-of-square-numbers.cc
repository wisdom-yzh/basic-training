#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c == 0) {
            return true;
        }
        for (int i = 1, max = std::sqrt(c); i <= max; i++) {
            int rest = c - i * i;
            if (std::fabs(std::sqrt(rest) - static_cast<int>(std::sqrt(rest))) <= 1e-8) {
                return true;
            }
        }
        return false;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int c = stringToInteger(line);

        bool ret = Solution().judgeSquareSum(c);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
