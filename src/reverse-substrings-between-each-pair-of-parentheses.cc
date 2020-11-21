#include <iostream>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <stack>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        std::stack<std::string> stk;
        stk.push("");

        for (auto &ch: s) {
            if (ch == '(') {
                stk.push("");
            } else if (ch == ')') {
                auto s = std::move(stk.top());
                stk.pop();
                std::reverse(s.begin(), s.end());

                if (stk.empty()) {
                    stk.push(s);
                } else {
                    stk.top().append(s);
                }
            } else {
                stk.top().push_back(ch);
            }
        }

        return stk.top();
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

        string ret = Solution().reverseParentheses(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
