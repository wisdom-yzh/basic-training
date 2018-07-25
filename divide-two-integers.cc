#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool isLessThanZero = (dividend > 0) ^ (divisor > 0);
        if (dividend == 0) {
            return 0;
        }
        long long lDividend = labs(dividend);
        long long lDivisor = labs(divisor);
        long long result = 0;

        while (lDividend >= lDivisor) {
            long long tmpResult = 1;
            long long tmpDivisor = lDivisor << 1;
            while (lDividend >= tmpDivisor) {
                tmpResult <<= 1;
                tmpDivisor <<= 1;
            }
            lDividend -= (tmpDivisor >> 1);
            result += tmpResult;
        }

        result = isLessThanZero ? -result : result;
        if (result > INT_MAX) {
            return INT_MAX;
        } else if (result < INT_MIN) {
            return INT_MIN;
        }
        return result;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int dividend = stringToInteger(line);
        getline(cin, line);
        int divisor = stringToInteger(line);
        
        int ret = Solution().divide(dividend, divisor);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
