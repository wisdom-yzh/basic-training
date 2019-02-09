#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        const int ROW = board.size();
        const int COL = board[0].size();
        int result = 0;
        char lastUp, lastLeft;

        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (i > 0) {
                    lastUp = board[i - 1][j];
                } else {
                    lastUp = '.';
                }
                if (j > 0) {
                    lastLeft = board[i][j - 1];
                } else {
                    lastLeft = '.';
                }
                if (board[i][j] == 'X' && lastLeft == '.' && lastUp == '.') {
                    result++;
                }
            }
        }
        return result;
    }
};

int main() {
    vector<vector<char>> board {
        { 'X', '.', '.', 'X' },
        { '.', '.', '.', 'X' },
        { '.', '.', '.', 'X' }
    };
    cout << Solution().countBattleships(board) << endl;
    return 0;
}