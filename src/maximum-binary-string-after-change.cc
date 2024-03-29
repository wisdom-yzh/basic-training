#include <string>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string maximumBinaryString(string binary) {
        int zeroCount = 0, leftZeroIndex = -1;

        for (int i = 0; i < binary.size(); i++) {
            if (binary[i] == '0') {
                zeroCount++;
                if (leftZeroIndex == -1) {
                    leftZeroIndex = i;
                }
            }
        }

        if (zeroCount == 0 || zeroCount == 1) {
            return binary;
        }

        std::fill(binary.begin(), binary.end(), '1');
        binary[leftZeroIndex + zeroCount - 1] = '0';
        return binary;
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
        string binary = stringToString(line);

        string ret = Solution().maximumBinaryString(binary);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
