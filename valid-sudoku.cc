#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isValidRow (vector<vector<char>>& board, int row) {
        bool table[9];
        std::fill(table, table + 9, false);
        for (int col = 0; col < 9; col++) {
            if (board[row][col] != '.') {
                if (table[board[row][col] - '1']) {
                    return false;
                }
                table[board[row][col] - '1'] = true;
            }
        }
        return true;
    }

    bool isValidCol (vector<vector<char>>& board, int col) {
        bool table[9];
        std::fill(table, table + 9, false);
        for (int row = 0; row < 9; row++) {
            if (board[row][col] != '.') {
                if (table[board[row][col] - '1']) {
                    return false;
                }
                table[board[row][col] - '1'] = true;
            }
        }
        return true;
    }

    bool isValidBlock (vector<vector<char>>& board, int i, int j) {
        bool table[9];
        std::fill(table, table + 9, false);
        for (int row = i * 3; row < (i + 1) * 3; row++) {
            for (int col = j * 3; col < (j + 1) * 3; col++) {
                if (board[row][col] != '.') {
                    if (table[board[row][col] - '1']) {
                        return false;
                    }
                    table[board[row][col] - '1'] = true;
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (!isValidRow(board, i) || !isValidCol(board, i)) {
                return false;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (!isValidBlock(board, i, j)) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> board1 {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    vector<vector<char>> board2 {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << boolalpha << Solution().isValidSudoku(board1) << endl;
    cout << boolalpha << Solution().isValidSudoku(board2) << endl;
    return 0;
}
