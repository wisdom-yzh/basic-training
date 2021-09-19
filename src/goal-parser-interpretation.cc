#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    string interpret(string command) {
        string res;

        for (int i = 0; i < command.size(); i++) {
            if (command[i] == '(' && i < command.size() - 1 && command[i + 1] == ')') {
                res.push_back('o');
                i++;
            } else if (command[i] == '(' || command[i] == ')') {
                continue;
            } else {
                res.push_back(command[i]);
            }
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
        string command = stringToString(line);

        string ret = Solution().interpret(command);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
