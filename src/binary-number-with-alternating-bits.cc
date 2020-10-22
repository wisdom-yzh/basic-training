#include <iostream>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        if (n == 0 || n == 1) {
            return true;
        }
        int last = n & 1;
        n /= 2;
        while (n > 0) {
            int current = n & 1;
            if (current == last) {
                return false;
            }
            last = current;
            n /= 2;
        }
        return true;
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
        int n = stringToInteger(line);

        bool ret = Solution().hasAlternatingBits(n);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
