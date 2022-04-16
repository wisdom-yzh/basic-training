#include <string>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        uint64_t first = 0, second = 0, target = 0;
        for (auto &ch: firstWord) {
            first = first * 10 + ch - 'a';
        }
        for (auto &ch: secondWord) {
            second = second * 10 + ch - 'a';
        }
        for (auto &ch: targetWord) {
            target = target * 10 + ch - 'a';
        }
        return first + second == target;
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
        string firstWord = stringToString(line);
        getline(cin, line);
        string secondWord = stringToString(line);
        getline(cin, line);
        string targetWord = stringToString(line);
        
        bool ret = Solution().isSumEqual(firstWord, secondWord, targetWord);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
