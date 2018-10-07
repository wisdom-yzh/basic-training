#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words;
        splitWords(str, words);
        map<string, char> m;
        set<char> s;
        if (pattern.size() != words.size()) {
            return false;
        }
        for (size_t i = 0; i < words.size(); i++) {
            auto p = m.find(words[i]);
            if (p == m.end()) {
                if (s.find(pattern[i]) != s.end()) {
                    return false;
                }
                s.emplace(pattern[i]);
                m.emplace(words[i], pattern[i]);
            } else {
                if (p->second != pattern[i]) {
                    return false;
                }
            }
        }
        return true;
    }

    void splitWords(const string &str, vector<string> &words) {
        istringstream iss(str);
        string s;
        while (getline(iss, s, ' ')) {
            words.push_back(s);
        }
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
        string pattern = stringToString(line);
        getline(cin, line);
        string str = stringToString(line);
        
        bool ret = Solution().wordPattern(pattern, str);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
