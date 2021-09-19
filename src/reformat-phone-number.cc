#include <string>
#include <iostream>
#include <cassert>
#include <sstream>
using namespace std;

class Solution {
public:
    string reformatNumber(string number) {
        string res;
        int x = 0;

        for (auto &ch: number) {
            if (ch == '-' || ch == ' ') {
                continue;
            }

            res.push_back(ch);

            if (x == 2) {
                res.push_back('-');
                x = 0;
            } else {
                x++;
            }
        }

        if (res.back() == '-') {
            res.pop_back();
        }
        if (x == 1) {
            std::swap(res[res.size() - 2], res[res.size() - 3]);
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
        string number = stringToString(line);

        string ret = Solution().reformatNumber(number);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
