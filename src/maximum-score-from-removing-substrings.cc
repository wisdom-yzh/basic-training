#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res = 0;
        if (x >= y) {
            res += gain(s, 'a', 'b', x);
            res += gain(s, 'b', 'a', y);
        } else {
            res += gain(s, 'b', 'a', y);
            res += gain(s, 'a', 'b', x);
        }
        return res;
    }

    int gain(string &s, char first, char second, int value) {
        int score = 0;
        vector<char> stk;
        for (auto &ch: s) {
            if (!stk.empty() && stk.back() == first && ch == second) {
                stk.pop_back();
                score += value;
            } else {
                stk.push_back(ch);
            }
        }
        s.assign(stk.begin(), stk.end());
        return score;
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
        int x = stringToInteger(line);
        getline(cin, line);
        int y = stringToInteger(line);

        int ret = Solution().maximumGain(s, x, y);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
