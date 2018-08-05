#include <string>
#include <vector>
#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

class Solution {
public:
    int doubleDecoded (string &s, int pos) {
        int num = 10 * (s[pos] - '0') + (s[pos + 1] - '0');
        return num <= 26 && num >= 10 ? 1 : 0;
    }

    int singleDecoded (string &s, int pos) {
        return s[pos] != '0' ? 1 : 0;
    }

    int numDecodings(string s) {
        const int SIZE = s.length();
        if (SIZE == 0) {
            return 0;
        }
        if (SIZE == 1) {
            return singleDecoded(s, 0);
        }
        if (SIZE == 2) {
            return doubleDecoded(s, 0) +
                   singleDecoded(s, 0) *
                   singleDecoded(s, 1);
        }
        int p = singleDecoded(s, SIZE - 1);
        int q = singleDecoded(s, SIZE - 2) * p +
                doubleDecoded(s, SIZE - 2);
        for (int i = SIZE - 3; i >= 0; i--) {
            int tmp = q;
            q = doubleDecoded(s, i) * p +
                singleDecoded(s, i) * q;
            p = tmp;
        }

        return q;
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
        string s = stringToString(line);
        
        int ret = Solution().numDecodings(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
