#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <iterator>
#include <cassert>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res;
        stack<int> stk;

        for (auto &ch: s) {
            if (ch == '(') {
                res.push_back(ch);
                stk.push(res.size() - 1);
            } else if (ch == ')') {
                if (!stk.empty()) {
                    stk.pop();
                    res.push_back(ch);
                }
            } else {
                res.push_back(ch);
            }
        }

        while (!stk.empty()) {
            int idx = stk.top();
            res.erase(next(res.begin(), idx));
            stk.pop();
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

        string ret = Solution().minRemoveToMakeValid(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
