#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        if (S.empty()) {
            return vector<string>(0);
        }

        vector<string> result(1, "");
        for (const auto &ch: S) {
            if (ch >= '0' && ch <= '9') {
                for (auto &str: result) {
                    str.push_back(ch);
                }
            } else {
                vector<string> tmp;
                for (auto &str: result) {
                    string s = str;
                    s.push_back(std::tolower(ch));
                    tmp.push_back(s);

                    s = str;
                    s.push_back(std::toupper(ch));
                    tmp.push_back(s);
                }
                result = std::move(tmp);
            }
        }
        return result;
    }
};

int main() {
    for (auto &s: Solution().letterCasePermutation("a1B2")) {
        cout << s << endl;
    }
    return 0;
}
