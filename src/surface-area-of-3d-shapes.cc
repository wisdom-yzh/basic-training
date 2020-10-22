#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                res += grid[i][j] * 6;
                if (grid[i][j] > 1) {
                    res -= (grid[i][j] - 1) * 2;
                }
                if (i >= 0 && i - 1 >= 0) {
                    res -= std::min(grid[i][j], grid[i - 1][j]) * 2;
                }

                if (j >= 0 && j - 1 >= 0) {
                    res -= std::min(grid[i][j], grid[i][j - 1]) * 2;
                }
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
