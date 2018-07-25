#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxSubStringLength = 0, tmpMaxSubStringLength = 0;
        unsigned long i, j;
        for (i = 0; i < s.length(); i++) {
            vector<bool> hashTable(256, false);
            tmpMaxSubStringLength = 0;
            for (j = i; j < s.length(); j++) {
                if (!hashTable[s[j]]) {
                    hashTable[s[j]] = true;
                    tmpMaxSubStringLength++;
                    if (tmpMaxSubStringLength > maxSubStringLength) {
                        maxSubStringLength = tmpMaxSubStringLength;
                    }
                } else {
                    break;
                }
            }
        }
        return maxSubStringLength;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (unsigned long i = 1; i < input.length() -1; i++) {
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

        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
