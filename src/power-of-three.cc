#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        int32_t maxNumber = 1162261467; // pow(3,19)
        if (n <= 0 || n > maxNumber) {
            return false;
        }
        return (maxNumber % n) == 0;
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
        
        bool ret = Solution().isPowerOfThree(n);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
