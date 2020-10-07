#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int q = 0;

        if (typed.size() < name.size()) {
            return false;
        }

        for (int p = 0; p < name.size(); p++) {
            if (typed[q] != name[p]) {
                return false;
            }

            if (p < name.size() - 1 && name[p + 1] == name[p]) {
                q++;
                continue;
            }

            while (q < typed.size() && typed[q] == name[p]) {
                q++;
            }

            if (q == typed.size()) {
                return p == name.size() - 1;
            }
        }

        return q == typed.size();

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
        string name = stringToString(line);
        getline(cin, line);
        string typed = stringToString(line);

        bool ret = Solution().isLongPressedName(name, typed);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
