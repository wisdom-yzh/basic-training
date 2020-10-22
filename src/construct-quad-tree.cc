#include <vector>
using namespace std;

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
    bool allTrueOrFalse(vector<vector<int>>& grid, bool allTrueOrFalse) {
        for (vector<int> row: grid) {
            for (int col: row) {
                if (col != allTrueOrFalse)
                    return false;
            }
        }
        return true;
    }
    vector<vector<int>> quad(vector<vector<int>>& grid, int row, int col, int size) {
        vector<vector<int>> res;
        for (int count = 0; count < size; count ++) {
            vector<int> tmp = grid[row + count];
            if (size == 1) {
                res.push_back(vector<int>{tmp[col]});
            } else {
                res.push_back(
                vector<int>(tmp.begin() + col, tmp.begin() + col + size));
            }
        }
        return res;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        if (allTrueOrFalse(grid, true)) {
            return new Node(true, true, NULL, NULL, NULL, NULL);
        }
        if (allTrueOrFalse(grid, false)) {
            return new Node(false, true, NULL, NULL, NULL, NULL);
        }
        int half = grid.size() / 2;
        vector<vector<int>> topLeft = quad(grid, 0, 0, half);
        vector<vector<int>> topRight = quad(grid, 0, half, half);
        vector<vector<int>> bottomLeft = quad(grid, half, 0, half);
        vector<vector<int>> bottomRight = quad(grid, half, half, half);
        return new Node(0, false, 
                        construct(topLeft), construct(topRight), 
                        construct(bottomLeft), construct(bottomRight));
    }
};

int main() {
    return 0;
}
