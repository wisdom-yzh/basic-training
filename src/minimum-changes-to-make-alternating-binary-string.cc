#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>
#include <string>
#include <type_traits>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int zeroFront = 0, oneFront = 0;
        char zero = '0', one = '1';

        for (const auto &ch: s) {
            if (zero != ch) {
                zeroFront++;
            } else {
                oneFront++;
            }
            std::swap(zero, one);
        }

        return std::min(zeroFront, oneFront);
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

        int ret = Solution().minOperations(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
