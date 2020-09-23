#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    static const vector<pair<int, int>> DIRECTIONS;

    int numEnclaves(vector<vector<int>>& A) {
        if (A.empty()) {
            return 0;
        }

        const int ROWS = A.size(), COLS = A[0].size();
        for (int r = 0; r < ROWS; r++) {
            if (A[r][0] == 1) {
                bfs(A, r, 0, ROWS, COLS);
            }
            if (A[r][COLS - 1] == 1) {
                bfs(A, r, COLS - 1, ROWS, COLS);
            }
        }
        for (int c = 0; c < COLS; c++ ) {
            if (A[0][c] == 1) {
                bfs(A, 0, c, ROWS, COLS);
            }
            if (A[ROWS - 1][c] == 1) {
                bfs(A, ROWS - 1, c, ROWS, COLS);
            }
        }

        int count = 0;
        for (const auto &rows: A) {
            for (const auto &p: rows) {
                if (p == 1) {
                    count++;
                }
            }
        }
        return count;
    }

    void bfs(vector<vector<int>> &A, int r, int c, const int ROWS, const int COLS) {
        A[r][c] = 0;
        std::queue<pair<int, int>> q;
        q.push({ r, c });

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            for (int i = 0; i < DIRECTIONS.size(); i++) {
                int rr = row + DIRECTIONS[i].first;
                int cc = col + DIRECTIONS[i].second;

                if (rr >= 0 && rr < ROWS && cc >= 0 && cc < COLS && A[rr][cc] == 1) {
                    A[rr][cc] = 0;
                    q.push({ rr, cc });
                }
            }

            q.pop();
        }
    }
};


const vector<pair<int, int>> Solution::DIRECTIONS {
    { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {
            {0,0,0,0},
            {1,0,1,0},
            {0,1,1,0},
            {0,0,0,0},
        },
        {
            {0,1,1,0},
            {0,0,1,0},
            {0,0,1,0},
            {0,0,0,0}
        }
    };
    for (auto &testCase: testCases) {
        cout << Solution().numEnclaves(testCase) << endl;
    }
    return 0;
}
