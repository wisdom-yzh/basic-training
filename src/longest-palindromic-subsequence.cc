#include <string>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.empty()) {
            return 0;
        }
        int size = s.size();
        vector<vector<int>> vec(size, vector<int>(size, 0));
        for (int i = 0; i < size; i++) {
            vec[i][i] = 1;
        }
        return this->recursionDP(s, vec, 0, size - 1);
    }

    int recursionDP(string &s, vector<vector<int>> &vec, int start, int end) {
        if (vec[start][end] != 0) {
            return vec[start][end];
        }

        int result = 0;

        if (s[start] == s[end]) {
            if (end == start + 1) {
                result = 2;
            } else {
                result = recursionDP(s, vec, start + 1, end - 1) + 2;
            }
        } else {
            result = std::max(
                recursionDP(s, vec, start + 1, end),
                recursionDP(s, vec, start, end - 1)
            );
        }

        vec[start][end] = result;
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
        string s = stringToString(line);

        int ret = Solution().longestPalindromeSubseq(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
