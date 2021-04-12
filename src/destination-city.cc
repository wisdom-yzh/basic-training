#include <vector>
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, string> dict;

        for (auto &path: paths) {
            dict[path[0]] = path[1];
        }

        for (auto &path: paths) {
            if (dict.find(path[1]) == dict.end()) {
                return path[1];
            }
        }

        return "";
    }
};

int main() {
    vector<vector<vector<string>>> testCases {
        {{"London","New York"},{"New York","Lima"},{"Lima","Sao Paulo"}},
        {{"B","C"},{"D","B"},{"C","A"}},
        {{"A","Z"}},
    };
    for (auto &testCase: testCases) {
        cout << Solution().destCity(testCase) << endl;
    }
    return 0;
}
