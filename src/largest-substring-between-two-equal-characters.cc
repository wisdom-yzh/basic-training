#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <array>
using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        std::array<int, 26> arr;
        std::fill(arr.begin(), arr.end(), -1);

        int res = -1;
        for (int i = 0; i < s.size(); i++) {
            auto ch = s[i];
            if (arr[ch - 'a'] == -1) {
                arr[ch - 'a'] = i;
            } else {
                res = std::max(res, i - arr[ch - 'a'] - 1);
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

        int ret = Solution().maxLengthBetweenEqualCharacters(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
