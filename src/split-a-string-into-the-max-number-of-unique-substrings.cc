#include <string>
#include <iostream>
#include <sstream>
#include <cassert>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxUniqueSplit(string s) {
        int res = 1;
        unordered_set<string> strSet;
        recursionSplit(s, 0, strSet, res);
        return res;
    }

    void recursionSplit(string &s, int begin, unordered_set<string> &strSet, int &maxVal) {
        if (begin == s.size()) {
            maxVal = std::max(maxVal, static_cast<int>(strSet.size()));
        }
        for (int i = begin; i < s.size(); i++) {
            auto subStr = s.substr(begin, i - begin + 1);
            if (strSet.find(subStr) != strSet.end()) {
                continue;
            }
            strSet.insert(subStr);
            recursionSplit(s, i + 1, strSet, maxVal);
            strSet.erase(subStr);
        }
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

        int ret = Solution().maxUniqueSplit(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
