#include <string>
#include <iostream>
#include <sstream>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int maxValue = 0, value = 0;
        int p = 0, q = k;

        for (int i = p; i < q; i++) {
            if (isVowel(s[i])) {
                value++;
            }
        }
        maxValue = value;

        while (q < s.size()) {
            if (isVowel(s[q])) {
                value++;
            }
            if (isVowel(s[p])) {
                value--;
            }
            maxValue = std::max(maxValue, value);
            q++;
            p++;
        }

        return maxValue;
    }

    bool isVowel(char &ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int k = stringToInteger(line);

        int ret = Solution().maxVowels(s, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
