#include <vector>
#include <queue>
#include <iostream>
#include <tuple>
using namespace std;

class Solution {
public:
        int maxAreaOfIsland(vector<vector<int>>& grid) {
        const static int delta[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    std::queue<std::pair<int, int>> q;

                    q.push(make_pair(i, j));
                    grid[i][j] = 0;

                    while (!q.empty()) {
                        int r, c;
                        std::tie(r, c) = std::move(q.front());

                        for (int k = 0; k < 4; k++) {
                            auto dr = delta[k][0], dc = delta[k][1];
                            if (r + dr >= 0 && r + dr < grid.size() &&
                                c + dc >= 0 && c + dc < grid[0].size() &&
                                grid[r + dr][c + dc] == 1) {
                                q.push(make_pair(r + dr, c + dc));
                                grid[r + dr][c + dc] = 0;
                            }
                        }

                        q.pop();
                        area++;
                    }

                    maxArea = std::max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};

int main() {
    vector<vector<vector<int>>> cases = {
        {{0,0,1,0,0,0,0,1,0,0,0,0,0},
         {0,0,0,0,0,0,0,1,1,1,0,0,0},
         {0,1,1,0,1,0,0,0,0,0,0,0,0},
         {0,1,0,0,1,1,0,0,1,0,1,0,0},
         {0,1,0,0,1,1,0,0,1,1,1,0,0},
         {0,0,0,0,0,0,0,0,0,0,1,0,0},
         {0,0,0,0,0,0,0,1,1,1,0,0,0},
         {0,0,0,0,0,0,0,1,1,0,0,0,0}},
        {{0,0,0,0,0,0,0,0}}
    };
    for (auto &c: cases) {
        std::cout << Solution().maxAreaOfIsland(c) << std::endl;
    }
    return 0;
}
