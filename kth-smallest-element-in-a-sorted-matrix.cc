#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto cmp = [](tuple<int, int, int> &a, tuple<int, int, int> &b) {
            return std::get<0>(a) > std::get<0>(b);
        };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> q(cmp);
        const int ROW = matrix.size();
        const int COL = matrix[0].size();
        for (int i = 0; i < ROW; i++) {
            q.push(make_tuple(matrix[i][0], i, 0));
        }
        int result, row, col;
        for (int i = 0; i < k; i++) {
            result = std::get<0>(q.top());
            row = std::get<1>(q.top());
            col = std::get<2>(q.top());
            q.pop();
            if (col < COL - 1) {
                q.push(make_tuple(matrix[row][col + 1], row, col + 1));
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> matrix {
        { 1, 5, 9 },
        { 10, 11, 13 },
        { 12, 13, 15}
    };
    cout << Solution().kthSmallest(matrix, 8);
    vector<vector<int>> matrix2 {
        { 1, 2 },
        { 1, 3 }
    };
    cout << Solution().kthSmallest(matrix2, 4);
    return 0;
}
