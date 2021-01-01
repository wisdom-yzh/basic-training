#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> dict;
        unordered_map<char, int> chars;
        int p = 0, q = 0;

        chars[s[0]] = 1;
        while (q < s.size()) {
            int len = q - p + 1;
            if (len >= minSize && len <= maxSize && chars.size() <= maxLetters) {
                dict[s.substr(p, q - p + 1)]++;
                auto iter = chars.find(s[p]);
                if (iter->second == 1) {
                    chars.erase(iter);
                } else {
                    iter->second--;
                }
                p++;
            }

            if (len > maxSize || chars.size() > maxLetters) {
                auto iter = chars.find(s[p]);
                if (iter->second == 1) {
                    chars.erase(iter);
                } else {
                    iter->second--;
                }
                p++;
                continue;
            }

            q++;
            if (q != s.size()) {
                chars[s[q]]++;
            }
        }

        int maxCount = 0;
        for (auto &item: dict) {
            maxCount = std::max(maxCount, item.second);
        }
        return maxCount;
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
        int maxLetters = stringToInteger(line);
        getline(cin, line);
        int minSize = stringToInteger(line);
        getline(cin, line);
        int maxSize = stringToInteger(line);

        int ret = Solution().maxFreq(s, maxLetters, minSize, maxSize);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
