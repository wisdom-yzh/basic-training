#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        const int M = grid.size(), N = grid[0].size();
        const int SIZE = M * N;
        vector<vector<int>> res(M, vector<int>(N, 0));

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                int newIndex = ((i * N + j) + k) % SIZE;
                res[newIndex / N][newIndex % N] = grid[i][j];
            }
        }

        return res;
    }
};

int main() {
    vector<pair<vector<vector<int>>, int>> testCases {
        { {{1},{2},{3},{4},{7},{6},{5}}, 23 },
        { {{1,2,3},{4,5,6},{7,8,9}}, 1 },
        { {{3,8,1,9},{19,7,2,5},{4,6,11,10},{12,0,21,13}}, 4 },
        { {{1,2,3},{4,5,6},{7,8,9}}, 9 }
    };
    for (auto &testCase: testCases) {
        for (auto &row: Solution().shiftGrid(testCase.first, testCase.second)) {
            for (auto &x: row) {
                cout << x << '\t';
            }
            cout << endl;
        }
    }
    return 0;
}
