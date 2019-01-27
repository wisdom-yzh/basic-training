#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        int carry = 0;
        int p1 = num1.size() - 1, p2 = num2.size() - 1;

        for (;;) {
            int num = 0;
            if (p1 >= 0 && p2 >= 0) {
                num = num1[p1] - '0' + num2[p2] - '0' + carry;
                p1--;
                p2--;
            } else if (p1 < 0 && p2 >= 0) {
                num = num2[p2] - '0' + carry;
                p2--;
            } else if (p2 < 0 && p1 >= 0) {
                num = num1[p1] - '0' + carry;
                p1--;
            } else {
                break;
            }

            if (num >= 10) {
                num -= 10;
                carry = 1;
            } else {
                carry = 0;
            }

            result.push_back(num + '0');
        }

        if (carry == 1) {
            result.push_back('1');
        }

        std::reverse(result.begin(), result.end());
        return result;
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
        string num1 = stringToString(line);
        getline(cin, line);
        string num2 = stringToString(line);
        
        string ret = Solution().addStrings(num1, num2);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
