#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <queue>
#include <set>
#include <tuple>
#include <utility>
#include <vector>

class Solution {
public:
  int nearestExit(std::vector<std::vector<char>> &maze,
                  std::vector<int> &entrance) {
    return floodFill(maze, entrance[0], entrance[1]);
  }

  int floodFill(std::vector<std::vector<char>> &maze, int r0, int c0) {
    const auto ROWS{maze.size()}, COLS{maze[0].size()};
    uint32_t res{std::numeric_limits<uint32_t>::max()};
    std::queue<std::tuple<int, int, uint32_t>> q;

    maze[r0][c0] = '+';
    q.emplace(r0, c0, 0);
    while (!q.empty()) {
      const auto [r, c, dist] = q.front();
      if ((r == 0 || r == ROWS - 1 || c == 0 || c == COLS - 1) &&
          (r != r0 || c != c0)) {
        res = std::min(res, dist);
      }
      if (r > 0 && maze[r - 1][c] == '.') {
        maze[r - 1][c] = '+';
        q.emplace(r - 1, c, dist + 1);
      }
      if (r < ROWS - 1 && maze[r + 1][c] == '.') {
        maze[r + 1][c] = '+';
        q.emplace(r + 1, c, dist + 1);
      }
      if (c > 0 && maze[r][c - 1] == '.') {
        maze[r][c - 1] = '+';
        q.emplace(r, c - 1, dist + 1);
      }
      if (c < COLS - 1 && maze[r][c + 1] == '.') {
        maze[r][c + 1] = '+';
        q.emplace(r, c + 1, dist + 1);
      }

      q.pop();
    }

    return static_cast<int32_t>(res);
  }
};

int main() {
  std::vector<std::pair<std::vector<std::vector<char>>, std::vector<int>>>
      testCases{
          {{{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}},
           {1, 2}},
          {{{'+', '+', '+'}, {'.', '.', '.'}, {'+', '+', '+'}}, {1, 0}},
          {{{'.', '+'}}, {0, 0}}};

  for (auto &[maze, entrance] : testCases) {
    std::cout << Solution().nearestExit(maze, entrance) << std::endl;
  }
  return 0;
}
