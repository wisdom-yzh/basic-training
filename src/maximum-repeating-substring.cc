#include <vector>
#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int res = 0, lastPos = -1;

        while (true) {
            int pos = sequence.find(word, lastPos + 1);
            if (pos == sequence.npos) {
                break;
            } else {
                lastPos = pos;
                int repeatPos = pos + word.size();
                int repeat = 1;
                while (repeatPos != sequence.size() && sequence.substr(repeatPos, word.size()) == word) {
                    repeat++;
                    repeatPos += word.size();
                }
                res = std::max(res, repeat);
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
        string sequence = stringToString(line);
        getline(cin, line);
        string word = stringToString(line);

        int ret = Solution().maxRepeating(sequence, word);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
