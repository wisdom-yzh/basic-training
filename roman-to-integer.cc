#include <string>
#include <iostream>
#include <tuple>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        const std::vector<std::tuple<string, int> > table{
            make_tuple("MMM", 3000),
            make_tuple("MM", 2000),
            make_tuple("M", 1000),
            make_tuple("CM", 900),
            make_tuple("DCCC", 800),
            make_tuple("DCC", 700),
            make_tuple("DC", 600),
            make_tuple("D", 500),
            make_tuple("CD", 400),
            make_tuple("CCC", 300),
            make_tuple("CC", 200),
            make_tuple("C", 100),
            make_tuple("XC", 90),
            make_tuple("LXXX", 80),
            make_tuple("LXX", 70),
            make_tuple("LX", 60),
            make_tuple("L", 50),
            make_tuple("XL", 40),
            make_tuple("XXX", 30),
            make_tuple("XX", 20),
            make_tuple("X", 10),
            make_tuple("IX", 9),
            make_tuple("VIII", 8),
            make_tuple("VII", 7),
            make_tuple("VI", 6),
            make_tuple("V", 5),
            make_tuple("IV", 4),
            make_tuple("III", 3),
            make_tuple("II", 2),
            make_tuple("I", 1),
        };
        int result = 0;
        unsigned int pos = 0;
        while (pos < s.length()) {
            for (auto j = table.begin(); j != table.end(); j++) {
                if (pos == s.find(std::get<0>(*j), pos)) {
                    result += std::get<1>(*j);
                    pos += std::get<0>(*j).length();
                    break;
                }
            }
        }
        return result;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (unsigned int i = 1; i < input.length() -1; i++) {
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
        
        int ret = Solution().romanToInt(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
