#include <string>
#include <iostream>
#include <cassert>
#include <map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s1, string s2) {
        if (s1.empty() && s2.empty()) {
            return true;
        }
        if (s1.length() != s2.length()) {
            return false;
        }
        map<char, int> m1, m2;
        m1.insert(make_pair(s1[0], 0));
        m2.insert(make_pair(s2[0], 0));
        for (size_t i = 1; i < s1.length(); i++) {
            auto f1 = m1.find(s1[i]);
            auto f2 = m2.find(s2[i]);
            if (f1 == m1.end() && f2 == m2.end()) {
                m1.insert(make_pair(s1[i], m1.size()));
                m2.insert(make_pair(s2[i], m2.size()));
            } else if (f1 != m1.end() && f2 != m2.end()) {
                if (f2->second != f1->second) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (size_t i = 1; i < input.length() -1; i++) {
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
        string s = stringToString(line);
        getline(cin, line);
        string t = stringToString(line);
        bool ret = Solution().isIsomorphic(s, t);
        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
