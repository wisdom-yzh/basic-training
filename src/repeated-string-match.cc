#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        if (B.size() == 0 || A.find(B, 0) != std::string::npos) {
            return 1;
        }
        if (A.size() == 0) {
            return -1;
        }

        std::string repeatedA = "";
        int estimate = std::ceil(static_cast<double>(B.size()) / A.size());
        for (int i = 0; i < estimate; i++) {
            repeatedA += A;
        }
        if (repeatedA.find(B, 0) != std::string::npos) {
            return estimate;
        }
        repeatedA  += A;
        if (repeatedA.find(B, 0) != std::string::npos) {
            return estimate + 1;
        }
        return -1;
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
        string A = stringToString(line);
        getline(cin, line);
        string B = stringToString(line);

        int ret = Solution().repeatedStringMatch(A, B);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
