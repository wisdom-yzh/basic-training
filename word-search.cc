#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<vector<char>> Board;
typedef vector<vector<bool>> Exist;

class Solution {
public:
    bool recursionExist(Board &board, Exist &exist, int row, int col, string &word, size_t pos) {
        if (pos == word.size()) {
            return true;
        }
        const int ROW = board.size();
        const int COL = board[0].size();
        if (row - 1 >= 0 &&
            board[row - 1][col] == word[pos] &&
            exist[row - 1][col]) {
            exist[row - 1][col] = false;
            if (this->recursionExist(board, exist, row - 1, col, word, pos + 1)) {
                return true;
            }
            exist[row - 1][col] = true;
        }
        if (row + 1 < ROW &&
            board[row + 1][col] == word[pos] &&
            exist[row + 1][col]) {
            exist[row + 1][col] = false;
            if (this->recursionExist(board, exist, row + 1, col, word, pos + 1)) {
                return true;
            }
            exist[row + 1][col] = true;
        }
        if (col + 1 < COL &&
            board[row][col + 1] == word[pos] &&
            exist[row][col + 1]) {
            exist[row][col + 1] = false;
            if (this->recursionExist(board, exist, row, col + 1, word, pos + 1)) {
                return true;
            }
            exist[row][col + 1] = true;
        }
        if (col - 1 >= 0 &&
            board[row][col - 1] == word[pos] &&
            exist[row][col - 1]) {
            exist[row][col - 1] = false;
            if (this->recursionExist(board, exist, row, col - 1, word, pos + 1)) {
                return true;
            }
            exist[row][col - 1] = true;
        }

        return false;
    }

    bool exist(Board& board, string word) {
        const int ROW = board.size();
        const int COL = board[0].size();

        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (board[i][j] == word[0]) {
                    Exist exist(ROW, vector<bool>(COL, true));
                    exist[i][j] = false;
                    if (this->recursionExist(board, exist, i, j, word, 1)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

int main() {
    vector<vector<char>> board {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    cout << boolalpha << Solution().exist(board, "ABCCED") << endl;
    cout << boolalpha << Solution().exist(board, "SEE") << endl;
    cout << boolalpha << Solution().exist(board, "ABCB") << endl;
    return 0;
}
