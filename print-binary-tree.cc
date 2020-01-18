#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int rows = this->recursiveTreeHeight(root);
        if (rows == 0) {
            return vector<vector<string>>();
        }

        int cols = (2 << (rows - 1)) - 1;
        vector<vector<string>> result(rows, vector<string>(cols, ""));

        recursivePrintTree(root, result, 0, 0, cols - 1);
        return result;
    }

    void recursivePrintTree(TreeNode* root, vector<vector<string>> &arr, int row, int left, int right) {
        if (root == nullptr) {
            return;
        }

        int mid = (left + right) / 2;
        arr[row][mid] = std::to_string(root->val);
        recursivePrintTree(root->left, arr, row + 1, left, mid - 1);
        recursivePrintTree(root->right, arr, row + 1, mid + 1, right);
    }

    int recursiveTreeHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + std::max(this->recursiveTreeHeight(root->left), this->recursiveTreeHeight(root->right));
    }
};

int main() {
    return 0;
}
