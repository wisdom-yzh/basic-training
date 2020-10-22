#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        shifts[shifts.size() - 1] = shifts[shifts.size() - 1] % 26;
        S[S.size() - 1] = shift(S[S.size() - 1], shifts[shifts.size() - 1]);

        for (int i = shifts.size() - 2; i >= 0; i--) {
            shifts[i] = ((shifts[i + 1] % 26) + shifts[i]) % 26;
            S[i] = shift(S[i], shifts[i]);
        }

        return S;
    }

    char shift(char origin, int size) {
        int result = (int)origin + size;
        if (result > (int)'z') {
            result -= 26;
        }
        return (char)result;
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

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                return !isspace(ch);
                }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string S = stringToString(line);
        getline(cin, line);
        vector<int> shifts = stringToIntegerVector(line);

        string ret = Solution().shiftingLetters(S, shifts);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
