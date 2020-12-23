#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> countRow(grid.size(), 0);
        vector<int> countCol(grid[0].size(), 0);

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                countRow[i] += grid[i][j];
                countCol[j] += grid[i][j];
            }
        }

        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if ((countRow[i] > 1 || countCol[j] > 1) && grid[i][j] == 1) {
                    res++;
                }
            }
        }
        return res;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{1,1,0,0},{0,0,1,0},{0,0,1,0},{0,0,0,1}},
        {{1,0},{1,1}},
        {{1,0},{0,1}}
    };
    for (auto &testCase: testCases) {
        cout << Solution().countServers(testCase) << endl;
    }
    return 0;
}
