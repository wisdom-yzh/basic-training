#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cassert>
using namespace std;

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.size() != t.size()) {
            return false;
        }

        vector<int> count(26, k / 26 + 1);
        k %= 26;

        for (int i = 0; i < s.size(); i++) {
            int delta = (t[i] + 26 - s[i]) % 26;
            if (!delta) {
                continue;
            }
            count[delta]--;
            if (count[delta] < 0 || delta > k && count[delta] == 0) {
                return false;
            }
        }

        return true;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string t = stringToString(line);
        getline(cin, line);
        int k = stringToInteger(line);

        bool ret = Solution().canConvertString(s, t, k);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
