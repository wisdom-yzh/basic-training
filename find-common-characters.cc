#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<std::map<char, int>> dicts;

        for (auto &str: A) {
            std::map<char, int> dict;
            for (auto &ch: str) {
                dict[ch]++;
            }
            dicts.push_back(dict);
        }

        for (int i = 1; i < dicts.size(); i++) {
            merge(dicts[i - 1], dicts[i]);
        }

        vector<string> result;
        for (const auto &p: dicts.back()) {
            for (int i = 0; i < p.second; i++) {
                result.push_back(std::string { p.first });
            }
        }
        return result;
    }

    void merge(std::map<char, int> &d1, std::map<char, int> &d2) {
        for (auto iter = d2.begin(); iter != d2.end(); ) {
            auto p = d1.find(iter->first);
            if (p == d1.end()) {
                iter = d2.erase(iter);
            } else {
                iter->second = std::min(iter->second, p->second);
                iter++;
            }
        }
    }
};

int main() {
    vector<vector<string>> testCases {
        { "bella","label","roller" },
        { "cool","lock","cook" }
    };

    for (auto &testCase: testCases) {
        for (auto &str: Solution().commonChars(testCase)) {
            cout << str << '\t';
        }
        cout << endl;
    }
    return 0;
}
