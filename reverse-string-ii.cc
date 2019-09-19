#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        ostringstream oss;
        int step = 2 * k;
        for (int i = 0; i < s.size(); i += step) {
            int restLength = s.size() - i;
            if (restLength >= step) {
                string str = s.substr(i, k);
                std::reverse(str.begin(), str.end());
                oss << str;
                oss << s.substr(i + k, k);
            } else if (restLength >= k) {
                string str = s.substr(i, k);
                std::reverse(str.begin(), str.end());
                oss << str;
                oss << s.substr(i + k, restLength - k);
            } else {
                string str = s.substr(i, restLength);
                std::reverse(str.begin(), str.end());
                oss << str;
            }
        }
        return oss.str();
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int k = stringToInteger(line);

        string ret = Solution().reverseStr(s, k);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
