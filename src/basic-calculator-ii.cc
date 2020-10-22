#include <string>
#include <cassert>
#include <stack>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int getLevel(char op) {
        switch (op) {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            case 0:
                return 0;
        }
        return 0;
    }

    bool isOper(char ch) {
        return ch == '+' || ch == '-' ||
            ch == '*' || ch == '/';
    }

    bool isNum(char ch) {
        return ch >= '0' && ch <= '9';
    }

    void handle(stack<int> &numStack, stack<char> &opStack, char op) {
        if (opStack.empty()) {
            opStack.push(op);
            return;
        }
        int level = getLevel(op);
        int topLevel = getLevel(opStack.top());
        while (level <= topLevel) {
            int num2 = numStack.top();
            numStack.pop();
            int num1 = numStack.top();
            numStack.pop();
            int topOp = opStack.top();
            opStack.pop();
            int result;
            switch (topOp) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    result = num1 / num2;
                    break;
            }
            numStack.push(result);
            if (!opStack.empty()) {
                topLevel = getLevel(opStack.top());
            } else {
                break;
            }
        }
        if (op) {
            opStack.push(op);
        }
    }

    int calculate(string s) {
        stack<int> numStack;
        stack<char> opStack;
        auto iter = s.begin(), numBegin = iter;
        int status = 0;
        for (;;) {
            char ch = iter == s.end() ? '\0' : *iter;
            if (status == 0) {
                if (isOper(ch)) {
                    handle(numStack, opStack, ch);
                } else if (isNum(ch)) {
                    numBegin = iter;
                    status = 1;
                }
                iter++;
            } else {
                if (isNum(ch)) {
                    iter++;
                } else {
                    numStack.push(stoi(string(numBegin, iter)));
                    status = 0;
                }
            }
            if (ch == '\0') {
                break;
            }
        }
        while (!opStack.empty()) {
            handle(numStack, opStack, '\0');
        }
        return numStack.top();
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
        
        int ret = Solution().calculate(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
