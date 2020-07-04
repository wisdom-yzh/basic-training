#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string S) {
        const int LEFT_PARENTHESE = -1;

        stack<int> parenthese;
        for (const auto &ch: S) {
            if (ch == '(') {
                parenthese.push(LEFT_PARENTHESE);
            } else {
                int num = 0;
                int top = parenthese.top();
                while (top != LEFT_PARENTHESE) {
                    num += top;
                    parenthese.pop();
                    top = parenthese.top();
                }
                parenthese.pop();
                parenthese.push(num == 0 ? 1 : num * 2);
            }
        }

        int sum = 0;
        while (!parenthese.empty()) {
            sum += parenthese.top();
            parenthese.pop();
        }
        return sum;
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

        int ret = Solution().scoreOfParentheses(S);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
