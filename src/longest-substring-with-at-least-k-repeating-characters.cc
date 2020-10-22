#include <string>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        std::unordered_map<char, int> numberOfChar;
        for (auto &ch: s) {
            auto iter = numberOfChar.find(ch);
            if (iter == numberOfChar.end()) {
                numberOfChar.emplace(ch, 1);
            } else {
                iter->second++;
            }
        }

        size_t i = 0;
        for (i = 0; i < s.size(); i++) {
            if (numberOfChar[s[i]] < k) {
                break;
            }
        }

        if (i == s.size()) {
            return i;
        }
        return std::max(
            longestSubstring(s.substr(0, i), k),
            longestSubstring(s.substr(i + 1, s.size() - i), k)
        );
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int k = stringToInteger(line);

        int ret = Solution().longestSubstring(s, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
