#include <vector>
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    int minFlips(string target) {
        if (target.empty()) {
            return 0;
        }

        int res = 0;

        if (target[0] == '1') {
            res++;
        }

        for (int i = 0; i < target.size() - 1; i++) {
            if (target[i] != target[i + 1]) {
                res++;
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
        string target = stringToString(line);

        int ret = Solution().minFlips(target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
