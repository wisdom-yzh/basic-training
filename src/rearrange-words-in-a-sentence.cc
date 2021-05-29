#include <string>
#include <iostream>
#include <sstream>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string arrangeWords(string text) {
        text[0] = std::tolower(text[0]);
        vector<string> pieces;
        string word;
        istringstream iss;
        iss.str(text);
        while (getline(iss, word, ' ')) {
            pieces.push_back(word);
        }

        std::stable_sort(pieces.begin(), pieces.end(),
            [](const string &a, const string &b) {
                return a.size() < b.size();
            });

        ostringstream oss;
        for (auto iter = pieces.begin(); iter != pieces.end(); iter++) {
            oss << *iter;
            if (iter != pieces.end() - 1) {
               oss << " ";
            }
        }
        auto s = oss.str();
        s[0] = std::toupper(s[0]);
        return s;
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

        string ret = Solution().arrangeWords(text);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
