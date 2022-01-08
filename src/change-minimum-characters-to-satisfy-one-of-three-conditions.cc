#include <string>
#include <iostream>
#include <array>
#include <cassert>
#include <limits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCharacters(string a, string b) {
        std::array<int, 26> va, vb;
        va.fill(0), vb.fill(0);

        for (const auto &ch: a) {
            va[ch - 'a']++;
        }
        for (const auto &ch: b) {
            vb[ch - 'a']++;
        }

        int res = std::numeric_limits<int>::max();
        int asum = 0, bsum = 0;
        for (int i = 0; i < 25; i++) {
            asum += va[i];
            bsum += vb[i];
            res = std::min(
                res,
                std::min(
                    (int)a.size() - va[i] + (int)b.size() - vb[i],
                    std::min(
                        (int)a.size() - asum + bsum,
                        (int)b.size() - bsum + asum
                    )
                )
            );
        }
        res = std::min(res, (int)a.size() - va[25] + (int)b.size() - vb[25]);
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
        string a = stringToString(line);
        getline(cin, line);
        string b = stringToString(line);

        int ret = Solution().minCharacters(a, b);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
