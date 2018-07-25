#include <iostream>
#include <string>
#include <cassert>
using namespace std;

const int BEFORE_SCAN = 0;
const int SCANNING = 1;
const int AFTER_SCAN = 2;

class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
        int scanStatus = BEFORE_SCAN;
        unsigned long long scanValue = 0;
        bool lessThanZero = false, overflow = false;

        for (string::iterator iter = str.begin();
                iter != str.end() && scanStatus != AFTER_SCAN && !overflow; 
                iter++) {
            char c = *iter;
            if (c >= '0' && c <= '9') {
                if (scanStatus == BEFORE_SCAN) {
                    scanStatus = SCANNING;
                }
                scanValue = scanValue * 10 + static_cast<int>(c - '0');
                if ((!lessThanZero && scanValue > INT_MAX) ||
                    (lessThanZero && scanValue > ((unsigned long long)INT_MAX + 1))) {
                    overflow = true;
                }
            } else if (c == '-') {
                if (scanStatus == BEFORE_SCAN) {
                    scanStatus = SCANNING;
                    lessThanZero = true;
                } else {
                    scanStatus = AFTER_SCAN;
                }
            } else if (c == '+') {
                if (scanStatus == BEFORE_SCAN) {
                    scanStatus = SCANNING;
                } else {
                    scanStatus = AFTER_SCAN;
                }
            } else if (c == ' ') {
                if (scanStatus == SCANNING) {
                    scanStatus = AFTER_SCAN;
                }
            } else {
                // invalid char
                if (scanStatus == BEFORE_SCAN) {
                    break;
                }
                if (scanStatus == SCANNING) {
                    scanStatus = AFTER_SCAN;
                }
            }
        }

        if (overflow) {
            result = lessThanZero ? INT_MIN : INT_MAX;
        } else {
            result = lessThanZero ? -scanValue : scanValue;
        }
        return result;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (unsigned int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string str = stringToString(line);

        int ret = Solution().myAtoi(str);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
