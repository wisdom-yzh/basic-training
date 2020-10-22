#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        if (!M.size() || !M[0].size()) {
            return M;
        }

        const int ROWS = M.size(), COLS = M[0].size();
        vector<vector<int>> R(ROWS, vector<int>(COLS, 0));
        for (int y = 0; y < ROWS; y++) {
            for (int x = 0; x < COLS; x++) {
                int s = 1, val = M[y][x];
                if (y != 0) {
                    val += M[y - 1][x];
                    s++;
                    if (x != 0) {
                        val += M[y - 1][x - 1];
                        s++;
                    }
                    if (x != COLS - 1) {
                        val += M[y - 1][x + 1];
                        s++;
                    }
                }
                if (y != ROWS - 1) {
                    val += M[y + 1][x];
                    s++;
                    if (x != 0) {
                        val += M[y + 1][x - 1];
                        s++;
                    }
                    if (x != COLS - 1) {
                        val += M[y + 1][x + 1];
                        s++;
                    }
                }
                if (x != 0) {
                    val += M[y][x - 1];
                    s++;
                }
                if (x != COLS - 1) {
                    val += M[y][x + 1];
                    s++;
                }

                R[y][x] = static_cast<int>(val / s);
            }
        }

        return R;
    }
};

int main() {
    vector<vector<int>> M {
        { 1,1,1 },
        { 1,0,1 },
        { 1,1,1 },
    };
    Solution().imageSmoother(M);
    return 0;
}
