#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    constexpr static uint64_t MOD = 1e9 + 7;

    int concatenatedBinary(int n) {
        int res = 1;
        if (n == 1) {
            return res;
        }

        for (int i = 2; i <= n; i++) {
            res = (res * static_cast<uint64_t>(std::pow(
                2,
                (1 + std::floor(
                    std::log2(static_cast<double>(i))
                ))
            )) + i) % MOD;
        }

        return res;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().concatenatedBinary(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
