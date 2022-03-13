#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 == 0 || n % 3 == 1) {
                n /= 3;
                continue;
            }
            return false;
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
        
        bool ret = Solution().checkPowersOfThree(n);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
