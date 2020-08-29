#include <string>
#include <iostream>
#include <sstream>
#include <cassert>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        string result = "";
        int index = 0;
        while (index < S.size()) {
            result += getParentheses(S, index);;
        }
        return result;
    }

    string getParentheses(string &s, int &index) {
        int start = index + 1;
        int diff = 0;
        do {
            if (s[index] == '(') {
                diff++;
            } else {
                diff--;
            }
            index++;
        } while (diff != 0);

        return s.substr(start, index - start - 1);
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

        string ret = Solution().removeOuterParentheses(S);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
