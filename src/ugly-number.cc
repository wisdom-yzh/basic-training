#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if (num== 0) {
            return false;
        }
        if (num== 1) {
            return true;
        }
        return ((num% 2== 0 && isUgly(num/ 2)) ||
                (num% 3== 0 && isUgly(num/ 3)) ||
                (num% 5== 0 && isUgly(num/ 5)));
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

        bool ret = Solution().isUgly(num);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
