#include <string>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string customSortString(string S, string T) {
        char alphabet[26] {};
        for (int i = 0; i < S.size(); i++) {
            alphabet[S[i] - 'a'] = i;
        }

        std::sort(T.begin(), T.end(), [&alphabet](char a, char b) -> bool {
            return alphabet[a - 'a'] < alphabet[b - 'a'];
        });

        return T;
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
            string S = stringToString(line);
            getline(cin, line);
            string T = stringToString(line);

            string ret = Solution().customSortString(S, T);

            string out = (ret);
            cout << out << endl;
        }
    return 0;
}
