#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stk;

        for (auto &ch: s) {
            if (stk.empty() || stk.top().first != ch) {
                stk.push({ ch, 1 });
            } else {
                stk.top().second++;
                if (stk.top().second == k) {
                    stk.pop();
                }
            }
        }

        string res;
        while (!stk.empty()) {
            res += std::string(stk.top().second, stk.top().first);
            stk.pop();
        }

        std::reverse(res.begin(), res.end());
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int k = stringToInteger(line);

        string ret = Solution().removeDuplicates(s, k);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
