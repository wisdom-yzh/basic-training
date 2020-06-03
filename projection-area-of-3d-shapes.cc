#include <vector>
using namespace std;

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int result = 0;

        for (int i = 0; i < grid.size(); i++) {
            int maxOfRows = 0, maxOfCols = 0;
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != 0) {
                    result++;
                }
                maxOfRows = std::max(maxOfRows, grid[i][j]);
                maxOfCols = std::max(maxOfCols, grid[j][i]);
            }
            result += (maxOfCols + maxOfRows);
        }

        return result;
    }
};

int main() {
    return 0;
}
