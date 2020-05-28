#include <iostream>
#include <string>
#include <cassert>
#include <deque>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        std::deque<char> q1, q2;

        for (const auto &ch: S) {
            if (ch == '#') {
                if (!q1.empty()) q1.pop_back();
            } else {
                q1.push_back(ch);
            }
        }

        for (const auto &ch: T) {
            if (ch == '#') {
                if (!q2.empty()) q2.pop_back();
            } else {
                q2.push_back(ch);
            }
        }

        return q1 == q2;
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
        string S = stringToString(line);
        getline(cin, line);
        string T = stringToString(line);

        bool ret = Solution().backspaceCompare(S, T);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
