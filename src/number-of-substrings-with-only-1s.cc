#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class Solution {
public:
    int numSub(string s) {
        uint64_t res = 0;
        uint64_t n = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                if (n == 0) {
                    continue;
                }

                uint64_t x = (n * (n + 1)) / 2;
                res = (res + x) % static_cast<uint64_t>(1e9 + 7);
                n = 0;
            } else {
                n++;
            }
        }

        if (n != 0) {
            uint64_t x = (n * (n + 1)) / 2;
            res = (res + x) % static_cast<uint64_t>(1e9 + 7);
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

        int ret = Solution().numSub(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
