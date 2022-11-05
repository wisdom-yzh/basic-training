#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
public:
  bool checkMove(vector<vector<char>> &board, int r, int c, char color) {
    int n = board.size(), m = board[0].size();
    board[r][c] = color;
    auto check_in = [&](int r, int c) {
      return r >= 0 && r < n && c >= 0 && c < m;
    };
    vector<pair<int, int>> vecs{{-1, 0}, {1, 0},   {0, 1},  {0, -1},
                                {1, 1},  {-1, -1}, {-1, 1}, {1, -1}};

    auto check = [&](pair<int, int> &vec) {
      int dx = vec.first, dy = vec.second;
      int tx = r + dx, ty = c + dy;
      if (!check_in(tx, ty) || board[tx][ty] == color || board[tx][ty] == '.') {
        return false;
      }
      while (check_in(tx, ty) && board[tx][ty] != '.' &&
             board[tx][ty] != color) {
        tx += dx;
        ty += dy;
      }
      return check_in(tx, ty) && board[tx][ty] == color;
    };

    for (auto &v : vecs) {
      if (check(v))
        return true;
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  vector<tuple<vector<vector<char>>, int, int, char>> testCases{
      {{{'.', '.', '.', 'B', '.', '.', '.', '.'},
        {'.', '.', '.', 'W', '.', '.', '.', '.'},
        {'.', '.', '.', 'W', '.', '.', '.', '.'},
        {'.', '.', '.', 'W', '.', '.', '.', '.'},
        {'W', 'B', 'B', '.', 'W', 'W', 'W', 'B'},
        {'.', '.', '.', 'B', '.', '.', '.', '.'},
        {'.', '.', '.', 'B', '.', '.', '.', '.'},
        {'.', '.', '.', 'W', '.', '.', '.', '.'}},
       4,
       3,
       'B'},
      {{{'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', 'B', '.', '.', 'W', '.', '.', '.'},
        {'.', '.', 'W', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'W', 'B', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', 'B', 'W', '.', '.'},
        {'.', '.', '.', '.', '.', '.', 'W', '.'},
        {'.', '.', '.', '.', '.', '.', '.', 'B'}},
       4,
       4,
       'W'}};
  for (auto [board, rMove, cMove, color] : testCases) {
    cout << boolalpha << Solution().checkMove(board, rMove, cMove, color)
         << endl;
  }
  return 0;
}
