#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int permutation(int n, int r) {
        if (r == 0) {
            return 1;
        }
        return n * permutation(n - 1, r - 1);
    }

    int countNumbersWithUniqueDigits(int n) {
        int sum = 1;
        if (n > 0) {
            int end = (n > 10) ? 10 : n;
            for (int i = 0; i < end; i++) {
                sum += 9 * permutation(9, i);
            }
        }
        return sum;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().countNumbersWithUniqueDigits(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
