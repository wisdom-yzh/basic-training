#include <string>
#include <iostream>
#include <sstream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        std::stringstream oss;
        std::stringstream iss;
        iss.str(s);
        for (int i = 0; i < k; i++) {
            std::string slice;
            getline(iss, slice, ' ');
            oss << slice << ' ';
        }
        string out = oss.str();
        return out.substr(0, out.size() - 1);
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
        
        string ret = Solution().truncateSentence(s, k);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
