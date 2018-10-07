#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        static int pos[][2] = {
            { -1, -1 }, { -1, 0 }, { -1, 1 },
            { 0, -1 }, { 0, 1 },
            { 1, -1 }, { 1, 0 }, { 1, 1 }
        };
        const int ROW = board.size();
        const int COL = board[0].size();
        vector<vector<int>> next(ROW);
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                int count = 0;
                for (int k = 0; k < 8; k++) {
                    int dy = pos[k][0] + i;
                    int dx = pos[k][1] + j;
                    if (dy >= 0 && dy < ROW &&
                        dx >= 0 && dx < COL &&
                        board[dy][dx] == 1) {
                        count++;
                    }
                }
                if (count < 2 || count > 3) {
                    next[i].push_back(0);
                } else if (count == 2) {
                    next[i].push_back(board[i][j]);
                } else {
                    next[i].push_back(1);
                }
            }
        }
        board = next;
    }
};

int main() {
    vector<vector<int>> test {
        {0,1,0},
        {0,0,1},
        {1,1,1},
        {0,0,0}
    };
    Solution().gameOfLife(test);
    for (auto &row: test) {
        for (auto &p: row) {
            cout << p << ',';
        }
        cout << endl;
    }
    return 0;
}
