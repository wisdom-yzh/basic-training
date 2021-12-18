#include <vector>
#include <tuple>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        const int rows = matrix.size(), cols = matrix[0].size();
        std::priority_queue<int> q;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (r == 0 && c != 0) {
                    matrix[r][c] = matrix[r][c - 1] ^ matrix[r][c];
                } else if (c == 0 && r != 0) {
                    matrix[r][c] = matrix[r - 1][c] ^ matrix[r][c];
                } else if (c != 0 && r != 0) {
                    matrix[r][c] = matrix[r][c] ^
                        matrix[r - 1][c] ^
                        matrix[r][c - 1] ^
                        matrix[r - 1][c - 1];
                }
                q.push(matrix[r][c]);
            }
        }

        for (int i = 0; i < k - 1; i++) {
            q.pop();
        }
        return q.top();
    }
};

int main() {
    vector<tuple<vector<vector<int>>, int>> testCases {
        { {{5,2},{1,6}}, 1 },
        { {{5,2},{1,6}}, 2 },
        { {{5,2},{1,6}}, 3 },
        { {{5,2},{1,6}}, 4 },
    };

    for (auto &[matrix, k]: testCases) {
        std::cout << Solution().kthLargestValue(matrix, k) << std::endl;
    }
    return 0;
}
