#include <string>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <iterator>
#include <cmath>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        for (auto iter = s.begin(); iter != prev(s.end()); ) {
            if (shouldErase(*iter, *next(iter))) {
                iter = s.erase(iter);
                iter = s.erase(iter);
                if (s.empty()) {
                    break;
                }
                iter = s.begin();
            } else {
                iter++;
            }
        }

        return s;
    }

    bool shouldErase(char a, char b) {
        return abs(a - b) == ('a' - 'A');
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

        string ret = Solution().makeGood(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}