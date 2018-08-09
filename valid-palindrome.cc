#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string handled;
        for (char & ch: s) {
            if (ch >= 'A' && ch <= 'Z') {
                handled += ch - 'A' + 'a';
            } else if ((ch >= 'a' && ch <= 'z') ||
                    (ch >= '0' && ch <= '9')) {
                handled += ch;
            }
        }
        int len = handled.length();
        for (auto i = 0; i < len / 2; i++) {
            if (handled[i] != handled[len - 1 - i]) {
                return false;
            }
        }
        return true;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        bool ret = Solution().isPalindrome(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
