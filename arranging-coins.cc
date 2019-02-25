#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        return static_cast<int>((std::sqrt(static_cast<double>(n) * 8.0 + 1) - 1) / 2.0);
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().arrangeCoins(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
