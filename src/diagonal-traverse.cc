#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    enum Direction {
        UP_RIGHT, DOWN_LEFT
    };

    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (!matrix.size() || !matrix[0].size()) {
            return {};
        }
        const int ROW = matrix.size(), COL = matrix[0].size();
        int r = 0, c = 0;
        Direction direction = Direction::UP_RIGHT;


        if (ROW == 1) {
            result = matrix[0];
            return result;
        }

        if (COL == 1) {
            for (const auto &row: matrix) {
                result.push_back(row[0]);
            }
            return result;
        }

        result.push_back(matrix[r][c]);
        while (r != ROW - 1 || c != COL - 1) {
            if (direction == Direction::UP_RIGHT) {
                if (r == 0 || c == COL - 1) {
                    if (c == COL - 1) {
                        r++;
                    } else {
                        c++;
                    }
                    direction = Direction::DOWN_LEFT;
                } else {
                    r--;
                    c++;
                }
                result.push_back(matrix[r][c]);
            } else {
                if (r == ROW - 1 || c == 0) {
                    if (r == ROW - 1) {
                        c++;
                    } else {
                        r++;
                    }
                    direction = Direction::UP_RIGHT;
                } else {
                    r++;
                    c--;
                }
                result.push_back(matrix[r][c]);
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> matrix {
        {1,2,3},{4,5,6},{7,8,9}
    };
    auto result = Solution().findDiagonalOrder(matrix);
    for (const auto &item: result) {
        cout << item << endl;
    }
    return 0;
}
