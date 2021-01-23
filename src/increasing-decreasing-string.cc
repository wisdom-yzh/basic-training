#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    string sortString(string s) {
        std::sort(s.begin(), s.end());
        std::string res;

        while (!s.empty()) {
            for (auto iter = s.begin(); ; ) {
                res.push_back(*iter);
                iter = s.erase(iter);
                while (iter != s.end() && *iter == res.back()) {
                    iter++;
                }
                if (iter == s.end()) {
                    break;
                }
            }
            if (s.empty()) {
                break;
            }
            for (auto iter = s.end() - 1; ; ) {
                res.push_back(*iter);
                iter = s.erase(iter);
                if (s.empty()) {
                    break;
                }
                iter--;
                while (iter != s.begin() && *iter == res.back()) {
                    iter--;
                }
                if (iter == s.begin()) {
                    break;
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

        string ret = Solution().sortString(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
