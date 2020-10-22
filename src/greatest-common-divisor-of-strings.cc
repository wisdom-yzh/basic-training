#include <string>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.empty() || str2.empty()) {
            return "";
        }

        int maxValue = std::min(str1.size(), str2.size()) - 1;
        int p = 0;

        for (int i = 0; i <= maxValue; i++) {
            if (str1[i] != str2[i]) {
                break;
            }
            if (str1.size() % (i + 1) != 0 || str2.size() % (i + 1) != 0) {
                continue;
            }

            bool legal = true;
            auto sub = str1.substr(0, i + 1);
            for (int j = i + 1; j < str1.size() && legal; j += (i + 1)) {
                if (sub != str1.substr(j, i + 1)) {
                    legal = false;
                }
            }
            if (!legal) {
                continue;
            }
            for (int j = i + 1; j < str2.size() && legal; j += (i + 1)) {
                if (sub != str2.substr(j, i + 1)) {
                    legal = false;
                }
            }
            if (!legal) {
                continue;
            }
            p = i + 1;
        }

        return str1.substr(0, p);
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
        string str1 = stringToString(line);
        getline(cin, line);
        string str2 = stringToString(line);

        string ret = Solution().gcdOfStrings(str1, str2);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
