#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        vector<string> words(10);

        stringstream ss;
        ss.str(s);
        int len = 0;
        string word;
        while (getline(ss, word, ' ')) {
            words[word.back() - '1'] = word.substr(0, word.size() - 1);
            len++;
        }
        string res;
        for (auto &w: words) {
            res.append(w);
            if (len-- == 0) {
                break;
            }
            res.append(" ");
        }
        return res.substr(0, res.size() - 1);
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
        
        string ret = Solution().sortSentence(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
