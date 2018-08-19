#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    typedef vector<vector<char>> Board;

    void solve(Board& board) {
        const int ROW = board.size();
        if (ROW == 0) {
            return;
        }
        const int COL = board[0].size();
        if (COL == 0) {
            return;
        }
        Board visited(ROW, vector<char>(COL, 0));

        for (int y = 0; y < ROW; y++) {
            for (int x = 0; x < COL; x++) {
                if (visited[y][x]) {
                    continue;
                }
                visited[y][x] = 1;
                if (board[y][x] == 'X') {
                    continue;
                }

                vector<pair<int, int>> directions {
                    make_pair(-1, 0),
                    make_pair(1, 0),
                    make_pair(0, 1),
                    make_pair(0, -1)
                };
                vector<pair<int, int>> q;
                q.push_back(make_pair(y, x));
                size_t index = 0;
                bool isBorder = false;
                while (index < q.size()) {
                    auto pos = q[index++];
                    if (pos.first == 0 || pos.first == ROW - 1 ||
                        pos.second == 0 || pos.second == COL - 1) {
                        isBorder = true;
                    }

                    for (auto &d: directions) {
                        auto next = make_pair(
                            pos.first + d.first,
                            pos.second + d.second
                        );
                        if (next.first < 0 || next.first >= ROW ||
                            next.second < 0 || next.second >= COL ||
                            visited[next.first][next.second] ||
                            board[next.first][next.second] == 'X') {
                            continue;
                        }
                        q.push_back(next);
                        visited[next.first][next.second] = 1;
                    }
                }
                if (!isBorder) {
                    for (auto &pos: q) {
                        board[pos.first][pos.second] = 'X';
                    }
                }
            }
        }
    }
};

int main() {
    Solution::Board board {
        {'O','X','O','O','X','X'},
        {'O','X','X','X','O','X'},
        {'X','O','O','X','O','O'},
        {'X','O','X','X','X','X'},
        {'O','O','X','O','X','X'},
        {'X','X','O','O','O','O'}
    };
    Solution().solve(board);
    for_each(board.begin(), board.end(), [](vector<char> &iter) {
        for_each(iter.begin(), iter.end(), [](char & i) {
            cout << i << ',';
        });
        cout << endl;
    });
    return 0;
}

