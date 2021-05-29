#include <string>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) {
            return false;
        }
        uint32_t mask = (1 << k) - 1;
        vector<bool> arr(mask + 1, false);

        uint32_t x = 0;
        for (int i = 0; i < k; i++) {
            x <<= 1;
            if (s[i] == '1') {
                x += 1;
            }
        }
        arr[x] = true;

        for (int i = k; i < s.size(); i++) {
            x <<= 1;
            if (s[i] == '1') {
                x += 1;
            }
            x &= mask;
            arr[x] = true;
        }

        for (const auto &item: arr) {
            if (!item) {
                return false;
            }
        }
        return true;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int k = stringToInteger(line);

        bool ret = Solution().hasAllCodes(s, k);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
