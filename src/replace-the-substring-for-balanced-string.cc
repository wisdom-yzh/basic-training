#include <string>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <array>
using namespace std;

class Solution {
public:
    int balancedString(string s) {
        std::array<int, 26> count;
        count.fill(0);

        for (auto &ch: s) {
            count[ch - 'A']++;
        }

        int len = s.length();
        int averageLen = len / 4;
        int left = 0, right = 0;
        int res = len;

        while (right < len) {
            count[s[right] - 'A']--;

            while (left < len &&
                count['Q' - 'A'] <= averageLen &&
                count['W' - 'A'] <= averageLen &&
                count['E' - 'A'] <= averageLen &&
                count['R' - 'A'] <= averageLen
            ) {
                res = std::min(right - left + 1, res);
                count[s[left] - 'A']++;
                left++;
            }
            right++;
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

        int ret = Solution().balancedString(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
