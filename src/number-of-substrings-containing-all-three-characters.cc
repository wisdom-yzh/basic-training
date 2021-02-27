#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        vector<int> record(3, -1);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') {
                res += std::min(record[1], record[2]) + 1;
            } else if (s[i] == 'b') {
                res += std::min(record[0], record[2]) + 1;
            } else {
                res += std::min(record[0], record[1]) + 1;
            }

            record[s[i] - 'a'] = i;
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

        int ret = Solution().numberOfSubstrings(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
