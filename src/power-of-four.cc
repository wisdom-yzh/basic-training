#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && ((n & (n - 1)) == 0) &&
            (n & 0b10101010101010101010101010101010) == 0;
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
        int num = stringToInteger(line);
        
        bool ret = Solution().isPowerOfFour(num);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
