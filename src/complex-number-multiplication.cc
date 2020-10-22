#include <string>
#include <iostream>
#include <sstream>
#include <cassert>
#include <algorithm>
#include <regex>
using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        return complex2str(multiple(str2complex(a), str2complex(b)));
    }

    std::pair<int, int> str2complex(string &num) {
        std::regex re("([\\-0-9]+)\\+([\\-0-9]+)i");
        std::smatch match;
        auto pair = std::make_pair(0, 0);

        if (std::regex_match(num, match, re)) {
            if (match.size() == 3) {
                pair.first = std::stol(match[1].str());
                pair.second = std::stol(match[2].str());
            }
        }

        return pair;
    }

    std::string complex2str(pair<int, int> &&num) {
        std::ostringstream oss;
        oss << num.first << '+' << num.second << 'i';
        return oss.str();
    }

    std::pair<int, int> multiple(std::pair<int, int> &&num1, std::pair<int, int> &&num2) {
        return std::make_pair(
            num1.first * num2.first - num1.second * num2.second,
            num1.second * num2.first + num1.first * num2.second
        );
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
        string a = stringToString(line);
        getline(cin, line);
        string b = stringToString(line);

        string ret = Solution().complexNumberMultiply(a, b);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
