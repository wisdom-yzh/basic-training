#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    bool checkNumberValid(string &s, int pos, int length) {
        if (length == 1) {
            return pos < (int)s.size() && s[pos] >= '0' && s[pos] <= '9';
        }
        if (length == 2) {
            return pos < (int)(s.size() - 1) &&
                s[pos] >= '1' && s[pos] <= '9' &&
                s[pos + 1] >= '0' && s[pos + 1] <= '9';
        }
        if (length == 3) {
            int number;
            return pos < (int)(s.size() - 2) &&
                (number = std::stoi(s.substr(pos, 3))) &&
                number >= 100 && number <= 255;
        }

        return false;
    }

    void recursionRestoreIpAddress(vector<string> &result, string &s, int pos, vector<string> &subResult) {
        if (pos == (int)s.size()) {
            if (subResult.size() == 4) {
                ostringstream ipAddr;
                auto iter = subResult.begin();
                for (; iter != subResult.end() - 1; iter++) {
                    ipAddr << *iter << ".";
                }
                ipAddr << *(subResult.end() - 1);
                result.push_back(ipAddr.str());
            }
            return;
        }
        if (subResult.size() == 4) {
            return;
        }

        for (int i = 1; i <= 3; i++) {
            if (this->checkNumberValid(s, pos, i)) {
                string subStr = s.substr(pos, i);
                subResult.push_back(subStr);
                this->recursionRestoreIpAddress(result, s, pos + i, subResult);
                subResult.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> subResult;
        this->recursionRestoreIpAddress(result, s, 0, subResult);
        return result;
    }
};

int main() {
    for (auto &s: Solution().restoreIpAddresses("25525511135")) {
        cout << s << endl;
    }
    for (auto &s: Solution().restoreIpAddresses("0000")) {
        cout << s << endl;
    }
    return 0;
}
