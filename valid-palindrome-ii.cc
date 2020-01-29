#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left <= right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                if (s[left + 1] == s[right] && strictValidPalindrome(s, left + 1, right)) {
                    return true;
                }
                if (s[left] == s[right - 1] && strictValidPalindrome(s, left, right - 1)) {
                    return true;
                }
                return false;
            }
        }

        return true;
    }

    bool strictValidPalindrome(string &s, int left, int right) {
        while (left <= right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
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
        string s = stringToString(line);

        bool ret = Solution().validPalindrome(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
