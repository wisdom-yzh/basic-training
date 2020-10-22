#include <iostream>
#include <string>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        vector<vector<bool>> sub(s.size(), vector<bool>(s.size(), false));

        for (int len = 1; len <= s.size(); len++) {
            for (int i = 0; i <= s.size() - len; i++) {
                int j = i + len - 1;
                if (j == i) {
                    sub[i][j] = true;
                    count++;
                } else if (j == i + 1 && s[i] == s[j]) {
                    sub[i][j] = true;
                    count++;
                } else if (s[i] == s[j] && sub[i + 1][j - 1]) {
                    sub[i][j] = true;
                    count++;
                }
            }
        }

        return count;
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

        int ret = Solution().countSubstrings(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
