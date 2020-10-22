#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        if (n <= 9) {
            return n;
        }
        uint64_t prefix = 10;
        uint64_t base = 9;
        uint64_t number = 1;
        while ((uint64_t)n > base * number) {
            n -= base * number;
            base *= 10;
            prefix *= 10;
            number++;
        }
        uint64_t high = (prefix / 10 - 1) + std::ceil(n / (double)number);
        uint64_t low = n % number;
        if (low == 0) low = number;
        low = number - low;
        while (low) {
            high /= 10;
            low--;
        }
        return high % 10;
    }
};

void test() {
    Solution s;
    for (int i = 1; i <= 100000; i++) {
        cout << s.findNthDigit(i) << ' ';
    }
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    // test();
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().findNthDigit(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
