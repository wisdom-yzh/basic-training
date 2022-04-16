#include <algorithm>
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class Solution {
public:
    bool checkZeroOnes(string s) {
        int one = 0, zero = 0, count = 0;

        char current = 0;
        for (auto &ch: s) {
            if (current != ch) {
                if (ch == '1') {
                    zero = std::max(zero, count);
                } else {
                    one = std::max(one, count);
                }
                current = ch;
                count = 1;
            } else {
                count++;
            }
        }

        if (s.back() == '0') {
            zero = std::max(zero, count);
        } else {
            one = std::max(one, count);
        }

        return one > zero;
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
        
        bool ret = Solution().checkZeroOnes(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
