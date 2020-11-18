#include <string>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int l = 0, a = 0;
        for (auto &ch: s) {
            if (ch == 'L') {
                l++;
            } else {
                l = 0;
            }
            if (ch == 'A') {
                a++;
            }
            if (l > 2 || a > 1) {
                return false;
            }
        }
        return true;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
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

        bool ret = Solution().checkRecord(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}