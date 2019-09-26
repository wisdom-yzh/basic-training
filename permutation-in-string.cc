#include <string>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) {
            return false;
        }

        map<char, int> s;
        for (const auto &ch: s1) {
            auto iter = s.find(ch);
            if (iter == s.end()) {
                s.emplace(std::make_pair(ch, 1));
            } else {
                iter->second++;
            }
        }

        for (int i = 0; i < s2.size() - s1.size() + 1; i++) {
            if (s.find(s2[i]) == s.end()) {
                continue;
            }

            map<char, int> characters(s);
            characters[s2[i]]--;
            bool found = true;

            for (int j = 1; j < s1.size() && found; j++) {
                auto iter = characters.find(s2[i + j]);
                if (iter == characters.end()) {
                    i += j;
                    found = false;
                } else if (iter->second == 0) {
                    found = false;
                } else {
                    iter->second--;
                }
            }

            if (found) return true;
        }

        return false;
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
        string s1 = stringToString(line);
        getline(cin, line);
        string s2 = stringToString(line);

        bool ret = Solution().checkInclusion(s1, s2);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
