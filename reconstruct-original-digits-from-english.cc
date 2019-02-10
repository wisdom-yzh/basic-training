#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
using namespace std;

class Solution {
public:
    string originalDigits(string s) {
       int count[10];
       std::fill(count, count + 10, 0);
       for (char &ch: s) {
           if (ch == 'z') count[0]++;
           if (ch == 'w') count[2]++;
           if (ch == 'x') count[6]++;
           if (ch == 's') count[7]++;
           if (ch == 'g') count[8]++;
           if (ch == 'u') count[4]++;
           if (ch == 'f') count[5]++;
           if (ch == 'h') count[3]++;
           if (ch == 'i') count[9]++;
           if (ch == 'o') count[1]++;
       }
       count[7] -= count[6];
       count[5] -= count[4];
       count[3] -= count[8];
       count[9] = count[9] - count[8] - count[5] - count[6];
       count[1] = count[1] - count[0] - count[2] - count[4];

       ostringstream ss;
       for (int i = 0; i < 10; i++) {
           for (int j = 0; j < count[i]; j++) {
                ss << i;
           }
       }
       return ss.str();
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
        
        string ret = Solution().originalDigits(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
