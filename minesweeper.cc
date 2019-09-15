#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (!board.size() || !board[0].size()) {
            return board;
        }
        vector<vector<char>> destBoard = board;
        dfsBoard(board, destBoard, click);
        return destBoard;
    }

    void dfsBoard(vector<vector<char>> &origin, vector<vector<char>> &dest, vector<int> &point) {
        const int y = point[0], x = point[1];
        const int rows = origin.size(), cols = origin[0].size();
        if (dest[y][x] != origin[y][x]) {
            return;
        }
        if (origin[y][x] == 'M') {
            dest[y][x] = 'X';
            return;
        }
        const vector<vector<int>> directions {
            { -1, -1 }, { 0, -1 }, { 1, -1 },
            { -1,  0 },            { 1,  0 },
            { -1,  1 }, { 0,  1 }, { 1,  1 }
        };
        vector<vector<int>> nextPoints;
        int minesNeighbour = 0;
        for (const auto &d: directions) {
            const int ny = y + d[1], nx = x + d[0];
            if (ny < 0 || ny >= rows || nx < 0 || nx >= cols) {
                continue;
            }
            if (origin[ny][nx] == 'M') {
                minesNeighbour++;
            } else {
                nextPoints.push_back(vector<int>{ ny, nx });
            }
        }

        if (minesNeighbour > 0) {
            dest[y][x] = minesNeighbour + '0';
        } else {
            dest[y][x] = 'B';
            for (auto &nextPoint: nextPoints) {
                dfsBoard(origin, dest, nextPoint);
            }
        }
    }
};

int main() {
    vector<vector<char>> board {
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'M', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'}
    };
    vector<int> click {3, 0};
    auto res = Solution().updateBoard(board, click);
    for (const auto &row: res) {
        for (const auto &point: row) {
            std::cout << point << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}
