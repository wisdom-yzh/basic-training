#include <string>
#include <iostream>
#include <cassert>
#include <set>
using namespace std;

class Solution {
public:
    int numDifferentIntegers(string word) {
        set<string> s;

        string sNum = "";
        for (auto &ch: word) {
            if (ch >= '0' && ch <= '9') {
                sNum.push_back(ch);
                continue;
            }

            if (sNum.size() > 0) {
                while (sNum.size() > 0 && sNum.front() == '0') {
                    sNum.erase(0, 1);
                }
                if (sNum.size() > 0) {
                    s.emplace(sNum);
                    sNum.clear();
                } else {
                    s.emplace("0");
                }
            }
        }

        
        if (sNum.size() > 0) {
            while (sNum.size() > 0 && sNum.front() == '0') {
                sNum.erase(0, 1);
            }
            if (sNum.size() > 0) {
                s.emplace(sNum);
                sNum.clear();
            } else {
                s.emplace("0");
            }
        }

        return s.size();
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
        string word = stringToString(line);
        
        int ret = Solution().numDifferentIntegers(word);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
