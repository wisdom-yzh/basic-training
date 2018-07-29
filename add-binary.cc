#include <string>
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result(std::max(a.length(), b.length()), '0');

        for (int i = a.length() - 1, j = b.length() - 1, k = result.length() - 1;
            i >= 0 || j >= 0;
            i--, j--, k--) {
            char ch1 = i < 0 ? '0' : a[i];
            char ch2 = j < 0 ? '0' : b[j];
            char ch = ch1 - '0' + ch2 - '0' + result[k] - '0';
            if (ch >= 2) {
                result[k] = ch == 2 ? '0' : '1';
                if (k == 0) {
                    result.insert(result.begin(), '1');
                } else {
                    result[k - 1] = '1';
                }
            } else {
                result[k] = ch + '0';
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
        string a = stringToString(line);
        getline(cin, line);
        string b = stringToString(line);
        
        string ret = Solution().addBinary(a, b);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
