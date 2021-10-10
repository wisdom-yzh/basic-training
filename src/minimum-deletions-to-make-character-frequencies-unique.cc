#include <string>
#include <array>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        std::array<int, 26> freq;
        std::fill(freq.begin(), freq.end(), 0);

        for (const auto &ch: s) {
            freq[ch - 'a']++;
        }

        std::sort(freq.begin(), freq.end(), std::greater<int>());

        int res = 0;
        for (int i = 1; i < freq.size(); i++) {
            while (freq[i] != 0 && freq[i] >= freq[i - 1]) {
                freq[i]--;
                res++;
            }
        }

        return res;
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
        string s = stringToString(line);

        int ret = Solution().minDeletions(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
