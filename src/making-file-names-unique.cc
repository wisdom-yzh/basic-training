#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> res;
        std::map<string, int> dict;

        for (auto &name: names) {
            auto iter = dict.find(name);
            if (iter == dict.end()) {
                res.push_back(name);
                dict.insert({ name, 1 });
                continue;
            }

            while (true) {
                int count = iter->second;
                iter->second++;
                auto newName = name + "(" + to_string(count) + ")";

                if (dict.find(newName) == dict.end()) {
                    res.push_back(newName);
                    dict.insert({ newName, 1 });
                    break;
                }
            }
        }

        return res;
    }
};

int main() {
    vector<vector<string>> testCases {
        { "pes","fifa","gta","pes(2019)" },
        { "gta","gta(1)","gta","avalon" },
        { "onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece" },
        { "wano","wano","wano","wano" },
        { "kaido","kaido(1)","kaido","kaido(1)" }
    };
    for (auto &testCase: testCases) {
        for (auto &s: Solution().getFolderNames(testCase)) {
            cout << s << ' ';
        }
        cout << endl;
    }
    return 0;
}
