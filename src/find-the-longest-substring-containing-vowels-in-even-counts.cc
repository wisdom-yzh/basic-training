#include <algorithm>
#include <string>
#include <iostream>
#include <cassert>
#include <array>
using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        std::array<int, 32> pos;
        std::fill(pos.begin(), pos.end(), s.size());
        pos[0] = -1;

        int res = 0;
        int val = 0;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            switch (ch) {
                case 'a': val ^= 0b10000; break;
                case 'e': val ^= 0b01000; break;
                case 'i': val ^= 0b00100; break;
                case 'o': val ^= 0b00010; break;
                case 'u': val ^= 0b00001; break;
            }

            if (pos[val] == s.size()) {
                pos[val] = i;
            } else {
                res = std::max(res, i - pos[val]);
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

        int ret = Solution().findTheLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
