#include <string>
#include <iostream>
#include <sstream>
#include <cassert>
#include <array>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        std::array<int, 26> count;
        count.fill(0);

        int series = 0;
        char prev;
        for (auto &ch: p) {
            if (!series || ch == prev + 1 ||
                (ch == 'a' && prev == 'z')) {
                series++;
            } else {
                series = 1;
            }

            count[ch - 'a'] = std::max(count[ch - 'a'], series);
            prev = ch;
        }

        return std::accumulate(count.begin(), count.end(), 0);
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
        string p = stringToString(line);

        int ret = Solution().findSubstringInWraproundString(p);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
