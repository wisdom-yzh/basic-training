#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
using namespace std;

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int c = 0, r = 0, o = 0, a = 0, k = 0, res = 0;

        for (auto &ch: croakOfFrogs) {
            if (ch == 'c') {
                c++;
            } else if (ch == 'r') {
                r++;
            } else if (ch == 'o') {
                o++;
            } else if (ch == 'a') {
                a++;
            } else {
                k++;
            }

            if (k > a || a > o || o > r || r > c) {
                return -1;
            }
            res = std::max(res, c - k);
        }

        if (k > a || a > o || o > r || r > c) {
            return -1;
        }
        return c == k ? res : -1;
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
        string croakOfFrogs = stringToString(line);

        int ret = Solution().minNumberOfFrogs(croakOfFrogs);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
