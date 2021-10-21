#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char, int> m1, m2;
        for (auto &ch: word1) {
            m1[ch]++;
        }
        for (auto &ch: word2) {
            m2[ch]++;
        }

        vector<char> ch1, ch2;
        vector<int> count1, count2;
        for (auto &[ch, count]: m1) {
            ch1.push_back(ch);
            count1.push_back(count);
        }
        sort(count1.begin(), count1.end());

        for (auto &[ch, count]: m2) {
            ch2.push_back(ch);
            count2.push_back(count);
        }
        sort(count2.begin(), count2.end());

        return ch1 == ch2 && count1 == count2;
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
        string word1 = stringToString(line);
        getline(cin, line);
        string word2 = stringToString(line);

        bool ret = Solution().closeStrings(word1, word2);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
