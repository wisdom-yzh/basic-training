#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.length();
        int count[26];
        std::fill(count, count + 26, 0);

        int start = 0, maxCount = 0, maxLength = 0;
        for (int end = 0; end < len; end++) {
            maxCount = std::max(maxCount, ++count[s[end] - 'A']);
            while (end - start + 1 > k + maxCount) {
                count[s[start] - 'A']--;
                start++;
            }
            maxLength = std::max(maxLength, end - start + 1);
        }
        return maxLength;
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
        
        int ret = Solution().characterReplacement(s, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
