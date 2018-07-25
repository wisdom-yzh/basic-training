#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        const unsigned int LENGTH = s.length();
        std::string result = "";

        if (numRows < 2) {
            return s;
        }
        for (int row = 0; row < numRows; row++) {
            unsigned int index = row;
            bool downUp = true;
            while ((unsigned int)index < LENGTH) {
                result.push_back(s[index]);

                if (row == 0 || row == numRows - 1) {
                    index += ((numRows - 1) << 1);
                } else {
                    if (downUp) {
                        index += ((numRows - 1 - row) << 1);
                    } else {
                        index += ((row - 0) << 1);
                    }
                    downUp = !downUp;
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int numRows = stringToInteger(line);
        
        string ret = Solution().convert(s, numRows);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
