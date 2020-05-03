#include <vector>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        if (ROWS == 0) {
            return true;
        }

        const int COLS = matrix[0].size();
        if (COLS == 0) {
            return true;
        }

        for (int i = ROWS - 1; i >= 0; i--) {
            int y = i, x = 0, elem = matrix[y][x];
            while (y < ROWS && x < COLS) {
                if (matrix[y][x] != elem) {
                    return false;
                }
                y++;
                x++;
            }
        }

        for (int i = 0; i < COLS; i++) {
            int y = 0, x = i, elem = matrix[y][x];
            while (y < ROWS && x < COLS) {
                if (matrix[y][x] != elem) {
                    return false;
                }
                y++;
                x++;
            }
        }

        return true;
    }
};

int main() {
    return 0;
}
