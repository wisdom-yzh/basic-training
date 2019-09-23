#include <string>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int l = -1, r = 0;

        while (r != s.size() + 1) {
            if (r == s.size() || s[r] == ' ') {
                if (l != -1) {
                    std::reverse(s.begin() + l, s.begin() + r);
                    l = -1;
                }
            } else {
                if (l == -1) {
                    l = r;
                }
            }

            r++;
        }

        return s;
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

        string ret = Solution().reverseWords(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
