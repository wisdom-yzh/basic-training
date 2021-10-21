#include <string>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int B[s.size()], A[s.size()];
        std::fill(B, B + s.size(), 0);
        std::fill(A, A + s.size(), 0);

        B[0] = s[0] == 'b' ? 1 : 0;
        A[s.size() - 1] = s[s.size() - 1] == 'a' ? 1 : 0;

        for (int i = 1; i < s.size(); i++) {
            B[i] = B[i - 1] + (s[i] == 'b' ? 1 : 0);
            A[s.size() - 1 - i] = A[s.size() - i] + (s[s.size() - 1 - i] == 'a' ? 1 : 0);
        }

        int res = s.size();
        for (int i = 0; i < s.size(); i++) {
            int value = (i == 0 ? 0 : B[i - 1]) + (i == s.size() - 1 ? 0 : A[i + 1]);
            res = std::min(res, value);
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

        int ret = Solution().minimumDeletions(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
