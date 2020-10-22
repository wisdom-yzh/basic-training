#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rookX, rookY;
        bool foundRook = false;
        for (int y = 0; y < board.size() && !foundRook; y++) {
            for (int x = 0; x < board.size() && !foundRook; x++) {
                if (board[y][x] == 'R') {
                    rookY = y;
                    rookX = x;
                    foundRook = true;
                }
            }
        }

        int result = 0;
        for (int i = rookY + 1; i < board.size(); i++) {
            if (board[i][rookX] != '.') {
                if (board[i][rookX] == 'p') {
                    result++;
                }
                break;
            }
        }
        for (int i = rookY - 1; i >= 0; i--) {
            if (board[i][rookX] != '.') {
                if (board[i][rookX] == 'p') {
                    result++;
                }
                break;
            }
        }
        for (int i = rookX + 1; i < board.size(); i++) {
            if (board[rookY][i] != '.') {
                if (board[rookY][i] == 'p') {
                    result++;
                }
                break;
            }
        }
        for (int i = rookX - 1; i >= 0; i--) {
            if (board[rookY][i] != '.') {
                if (board[rookY][i] == 'p') {
                    result++;
                }
                break;
            }
        }

        return result;
    }
};

int main() {
    vector<vector<vector<char>>> testCases {
        {{'.','.','.','.','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'.','.','.','R','.','.','.','p'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'}},
        {{'.','.','.','.','.','.','.','.'},{'.','p','p','p','p','p','.','.'},{'.','p','p','B','p','p','.','.'},{'.','p','B','R','B','p','.','.'},{'.','p','p','B','p','p','.','.'},{'.','p','p','p','p','p','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'}},
        {{'.','.','.','.','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'p','p','.','R','.','p','B','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','B','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'.','.','.','.','.','.','.','.'}}
    };
    for (auto &testCase: testCases) {
        cout << Solution().numRookCaptures(testCase) << endl;
    }
    return 0;
}
