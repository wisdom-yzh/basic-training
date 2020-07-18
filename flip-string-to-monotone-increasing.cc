#include <string>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string S) {
        vector<int> zero(S.size(), 0), one(S.size(), 0);
        zero[0] = S[0] == '0' ? 0 : 1;
        one[0] = 1 - zero[0];

        for (int i = 1; i < S.size(); i++) {
            bool isZero = S[i] == '0';
            zero[i] = zero[i - 1] + (isZero ? 0 : 1);
            one[i] = std::min(zero[i - 1], one[i - 1]) + (isZero ? 1 : 0);
        }

        return std::min(zero[S.size() - 1], one[S.size() - 1]);
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

        int ret = Solution().minFlipsMonoIncr(S);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
