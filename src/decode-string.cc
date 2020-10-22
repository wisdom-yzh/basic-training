#include <string>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    struct State {
        int bracket;
        int number;
        string innerString;
        string result;
    };

    string decodeString(string s) {
        State state { 0, 0, "", "" };
        for (size_t i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch >= '0' && ch <= '9') {
                if (state.bracket == 0) {
                    state.number *= 10;
                    state.number += (ch - '0');
                } else {
                    state.innerString.push_back(ch);
                }
            } else if (ch == '[') {
                state.bracket++;
                if (state.bracket > 1) {
                    state.innerString.push_back(ch);
                }
            } else if (ch == ']') {
                state.bracket--;
                if (state.bracket == 0) {
                    auto str = decodeString(state.innerString);
                    for (int i = 0; i < state.number; i++) {
                        state.result += str;
                    }
                    state.number = 0;
                    state.innerString.clear();
                } else {
                    state.innerString.push_back(ch);
                }
            } else {
                if (state.bracket == 0) {
                    state.result.push_back(ch);
                } else {
                    state.innerString.push_back(ch);
                }
            }
        }
        if (state.result.empty()) {
            return state.innerString;
        }
        return state.result;
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

        string ret = Solution().decodeString(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
