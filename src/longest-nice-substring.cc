#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <cassert>
#include <set>
#include <array>
using namespace std;

class Solution {
public:
    string longestNiceSubstring(string s) {
        string res;
        for (int i = 0; i < s.size(); i++) {
            std::array<bool, 26> lower, upper;
            std::fill(lower.begin(), lower.end(), false);
            std::fill(upper.begin(), upper.end(), false);

            for (int j = i; j < s.size(); j++) {
                if (s[j] >= 'A' && s[j] <= 'Z') {
                    upper[s[j] - 'A'] = true;
                }
                if (s[j] >= 'a' && s[j] <= 'z') {
                    lower[s[j] - 'a'] = true;
                }

                bool nice = true;
                for (int k = 0; k < 26; k++) {
                    if (lower[k] != upper[k]) {
                        nice = false;
                        break;
                    }
                }
                if (nice && j - i + 1 > res.size()) {
                    res = s.substr(i, j - i + 1);
                }
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
        string s = stringToString(line);
        
        string ret = Solution().longestNiceSubstring(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
