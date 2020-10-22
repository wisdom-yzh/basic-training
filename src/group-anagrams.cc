#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<string, vector<string>> table;

        for (auto str: strs) {
            string key = str;
            std::sort(key.begin(), key.end());
            if (table.find(key) == table.end()) {
                table[key] = { str };
            } else {
                table[key].push_back(str);
            }
        }

        for (auto item: table) {
            result.push_back(item.second);
        }

        return result;
    }
};

int main () {
    vector<string> strs {
        "eat","tea","tan","ate","nat","bat"
    };

    for (auto row: Solution().groupAnagrams(strs)) {
        for (auto col: row) {
            cout << col << ',';
        }
        cout << endl;
    }

    return 0;
}
