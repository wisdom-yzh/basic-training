#include <string>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxPower(string s) {
        if (!s.size()) {
            return 0;
        }

        int maxPow = 1, pow = 1;
        int ch = s[0];
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ch) {
                pow++;
            } else {
                maxPow = std::max(maxPow, pow);
                pow = 1;
                ch = s[i];
            }
        }

        return std::max(maxPow, pow);
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

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);

        int ret = Solution().maxPower(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
