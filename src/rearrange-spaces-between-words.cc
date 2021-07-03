#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    string reorderSpaces(string text) {
        int spaceNum = 0, wordNum = 0;
        vector<string> words;
        string result, tmp;
        int status = 0;

        for (auto &ch: text) {
            if (ch == ' ') {
                if (status == 1) {
                    words.push_back(tmp);
                    tmp = "";
                    status = 0;
                }
                spaceNum++;
            } else {
                status = 1;
                tmp.push_back(ch);
            }
        }

        if (status == 1) {
            words.push_back(tmp);
        }

        if (words.size() == 1) {
            return words[0] + std::string(spaceNum, ' ');
        }

        int spaceMiddle = spaceNum / (words.size() - 1);
        int spaceEnd = spaceNum % (words.size() - 1);
        for (auto iter = words.begin(); iter != prev(words.end()); iter++) {
            result += *iter;
            result += std::string(spaceMiddle, ' ');
        }
        result += words.back();
        result += std::string(spaceEnd, ' ');
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
        string text = stringToString(line);

        string ret = Solution().reorderSpaces(text);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
