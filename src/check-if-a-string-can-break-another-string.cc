#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        std::sort(s1.begin(), s1.end());
        std::sort(s2.begin(), s2.end());

        int check = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (check == 0) {
                if (s1[i] < s2[i]) {
                    check = -1;
                } else if (s1[i] > s2[i]) {
                    check = 1;
                }
            } else if (
                (check == 1 && s1[i] < s2[i]) ||
                (check == -1 && s1[i] > s2[i])
            ) {
                return false;
            }
        }

        return true;
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
        string s1 = stringToString(line);
        getline(cin, line);
        string s2 = stringToString(line);

        bool ret = Solution().checkIfCanBreak(s1, s2);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
