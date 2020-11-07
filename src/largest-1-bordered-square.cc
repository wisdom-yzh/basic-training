#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        const int ROWS = grid.size(), COLS = grid[0].size();
        const int MAX_EDGE = std::min(ROWS, COLS);

        for (int n = MAX_EDGE; n >= 1; n--) {
            for (int i = 0; i <= ROWS - n; i++) {
                for (int j = 0; j <= COLS - n; j++) {
                    bool check = true;
                    for (int k = 0; k < n && check; k++) {
                        check &= grid[i][j + k] == 1 &&
                            grid[i + k][j] == 1 &&
                            grid[i + n - 1][j + n - 1 - k] == 1 &&
                            grid[i + n - 1 - k][j + n - 1] == 1;
                    }

                    if (check) {
                        return n * n;
                    }
                }
            }
        }

        return 0;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        { {1,1,1},{1,0,1},{1,1,1} },
        { {1,1,0,0} },
        { {0,0,0,1} }
    };
    for (auto &testCase: testCases) {
        cout << Solution().largest1BorderedSquare(testCase) << endl;
    }
    return 0;
}
