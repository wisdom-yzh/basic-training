#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> board(3, vector<char>(3, ' '));
        char cur = 'x';

        for (auto &p: moves) {
            board[p[0]][p[1]] = cur;
            cur = cur == 'x' ? 'o' : 'x';
        }

        if (check(board, 'x')) {
            return "A";
        }

        if (check(board, 'o')) {
            return "B";
        }

        return isFull(board) ? "Draw" : "Pending";
    }

    bool check(vector<vector<char>> &board, char ch) {
        return (
            (board[0][0] == ch && board[0][1] == ch && board[0][2] == ch) ||
            (board[1][0] == ch && board[1][1] == ch && board[1][2] == ch) ||
            (board[2][0] == ch && board[2][1] == ch && board[2][2] == ch) ||
            (board[0][0] == ch && board[1][1] == ch && board[2][2] == ch) ||
            (board[0][2] == ch && board[1][1] == ch && board[2][0] == ch) ||
            (board[0][0] == ch && board[1][0] == ch && board[2][0] == ch) ||
            (board[0][1] == ch && board[1][1] == ch && board[2][1] == ch) ||
            (board[0][2] == ch && board[1][2] == ch && board[2][2] == ch)
        );
    }

    bool isFull(vector<vector<char>> &board) {
        for (auto &row: board) {
            for (auto &x: row) {
                if (x == ' ') {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    return 0;
}
