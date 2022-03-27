#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        std::map<string, string> dict;
        for (auto &arr: knowledge) {
            dict[arr[0]] = arr[1];
        }

        string res {};
        string key {};
        bool matchMode = false;
        for (auto &ch: s) {
            if (matchMode) {
                if (ch == ')') {
                    matchMode = false;
                    auto iter = dict.find(key);
                    if (iter == dict.end()) {
                        res.push_back('?');
                    } else {
                        res += iter->second;
                    }
                    key.clear();
                } else {
                    key.push_back(ch);
                }
            } else {
                if (ch == '(') {
                    matchMode = true;
                } else {
                    res.push_back(ch);
                }
            }
        }
        return res;
    }
};

int main() {
    vector<pair<string, vector<vector<string>>>> testCases {
        { "(name)is(age)yearsold", {{"name","bob"},{"age","two"}} },
        { "hi(name)", {{"a","b"}} }, 
        { "(a)(a)(a)aaa", {{"a","yes"}} }
    };
    for (auto &[s, knowledge] : testCases) {
        cout << Solution().evaluate(s, knowledge) << endl;
    }
    return 0;
}
