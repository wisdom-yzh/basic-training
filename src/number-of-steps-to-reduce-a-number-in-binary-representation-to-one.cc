#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int res = 0;

        while (s.length() > 1) {
            int pos = s.find_last_of('1');

            if (pos != s.size() - 1) {
                res += s.size() - 1 - pos;
                s = s.substr(0, pos + 1);
            } else {
                s[pos] = '0';
                int i = pos - 1;
                for (; i >= 0; i--) {
                    if (s[i] == '0') {
                        s[i] = '1';
                        break;
                    } else {
                        s[i] = '0';
                    }
                }
                if (i < 0) {
                    s = "1" + s;
                }
                res++;
            }
        }

        return res;
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

        int ret = Solution().numSteps(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
