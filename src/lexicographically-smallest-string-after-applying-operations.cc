#include <string>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        string res = s;
        for (int i = 0; i <= s.size(); i++) {
            s = s.substr(b, s.size()) + s.substr(0, b);
            for (int j = 0; j < 10; j++) {
                for (int k = 1; k < s.size(); k += 2) {
                    s[k] += a;
                    if (s[k] > '9') {
                        s[k] = '0' + (s[k] - '9' - 1);
                    }
                }
                if ((b % 2) != 0) {
                    for (int m = 0; m < 10; m++) {
                        for (int k = 0; k < s.size(); k += 2) {
                            s[k] += a;
                            if (s[k] > '9') {
                                s[k] = '0' + (s[k] - '9' - 1);
                            }
                        }
                        res = min(res, s);
                    }
                } else {
                    res = min(res, s);
                }
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int a = stringToInteger(line);
        getline(cin, line);
        int b = stringToInteger(line);

        string ret = Solution().findLexSmallestString(s, a, b);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
