#include <string>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    const static int MOD = 1e9 + 7;

    int numWays(string s) {
        int count = 0;
        for (auto &ch: s) {
            if (ch == '1') {
                count++;
            }
        }

        if (count % 3 != 0) {
            return 0;
        }

        if (count == 0) {
            return (static_cast<uint64_t>(s.size() - 1) * (s.length() - 2) / 2) % MOD;
        }

        count /= 3;

        uint64_t c = 0, d1 = 0, d2 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                c++;
            }
            if (c == count) {
                d1++;
            }
            if (c == 2 * count) {
                d2++;
            }
        }

        return (d1 * d2) % MOD;
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

        int ret = Solution().numWays(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
