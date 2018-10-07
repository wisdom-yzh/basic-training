#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <cassert>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int nums[10];
        std::fill(nums, nums + 10, 0);
        for (size_t i = 0; i < secret.size(); i++) {
            char ch = secret[i];
            if (secret[i] != guess[i]) {
                nums[ch - '0']++;
            }
        }
        int bull = 0, cow = 0;
        // count bull
        for (size_t i = 0; i < secret.size(); i++) {
            if (guess[i] == secret[i]) {
                bull++;
                guess[i] = 'z';
            }
        }
        // count cow
        for (size_t i = 0; i < guess.size(); i++) {
            char ch = guess[i];
            if (ch == 'z') continue;
            if (nums[ch - '0'] > 0) {
                cow++;
                nums[ch - '0']--;
            }
        }
        return std::to_string(bull) + "A" + std::to_string(cow) + "B";
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
        string secret = stringToString(line);
        getline(cin, line);
        string guess = stringToString(line);
        
        string ret = Solution().getHint(secret, guess);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
