#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        const unsigned int LENGTH = s.length();
        bool L[LENGTH][LENGTH];
        unsigned int maxPalindromeLength = 1, begin = 0;

        memset(L, 0, sizeof(bool) * LENGTH * LENGTH);

        for (unsigned int i = 0; i < LENGTH; i++) {
            L[i][i] = true;
        }

        for (unsigned int i = 0; i < LENGTH - 1; i++) {
            if (s[i] == s[i + 1]) {
                L[i][i + 1]  = true;
                maxPalindromeLength = 2;
                begin = i;
            }
        }

        for (unsigned int size = 2; size <= LENGTH; size++) {
            for (unsigned int i = 0; i + size <= LENGTH; i++) {
                unsigned int j = i + size - 1;
                if (L[i + 1][j - 1] && s[i] == s[j]) {
                    L[i][j] = true;
                    begin = i;
                    maxPalindromeLength = size;
                }
            }
        }
        

        return s.substr(begin, maxPalindromeLength);
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (unsigned long i = 1; i < input.length() -1; i++) {
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
        
        string ret = Solution().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
