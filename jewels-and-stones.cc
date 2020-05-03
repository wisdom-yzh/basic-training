#include <string>
#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count[256];
        std::fill(count, count + 256, 0);
        for (const auto &ch: S) {
            count[static_cast<int>(ch)]++;
        }

        int result = 0;
        for (const auto &ch: J) {
            result += count[static_cast<int>(ch)];
        }
        return result;
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
        string J = stringToString(line);
        getline(cin, line);
        string S = stringToString(line);

        int ret = Solution().numJewelsInStones(J, S);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
