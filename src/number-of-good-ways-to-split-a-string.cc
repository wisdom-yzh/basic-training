#include <string>
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    int numSplits(string s) {
        int res = 0;
        vector<int> l(26, 0), r(26, 0);
        int leftCount = 0, rightCount = 0;

        for (auto &ch: s) {
            auto idx = ch - 'a';
            if (r[idx] == 0) {
                rightCount++;
            }
            r[idx]++;
        }

        for (auto &ch: s) {
            auto idx = ch - 'a';
            r[idx]--;
            if (r[idx] == 0) {
                rightCount--;
            }
            if (l[idx] == 0) {
                leftCount++;
            }
            l[idx]++;
            if (leftCount == rightCount) {
                res++;
            }
            if (leftCount > rightCount) {
                break;
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

        int ret = Solution().numSplits(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
