#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) {
            return 1;
        }
        if (n == 3) {
            return 2;
        }
        int maxValue = 1;
        for (int i = 2; i <= n - 1; i++) {
            int mod = n % i;
            int num1 = n / i, num2 = n / i + 1;
            int count1 = i - mod, count2 = mod;
            int part1 = 1, part2 = 1;
            while (count1 > 0) {
                part1 *= num1;
                count1--;
            }
            while (count2 > 0) {
                part2 *= num2;
                count2--;
            }
            maxValue = max(maxValue, part1 * part2);
        }
        return maxValue;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().integerBreak(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
