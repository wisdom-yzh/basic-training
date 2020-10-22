#include <string>
#include <iostream>
#include <sstream>
#include <array>
#include <cassert>
using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        bool duplicate = false;
        std::array<int, 26> alphabetMap { 0 };

        if (A.size() != B.size()) {
            return false;
        }

        string A0, B0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != B[i]) {
                A0.push_back(A[i]);
                B0.push_back(B[i]);
            } else if (!duplicate) {
                alphabetMap[A[i] - 'a']++;
                if (alphabetMap[A[i] - 'a'] > 1) {
                    duplicate = true;
                }
            }
        }

        if (A0.empty()) {
            return duplicate;
        }

        if (A0.size() == 2) {
            return A0[0] == B0[1] && A0[1] == B0[0];
        }

        return false;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string A = stringToString(line);
        getline(cin, line);
        string B = stringToString(line);

        bool ret = Solution().buddyStrings(A, B);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
