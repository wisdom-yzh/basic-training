#include <string>
#include <iostream>
#include <sstream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream iss;
        iss.str(sentence);

        string str;
        int res = 1;

        while (getline(iss, str, ' ')) {
            if (str.substr(0, searchWord.size()) == searchWord) {
                return res;
            }
            res++;
        }

        return -1;
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
        string sentence = stringToString(line);
        getline(cin, line);
        string searchWord = stringToString(line);

        int ret = Solution().isPrefixOfWord(sentence, searchWord);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
