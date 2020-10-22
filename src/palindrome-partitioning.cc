#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(string &s) {
        int len = s.length();
        for (auto i = 0; i < len / 2; i++) {
            if (s[i] != s[len - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    void recursionPartition(vector<vector<string>> &result, vector<string> &subResult, string &s) {
        if (s.empty()) {
            if (!subResult.empty()) {
                result.push_back(subResult);
            }
            return;
        }
        for (size_t len = 1; len <= s.size(); len++) {
            string subStr = s.substr(0, len);
            if (this->isPalindrome(subStr)) {
                string nextStr = s.substr(len);
                subResult.push_back(subStr);
                this->recursionPartition(result, subResult, nextStr);
                subResult.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> subResult;
        this->recursionPartition(result, subResult, s);
        return result;
    }
};

int main() {
    auto result = Solution().partition("aab");
    for_each(result.begin(), result.end(), [](vector<string> &v) {
        for_each(v.begin(), v.end(), [](string &s) {
            cout << s << ',';
        });
        cout << endl;
    });
    return 0;
}
