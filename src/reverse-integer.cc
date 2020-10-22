#include <string>
#include <iostream>
using namespace std;

class Solution {
    public:
        int reverse(int x) {
            bool lessThanZero = false;
            if (x < 0) {
                x = -x;
                lessThanZero = true;
            }
            unsigned long long result = 0;
            while (x > 0) {
                result *= 10;
                result += (x % 10);
                if (result != (int)result) {
                    return 0;
                }
                x /= 10;
            }

            return lessThanZero ? -result : result;
        }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);

        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
