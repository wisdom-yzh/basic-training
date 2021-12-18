#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;

        return 28 * weeks + weeks * (weeks - 1) / 2 * 7 + (weeks + weeks + 1 + days) * days / 2;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().totalMoney(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
