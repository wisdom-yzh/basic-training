#include <vector>
#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (!matrix.size() || !matrix[0].size()) {
            return matrix;
        }

        const int rows = matrix.size(), cols = matrix[0].size();
        const int MAX_INT = std::numeric_limits<int>::max();
        vector<vector<int>> mat(rows, vector<int>(cols, MAX_INT));
        int y, x;

        for (y = 0; y < rows; y++) {
            for (x = 0; x < cols; x++) {
                if (matrix[y][x] == 0) {
                    mat[y][x] = 0;
                } else {
                    if (y != 0 && mat[y - 1][x] != MAX_INT) {
                        mat[y][x] = std::min(mat[y][x], 1 + mat[y - 1][x]);
                    }
                    if (x != 0 && mat[y][x - 1] != MAX_INT) {
                        mat[y][x] = std::min(mat[y][x], 1 + mat[y][x - 1]);
                    }
                }
            }
        }

        for (y = rows - 1; y >= 0; y--) {
            for (x = cols - 1; x >= 0; x--) {
                if (matrix[y][x] == 0) {
                    mat[y][x] = 0;
                } else {
                    if (y != rows - 1 && mat[y + 1][x] != MAX_INT) {
                        mat[y][x] = std::min(mat[y][x], 1 + mat[y + 1][x]);
                    }
                    if (x != cols - 1 && mat[y][x + 1] != MAX_INT) {
                        mat[y][x] = std::min(mat[y][x], 1 + mat[y][x + 1]);
                    }
                }
            }
        }

        return mat;
    }
};

int main() {
    vector<vector<int>> matrix {
        {0,0,1,0,1,1,1,0,1,1},
        {1,1,1,1,0,1,1,1,1,1},
        {1,1,1,1,1,0,0,0,1,1},
        {1,0,1,0,1,1,1,0,1,1},
        {0,0,1,1,1,0,1,1,1,1},
        {1,0,1,1,1,1,1,1,1,1},
        {1,1,1,1,0,1,0,1,0,1},
        {0,1,0,0,0,1,0,0,1,1},
        {1,1,1,0,1,1,0,1,0,1},
        {1,0,1,1,1,0,1,1,1,0}
    };
    for (const auto &row: Solution().updateMatrix(matrix)) {
        for (const auto &p: row) {
            std::cout << p << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}
