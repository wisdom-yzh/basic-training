#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> dict;
        ostringstream oss;

        for (auto &row: matrix) {
            oss.str("");
            for (int i = 0; i < row.size(); i++) {
                oss << (row[0] == row[i] ? '0' : '1');
            }
            dict[oss.str()]++;
        }

        int res = 0;
        for (auto &p: dict) {
            res = std::max(res, p.second);
        }

        return res;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{0,1},{1,1}},
        {{0,1},{1,0}},
        {{0,0,0},{0,0,1},{1,1,0}}
    };
    for (auto &testCase: testCases) {
        cout << Solution().maxEqualRowsAfterFlips(testCase) << endl;
    }
    return 0;
}
