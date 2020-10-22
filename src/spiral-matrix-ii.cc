#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        if (n == 0) {
            return matrix;
        }

        int y = 0, x = 0, dy = 0, dx = 1;
        for (int i = 0; i < n * n; i++) {
            matrix[y][x] = i + 1;
            if (dy == 0 && (x + dx == n || x + dx == -1 ||
                matrix[y + dy][x + dx] != 0)) {
                dy = dx;
                dx = 0;
            } else if (dx == 0 && (y + dy == n || y + dy == -1 ||
                matrix[y + dy][x + dx] != 0)) {
                dx = -dy;
                dy = 0;
            }
            x += dx;
            y += dy;
        }

        return matrix;
    }
};

int main() {
    auto output = Solution().generateMatrix(5);
    for (auto row: output) {
        std::copy(row.begin(), row.end(), ostream_iterator<int>(cout, ","));
        cout << endl;
    }
    return 0;
}
