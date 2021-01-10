#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        const int ROWS = grid.size(), COLS = grid[0].size();

        int count = 0;
        for (int y = 0; y < ROWS; y++) {
            for (int x = 0; x < COLS; x++) {
                if (grid[y][x] < 0) {
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}},
        {{3,2},{1,0}},
        {{1,-1},{-1,-1}},
        {{-1}}
    };
    for (auto &testCase: testCases) {
        cout << Solution().countNegatives(testCase) << endl;
    }
    return 0;
}
