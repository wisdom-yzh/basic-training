#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.empty()) {
            return false;
        }

        if (isCapital(word[0])) {
            int prev = -1, curr = -1;

            for (int i = 1; i < word.size(); i++) {
                if (isCapital(word[i])) {
                    curr = 0;
                } else {
                    curr = 1;
                }

                if (prev != -1 && prev != curr) {
                    return false;
                }

                prev = curr;
            }

            return true;
        }

        for (const auto &ch: word) {
            if (isCapital(ch)) {
                return false;
            }
        }

        return true;
    }

    bool isCapital(char ch) {
        return ch >= 'A' && ch <= 'Z';
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string word = stringToString(line);

        bool ret = Solution().detectCapitalUse(word);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
