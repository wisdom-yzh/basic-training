#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    string largestMerge(string word1, string word2) {
        string res;
        int i = 0, j = 0;
        while (i < word1.size() && j < word2.size())  {
            if (word1.substr(i) > word2.substr(j)) {
                res.push_back(word1[i++]);
            } else {
                res.push_back(word2[j++]);
            }
        }

        res += word1.substr(i);
        res += word2.substr(j);
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
        string word1 = stringToString(line);
        getline(cin, line);
        string word2 = stringToString(line);
        
        string ret = Solution().largestMerge(word1, word2);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
