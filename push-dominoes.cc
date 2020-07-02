#include <string>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int prevIndex = -1, status = 0;

        for (int i = 0; i < dominoes.size(); i++) {
            if (dominoes[i] == 'R') {
                if (status == 1) {
                    for (int j = prevIndex + 1; j < i; j++) {
                        dominoes[j] = 'R';
                    }
                }
                prevIndex = i;
                status = 1;
            } else if (dominoes[i] == 'L') {
                if (status == 0) {
                    for (int j = prevIndex + 1; j < i; j++) {
                        dominoes[j] = 'L';
                    }
                } else {
                    int left = prevIndex + 1, right = i - 1;
                    while (left < right) {
                        dominoes[left++] = 'R';
                        dominoes[right--] = 'L';
                    }
                }
                prevIndex = i;
                status = 0;
            }
        }

        if (status == 1) {
            for (int j = prevIndex + 1; j < dominoes.size(); j++) {
                dominoes[j] = 'R';
            }
        }
        return dominoes;
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
        string dominoes = stringToString(line);

        string ret = Solution().pushDominoes(dominoes);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
