#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cassert>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string S) {
        string str;
        for (auto &ch: S) {
            if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z') {
                str.push_back(ch);
            }
        }

        std::reverse(str.begin(), str.end());

        int i = 0;
        for (auto &ch: S) {
            if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z') {
                ch = str[i++];
            }
        }

        return S;
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
        string S = stringToString(line);

        string ret = Solution().reverseOnlyLetters(S);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
